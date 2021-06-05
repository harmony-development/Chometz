#include "clientmanager.h"
#include "client_p.h"
#include "util.h"

namespace SDK {

Client::Client(ClientManager* cm, const QString& homeserver) : QObject(cm), cm(cm), d(new Private)
{
	d->homeserver = homeserver;

	auto url = QUrl::fromUserInput(homeserver);
	auto host = url.host();
	auto port = QString::number(url.port(2289));
	auto scheme = url.scheme();

	const auto isHTTP = scheme == "http" and homeserver.startsWith("http://");
	const auto isHTTPS = scheme == "https";

	if (not (isHTTP or isHTTPS)) {
		scheme = "https";
	}

	d->chatKit = std::unique_ptr<ChatServiceServiceClient>(new ChatServiceServiceClient(host+":"+port, scheme == "https"));
	d->authKit = std::unique_ptr<AuthServiceServiceClient>(new AuthServiceServiceClient(host+":"+port, scheme == "https"));
	d->mediaProxyKit = std::unique_ptr<MediaProxyServiceServiceClient>(new MediaProxyServiceServiceClient(host+":"+port, scheme == "https"));
}

Client::~Client()
{

}

void Client::setSession(const std::string& session, quint64 userID)
{
	d->session = session;
	d->userID = userID;

	auto tok = QString::fromStdString(session);

	d->chatKit->universalHeaders = {{"Authorization", tok}};

	d->authKit->universalHeaders = {{"Authorization", tok}};
	d->mediaProxyKit->universalHeaders = {{"Authorization", tok}};
}

void Client::nextStep(const protocol::auth::v1::NextStepRequest& nstep)
{
	auto it = nstep;
	it.set_auth_id(d->authID);

	d->authKit->NextStep([this](auto resp){
		if (!resultOk(resp)) {
			return;
		}
		auto value = unwrap(resp);
		// Q_EMIT authEvent(value);
	}, it);
}

void Client::startAuth()
{
	d->authKit->BeginAuth([this](auto resp) {
		if (!resultOk(resp)) {
			return;
		}
		auto value = unwrap(resp);

		protocol::auth::v1::StreamStepsRequest streamReq;
		streamReq.set_auth_id(value.auth_id());

		auto stepStream = d->authKit->StreamSteps(streamReq);
		connect(stepStream, &Receive__protocol_auth_v1_AuthStep__Stream::receivedMessage, this, &Client::authEvent);
		connect(stepStream, &QWebSocket::disconnected, [=] {
			stepStream->deleteLater();
		});

		protocol::auth::v1::NextStepRequest req2;
		req2.set_auth_id(value.auth_id());

		d->authID = value.auth_id();
		d->authKit->NextStep([this](auto resp) {
			if (!resultOk(resp)) {
				return;
			}
			auto value = unwrap(resp);

			Q_EMIT authEvent(value);
		}, req2);
	}, google::protobuf::Empty{});
}

QString Client::homeserver() const
{
	return d->homeserver;
}

void Client::startEvents()
{
	d->eventStream = QSharedPointer<Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream>(d->chatKit->StreamEvents(), &QObject::deleteLater);

	connect(
		d->eventStream.get(),
		&QWebSocket::connected,
		this,
		[=] {
			Q_EMIT eventLoopStarted();
		}
	);
	connect(
		d->eventStream.get(),
		&QWebSocket::disconnected,
		this,
		[=] {
			Q_EMIT eventLoopEnded();
		}
	);
	connect(
		d->eventStream.get(),
		&Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream::receivedMessage,
		this,
		[=](const protocol::chat::v1::Event& msg) {
			using namespace protocol::chat::v1;

			if (msg.has_action_performed()) {
				Q_EMIT actionTriggered(msg.action_performed());
			} else if (msg.has_guild_added_to_list() || msg.has_guild_removed_from_list()) {
				Q_EMIT hsEvent(msg);
			} else {
				Q_EMIT chatEvent(msg);
			}
		}
	);
}

void Client::subscribeToActions()
{
	if (d->eventStream == nullptr) {
		startEvents();
	}

	auto make = [this]() {
		auto req = protocol::chat::v1::StreamEventsRequest {};
		req.set_allocated_subscribe_to_homeserver_events(new protocol::chat::v1::StreamEventsRequest::SubscribeToHomeserverEvents);

		auto ok = d->eventStream->send(req);
		Q_UNUSED(ok);
	};

	if (d->eventStream->state() != QAbstractSocket::ConnectedState) {
		connect(d->eventStream.get(), &QWebSocket::connected, this, make);
		return;
	}

	make();
}

void Client::subscribeToHomeserver()
{
	if (d->eventStream == nullptr) {
		startEvents();
	}

	auto make = [this]() {
		auto req = protocol::chat::v1::StreamEventsRequest {};
		req.set_allocated_subscribe_to_actions(new protocol::chat::v1::StreamEventsRequest::SubscribeToActions);

		auto ok = d->eventStream->send(req);
		Q_UNUSED(ok);
	};

	if (d->eventStream->state() != QAbstractSocket::ConnectedState) {
		connect(d->eventStream.get(), &QWebSocket::connected, this, make);
		return;
	}
}

void Client::subscribeToGuild(quint64 guildID)
{
	if (d->eventStream == nullptr) {
		startEvents();
	}

	auto make = [this, guildID]() {
		auto req = protocol::chat::v1::StreamEventsRequest {};
		req.set_allocated_subscribe_to_guild(new protocol::chat::v1::StreamEventsRequest::SubscribeToGuild);
		req.mutable_subscribe_to_guild()->set_guild_id(guildID);

		auto ok = d->eventStream->send(req);
		Q_UNUSED(ok)
	};

	if (d->eventStream->state() != QAbstractSocket::ConnectedState) {
		connect(d->eventStream.get(), &QWebSocket::connected, this, make);
		return;
	}

	make();
}

ChatServiceServiceClient* Client::chatKit()
{
	return d->chatKit.get();
}

void Client::federateOtherClient(Client* client, const QString& target)
{
	auto req = protocol::auth::v1::FederateRequest{};
	req.set_target(target.toStdString());

	auto result = d->authKit->FederateSync(req);
	if (!resultOk(result)) {
		return;
	}

	auto req2 = protocol::auth::v1::LoginFederatedRequest {};
	req2.set_auth_token(unwrap(result).token());
	req2.set_domain(d->homeserver.toStdString());

	auto result2 = client->d->authKit->LoginFederatedSync(req2);
	if (!resultOk(result2)) {
		return;
	}
	auto resp = unwrap(result2);

	client->d->session = resp.session_token();
	client->d->userID = resp.user_id();
}

AuthServiceServiceClient* Client::authKit()
{
	return d->authKit.get();
}

MediaProxyServiceServiceClient* Client::mediaProxyKit()
{
	return d->mediaProxyKit.get();
}


}
