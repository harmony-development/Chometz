#pragma once

#include <QMutex>

#include "chometz_client.h"

namespace Chometz
{

struct Client::Private
{
	Private(Client* q) : q(q) { }

	Client* q = nullptr;
	QSqlDatabase db;
	QMutex databaseLock;

	Future<Result<QJsonObject>> get(QString key);
	Future<Result<ok>> set(QString key, QJsonObject obj);

	Future<Result<SRef<Object>>> dispatch(SRef<start> req);
};

};
