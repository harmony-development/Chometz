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

Client* ClientManager::mainClient() const { return d->mainClient; }

void ClientManager::subscribeToGuild(const QString& homeserver, quint64 guildID)
{
	qWarning() << "subscribing to" << homeserver << guildID;
	clientForHomeserver(homeserver).then([guildID](Client* c) {
		qWarning() << "== subscribing to" << guildID;
		c->subscribeToGuild(guildID);
	});
}

void ClientManager::subscribeToActions()
{
	d->subs.actions = true;

	for (auto& client : d->clients) {
		client.then([=](Client* c) {
			c->subscribeToActions();
		});
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

	connect(client, &Client::actionTriggered, this, [this, hs = homeserver](StreamEvent::ActionPerformed ev) {
		Q_EMIT actionTriggered(hs, ev);
	});
	connect(client, &Client::chatEvent, this, [this, hs = homeserver](StreamEvent ev) {
		Q_EMIT chatEvent(hs, ev);
	});
}

Future<Client*> ClientManager::clientForHomeserver(QString homeserver)
{
	if (homeserver == "local" || homeserver.isEmpty()) {
		Future<Client*> it;
		it.succeed(d->mainClient);
		return it;
	}

	if (!d->clients.contains(host(homeserver))) {
		auto client = new Client(this, homeserver);
		d->clients[host(homeserver)] = d->mainClient->federateOtherClient(client, homeserver);
	}

	return d->clients[host(homeserver)];
}

void ClientManager::beginAuthentication(const QString& homeserver)
{
	if (d->mainClient != nullptr) {
		d->mainClient = nullptr;
	}
	d->clients.clear();

	d->mainClient = new Client(this, homeserver);
	Future<Client*> it;
	it.succeed(d->mainClient);
	d->clients[host(homeserver)] = it;

	connect(d->mainClient, &Client::authEvent, this, &ClientManager::authEvent);
	connect(d->mainClient, &Client::authEvent, this, [this, hs = homeserver](protocol::auth::v1::AuthStep step) {
		if (step.step_case() == protocol::auth::v1::AuthStep::kSession) {
			d->mainClient->setSession(step.session().session_token(), step.session().user_id());
			qWarning() << "emitting ready";
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

Future<bool> ClientManager::checkLogin(QString token, QString homeserver, quint64 userID)
{
	if (d->mainClient != nullptr) {
		d->mainClient = nullptr;
	}
	d->clients.clear();

	d->mainClient = new Client(this, homeserver);
	d->mainClient->setSession(token.toStdString(), userID);
	Future<Client*> it;
	it.succeed(d->mainClient);
	d->clients[host(homeserver)] = it;

	connect(d->mainClient, &Client::authEvent, this, &ClientManager::authEvent);
	connect(d->mainClient, &Client::hsEvent, this, &ClientManager::hsEvent);
	connectClient(d->mainClient, homeserver);

	auto ret = co_await d->mainClient->CheckLoggedIn(protocol::auth::v1::CheckLoggedInRequest{});
	if (ret.ok()) {
		Q_EMIT ready(homeserver, userID, token);
	}

	co_return ret.ok();
}

};
