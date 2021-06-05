#include <coroutine>

#include "clientmanager_p.h"

namespace SDK
{

Init init;

auto host(const QString& hs)
{
	auto it = QUrl::fromUserInput(hs);
	return it.host();
}

ClientManager::ClientManager(QObject* parent) : QObject(parent), d(new Private)
{
}

ClientManager::~ClientManager()
{

}

ChatServiceServiceClient* ClientManager::chatKit() { return d->mainClient->chatKit(); }
AuthServiceServiceClient* ClientManager::authKit() { return d->mainClient->authKit(); }
MediaProxyServiceServiceClient* ClientManager::mediaProxyKit() { return d->mainClient->mediaProxyKit(); }

void ClientManager::subscribeToGuild(const QString& homeserver, quint64 guildID)
{
	if (!d->clients.contains(host(homeserver))) {
		// TODO: federate automagically
		return;
	}
	if (!d->subs.guilds.contains(host(homeserver))) {
		d->subs.guilds[host(homeserver)] = {};
	}

	d->subs.guilds[host(homeserver)].append(guildID);

	d->clients[host(homeserver)]->subscribeToGuild(guildID);
}

void ClientManager::subscribeToActions()
{
	d->subs.actions = true;

	for (auto& client : d->clients) {
		client->subscribeToActions();
	}
}

void ClientManager::subscribeToHomeserver()
{
	d->subs.homeserver = true;

	d->mainClient->subscribeToHomeserver();
}

void ClientManager::connectClient(Client* client, const QString& homeserver)
{
	using namespace protocol::chat::v1;

	// connect(client, &Client::actionTriggered, this, [this, hs = homeserver](Event::ActionPerformed ev) {
	// 	Q_EMIT actionTriggered(hs, ev);
	// });
	// connect(client, &Client::chatEvent, this, [this, hs = homeserver](Event ev) {
	// 	Q_EMIT chatEvent(hs, ev);
	// });
}

Client* ClientManager::clientForHomeserver(const QString& homeserver)
{
	if (homeserver == "local" || homeserver.isEmpty()) {
		return d->mainClient;
	}

	if (!d->clients.contains(host(homeserver))) {
		auto client = new Client(this, homeserver);
		d->clients[host(homeserver)] = QSharedPointer<Client>(client, &QObject::deleteLater);
		d->mainClient->federateOtherClient(client, homeserver);
	}

	return d->clients[host(homeserver)].get();
}

void ClientManager::beginAuthentication(const QString& homeserver)
{
	if (d->mainClient != nullptr) {
		d->mainClient = nullptr;
	}
	d->clients.clear();

	d->mainClient = new Client(this, homeserver);
	d->clients[host(homeserver)] = QSharedPointer<Client>(d->mainClient, &QObject::deleteLater);

	connect(d->mainClient, &Client::authEvent, this, &ClientManager::authEvent);
	connect(d->mainClient, &Client::authEvent, this, [this, hs = homeserver](protocol::auth::v1::AuthStep step) {
		if (step.step_case() == protocol::auth::v1::AuthStep::kSession) {
			d->mainClient->setSession(step.session().session_token(), step.session().user_id());
			Q_EMIT ready(hs, step.session().user_id(), QString::fromStdString(step.session().session_token()));
		}
	});

	connect(d->mainClient, &Client::hsEvent, this, &ClientManager::hsEvent);
	connectClient(d->mainClient, homeserver);
	d->mainClient->startAuth();
}

void ClientManager::continueAuthentication(const protocol::auth::v1::NextStepRequest& req)
{
	Q_ASSERT(d->mainClient);

	d->mainClient->nextStep(req);
}

void ClientManager::checkLogin(::std::function<void(bool)> cb, const QString& token, const QString& homeserver, quint64 userID)
{
	if (d->mainClient != nullptr) {
		d->mainClient = nullptr;
	}
	d->clients.clear();

	d->mainClient = new Client(this, homeserver);
	d->mainClient->setSession(token.toStdString(), userID);
	d->clients[host(homeserver)] = QSharedPointer<Client>(d->mainClient, &QObject::deleteLater);

	connect(d->mainClient, &Client::authEvent, this, &ClientManager::authEvent);
	connect(d->mainClient, &Client::hsEvent, this, &ClientManager::hsEvent);
	connectClient(d->mainClient, homeserver);

	auto r = co_await d->mainClient->authKit()->CheckLoggedIn(google::protobuf::Empty{});
	auto ok = std::holds_alternative<google::protobuf::Empty>(r);
	if (ok) {
		Q_EMIT ready(homeserver, userID, token);
	}
	cb(ok);
}

};
