#include "clientmanager.h"
#include "client_p.h"
#include "util_p.h"

namespace SDK {

Client::Client(ClientManager* cm, const QString& homeserver) : QObject(cm), cm(cm), d(new Private)
{
	d->homeserver = homeserver;

	auto url = QUrl::fromUserInput(homeserver);
	auto host = url.host();
	auto port = QString::number(url.port(2289));
	auto scheme = url.scheme();
	if (scheme != "http" && scheme != "https") {
		scheme = "https";
	}

	d->chatKit = std::unique_ptr<ChatServiceServiceClient>(new ChatServiceServiceClient(host+":"+port, scheme == "https"));
	d->authKit = std::unique_ptr<AuthServiceServiceClient>(new AuthServiceServiceClient(host+":"+port, scheme == "https"));
	d->mediaProxyKit = std::unique_ptr<MediaProxyServiceServiceClient>(new MediaProxyServiceServiceClient(host+":"+port, scheme == "https"));
}

Client::~Client()
{

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

void Client::startEvents()
{
}

}
