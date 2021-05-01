#pragma once

#include <QMap>
#include <QSharedPointer>

#include "client.h"
#include "clientmanager.h"

#include "init_p.h"

namespace SDK
{

enum class State
{
	Null, // the main client is nullptr
	Unauthenticated, // the main client exists, but is not authenticated
	Authenticated, // the main client exists and is authenticated
};

struct ClientManager::Private
{
	Client* mainClient;
	QMap<QString,QSharedPointer<Client>> clients;
};

};
