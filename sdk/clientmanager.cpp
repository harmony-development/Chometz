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

Client* ClientManager::operator->()
{
	return d->mainClient;
}

void ClientManager::beginAuthentication(const QString& homeserver)
{
	if (d->mainClient != nullptr) {
		d->mainClient = nullptr;
	}
	d->clients.clear();

	d->mainClient = new Client(this, homeserver);
	d->clients[homeserver] = QSharedPointer<Client>(d->mainClient);

	connect(d->mainClient, &Client::authEvent, this, &ClientManager::authEvent);
	d->mainClient->startAuth();
}

void ClientManager::continueAuthentication(const protocol::auth::v1::NextStepRequest& req)
{
	Q_ASSERT(d->mainClient);

	d->mainClient->nextStep(req);
}

};
