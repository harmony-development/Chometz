#include "clientmanager_p.h"

namespace SDK
{

Init init;

ClientManager::ClientManager(QObject* parent) : QObject(parent), d(new Private)
{
}

ClientManager::~ClientManager()
{

}

ChatServiceServiceClient* ClientManager::chatKit() { return d->mainClient->chatKit(); }
AuthServiceServiceClient* ClientManager::authKit() { return d->mainClient->authKit(); }
MediaProxyServiceServiceClient* ClientManager::mediaProxyKit() { return d->mainClient->mediaProxyKit(); }

void ClientManager::beginAuthentication(const QString& homeserver)
{
	if (d->mainClient != nullptr) {
		d->mainClient = nullptr;
	}
	d->clients.clear();

	d->mainClient = new Client(this, homeserver);
	d->clients[homeserver] = QSharedPointer<Client>(d->mainClient);

	connect(d->mainClient, &Client::authEvent, this, &ClientManager::authEvent);
	connect(d->mainClient, &Client::authEvent, this, [this](protocol::auth::v1::AuthStep step) {
		if (step.step_case() == protocol::auth::v1::AuthStep::kSession) {
			d->mainClient->setSession(step.session().session_token(), step.session().user_id());
		}
	});
	d->mainClient->startAuth();
}

void ClientManager::continueAuthentication(const protocol::auth::v1::NextStepRequest& req)
{
	Q_ASSERT(d->mainClient);

	d->mainClient->nextStep(req);
}

};
