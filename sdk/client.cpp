#include <QTimer>
#include <QRandomGenerator>

#include "auth/v1/auth.pb.h"
#include "chat/v1/chat.hrpc.client.h"
#include "client.h"
#include "clientmanager.h"
#include "client_p.h"
#include "util.h"

namespace SDK {

static inline QString _host(const QString& homeserver)
{
	auto url = QUrl::fromUserInput(homeserver);
	auto host = url.host();
	auto port = QString::number(url.port(2289));
	auto scheme = url.scheme();

	const auto isHTTP = scheme == "http" and homeserver.startsWith("http://");
	const auto isHTTPS = scheme == "https";

	if (not (isHTTP or isHTTPS)) {
		scheme = "https";
	}

	return host + ":" + port;
}

static inline bool _secure(const QString& homeserver)
{
	auto url = QUrl::fromUserInput(homeserver);
	auto host = url.host();
	auto port = QString::number(url.port(2289));
	auto scheme = url.scheme();

	const auto isHTTP = scheme == "http" and homeserver.startsWith("http://");
	const auto isHTTPS = scheme == "https";

	if (not (isHTTP or isHTTPS)) {
		scheme = "https";
	}

	return scheme == "https";
}

Client::Client(ClientManager* cm, const QString& homeserver) : QObject(cm), RequestClient(_host(homeserver), _secure(homeserver)), cm(cm), d(new Private)
{
	d->homeserver = homeserver;
}

Client::~Client()
{

}

void Client::setSession(const std::string& session, quint64 userID)
{
	d->session = session;
	d->userID = userID;

	auto tok = QString::fromStdString(session);

	ChatServiceServiceClient::universalHeaders = {{"Authorization", tok}};
	AuthServiceServiceClient::universalHeaders = {{"Authorization", tok}};
	MediaProxyServiceServiceClient::universalHeaders = {{"Authorization", tok}};
	EmoteServiceServiceClient::universalHeaders = {{"Authorization", tok}};
	ProfileServiceServiceClient::universalHeaders = {{"Authorization", tok}};
	VoiceServiceServiceClient::universalHeaders = {{"Authorization", tok}};
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

	return NextStep(it).toFutureT().map([](auto) { return Unit{}; });
}

Future<Unit> Client::startAuth()
{
	return BeginAuth(protocol::auth::v1::BeginAuthRequest{})
	.toFutureT()
	.flatMap([this](auto value) {
		protocol::auth::v1::StreamStepsRequest streamReq;
		streamReq.set_auth_id(value.auth_id());

		auto stepStream = StreamSteps(streamReq);
		connect(stepStream, &Receive__protocol_auth_v1_StreamStepsResponse__Stream::receivedMessage, this, [this](protocol::auth::v1::StreamStepsResponse r) {
			Q_EMIT authEvent(r.step());
		});
		connect(stepStream, &QWebSocket::disconnected, [=] {
			stepStream->deleteLater();
		});

		d->authID = value.auth_id();

		protocol::auth::v1::NextStepRequest req2;
		req2.set_auth_id(value.auth_id());

		return NextStep(req2).toFutureT();
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
	d->eventStream = QSharedPointer<Receive__protocol_chat_v1_StreamEventsResponse__Send__protocol_chat_v1_StreamEventsRequest__Stream>(StreamEvents(), &QObject::deleteLater);

	connect(
		d->eventStream.get(),
		&QWebSocket::stateChanged,
		this,
		[=](QAbstractSocket::SocketState socketState) {
			ConnectionState state;
			switch (socketState) {
			case QAbstractSocket::UnconnectedState:
				state = ConnectionState::Offline;
				break;
			case QAbstractSocket::HostLookupState:
				state = ConnectionState::ResolvingHost;
				break;
			case QAbstractSocket::ConnectingState:
				state = ConnectionState::Connecting;
				break;
			case QAbstractSocket::ConnectedState:
				state = ConnectionState::Connected;
				break;
			case QAbstractSocket::ClosingState:
				state = ConnectionState::Disconnecting;
				break;
			default:
				return;
			}
			d->state = state;
			Q_EMIT connectionStateChanged(state);
		}
	);
	connect(
		d->eventStream.get(),
		&QWebSocket::disconnected,
		this,
		[=]() {
			const auto duration = d->wsDelay + QRandomGenerator::system()->bounded(0, 300);
			auto when = QDateTime::currentDateTime().addMSecs(duration);
			QTimer::singleShot(duration, [=] {
				d->eventStream->open(d->eventStream->request());
			});
			d->state = ConnectionState::WaitingToReconnect;
			d->when = when;
			Q_EMIT connectionStateChanged(d->state);
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

Client::ConnectionState Client::connectionState() const
{
	return d->state;
}

QDateTime Client::reconnectingIn() const
{
	return d->when;
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

Future<Client*> Client::federateOtherClient(Client* client, QString target)
{
	auto req = protocol::auth::v1::FederateRequest{};
	req.set_server_id(target.toStdString());

	return Federate(req).toFutureT()
	.flatMap([this, client](auto result) {
		auto req = protocol::auth::v1::LoginFederatedRequest {};
		req.set_allocated_auth_token(result.release_token());
		req.set_server_id(d->homeserver.toStdString());

		return client->LoginFederated(req).toFutureT();
	})
	.map([client](protocol::auth::v1::LoginFederatedResponse result) {
		client->setSession(result.session().session_token(), result.session().user_id());

		return client;
	});
}

}
