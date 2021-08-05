#include "chometz_client_p.h"

namespace Chometz {

Client::Client(QSqlDatabase store, QObject* parent) : QObject(parent), d(new Private{this})
{
	d->db = store;
}

Client::Client(QString databaseName, QObject* parent) : QObject(parent), d(new Private{this})
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(databaseName);

	d->db = db;
}

Client::~Client()
{

}

Future<Result<SRef<Object>>>
Client::_request(SRef<Function> fn)
{
	if (fn->getID() == start::ID) {
		return d->dispatch(fn.staticCast<start>());
	} else {
		qFatal("unhandled function %d", fn->getID());

		Q_UNREACHABLE();
	}
}

}