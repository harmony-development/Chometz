#include "auth/v1/auth.pb.h"
#include "chat/v1/chat.hrpc.client.h"
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
	d->emoteKit = std::unique_ptr<EmoteServiceServiceClient>(new EmoteServiceServiceClient(host+":"+port, scheme == "https"));
	d->profileKit = std::unique_ptr<ProfileServiceServiceClient>(new ProfileServiceServiceClient(host+":"+port, scheme == "https"));
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
	d->emoteKit->universalHeaders = {{"Authorization", tok}};
	d->profileKit->universalHeaders = {{"Authorization", tok}};
}

std::string Client::session() const
{
	return d->session;
}

quint64 Client::userID() const
{
	return d->userID;
}

Future<Unit> Client::nextStep(protocol::auth::v1::NextStepRequest nstep)
{
	auto it = nstep;
	it.set_auth_id(d->authID);

	return d->authKit->NextStep(it).toFutureT().map([](auto) { return Unit{}; });
}

Future<Unit> Client::startAuth()
{
	return d->authKit->BeginAuth(protocol::auth::v1::BeginAuthRequest{})
	.toFutureT()
	.flatMap([this](auto value) {
		protocol::auth::v1::StreamStepsRequest streamReq;
		streamReq.set_auth_id(value.auth_id());

		auto stepStream = d->authKit->StreamSteps(streamReq);
		connect(stepStream, &Receive__protocol_auth_v1_StreamStepsResponse__Stream::receivedMessage, this, [this](protocol::auth::v1::StreamStepsResponse r) {
			Q_EMIT authEvent(r.step());
		});
		connect(stepStream, &QWebSocket::disconnected, [=] {
			stepStream->deleteLater();
		});

		d->authID = value.auth_id();

		protocol::auth::v1::NextStepRequest req2;
		req2.set_auth_id(value.auth_id());

		return d->authKit->NextStep(req2).toFutureT();
	})
	.map([this](protocol::auth::v1::NextStepResponse value) {
		Q_EMIT authEvent(value.step());

		return Unit{};
	});
}

QString Client::homeserver() const
{
	return d->homeserver;
}

void Client::startEvents()
{
	d->eventStream = QSharedPointer<Receive__protocol_chat_v1_StreamEventsResponse__Send__protocol_chat_v1_StreamEventsRequest__Stream>(d->chatKit->StreamEvents(), &QObject::deleteLater);

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
		&Receive__protocol_chat_v1_StreamEventsResponse__Send__protocol_chat_v1_StreamEventsRequest__Stream::receivedMessage,
		this,
		[=](const protocol::chat::v1::StreamEventsResponse& r) {
			using namespace protocol::chat::v1;

			if (r.has_chat()) {
				auto msg = r.chat();
				if (msg.has_action_performed()) {
					Q_EMIT actionTriggered(msg.action_performed());
				} else if (msg.has_guild_added_to_list() || msg.has_guild_removed_from_list()) {
					Q_EMIT hsEvent(msg);
				} else {
					Q_EMIT chatEvent(msg);
				}
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

Future<Client*> Client::federateOtherClient(Client* client, QString target)
{
	auto req = protocol::auth::v1::FederateRequest{};
	req.set_target(target.toStdString());

	return d->authKit->Federate(req).toFutureT()
	.flatMap([this, client](auto result) {
		auto req = protocol::auth::v1::LoginFederatedRequest {};
		req.set_allocated_auth_token(result.release_token());
		req.set_domain(d->homeserver.toStdString());

		return client->d->authKit->LoginFederated(req).toFutureT();
	})
	.map([client](protocol::auth::v1::LoginFederatedResponse result) {
		client->setSession(result.session().session_token(), result.session().user_id());

		return client;
	});
}

AuthServiceServiceClient* Client::authKit()
{
	return d->authKit.get();
}

MediaProxyServiceServiceClient* Client::mediaProxyKit()
{
	return d->mediaProxyKit.get();
}

EmoteServiceServiceClient* Client::emoteKit()
{
	return d->emoteKit.get();
}

ProfileServiceServiceClient* Client::profileKit()
{
	return d->profileKit.get();
}


}
