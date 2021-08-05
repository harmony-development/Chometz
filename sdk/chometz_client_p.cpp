#include <QSqlError>
#include <QJsonObject>
#include <QtConcurrent>

#include "chometz_client_p.h"
#include "errors.h"

namespace Chometz
{

using RObj = Result<SRef<Object>>;

template<typename T>
using R = Result<SRef<T>>;

Future<RObj>
Client::Private::dispatch(SRef<start> req)
{
	Q_UNUSED(req)

	// initialise the database...

	Future<RObj> ret;
	if (!db.open()) {
		ret.settle(RObj(error(Errors::DatabaseInitFailure, db.lastError().text())));
		return ret;
	}

	// now let's run some queries

	QSqlQuery query(db);

	// create our key/value table if it doesn't exist

	if (!query.exec("CREATE TABLE IF NOT EXISTS data( key TEXT PRIMARY KEY, data BLOB NOT NULL );")) {
		ret.settle(RObj(error(Errors::DatabaseInitFailure, query.lastError().text())));
	}

	return ret;
}

Future<Result<QJsonObject>> Client::Private::get(QString key)
{
	Future<Result<QJsonObject>> ret;

	QtConcurrent::run([ret, key, this]() {
		databaseLock.lock();

		QSqlQuery query("", db);
		if (!query.prepare("SELECT data FROM data WHERE key = :key;")) {
			ret.settle(Result<QJsonObject>(error(Errors::DatabaseQueryFailure, query.lastError().text())));
			return;
		}
		query.bindValue(":key", key);
		if (!query.exec()) {
			ret.settle(Result<QJsonObject>(error(Errors::DatabaseQueryFailure, query.lastError().text())));
			return;
		}
		if (!query.next()) {
			ret.settle(Result<QJsonObject>(QJsonObject()));
			return;
		}

		auto a = QJsonDocument::fromJson(query.value("data").toByteArray()).object();
		ret.settle(Result<QJsonObject>(a));

		databaseLock.unlock();
	});

	return ret;
}

Future<Result<ok>> Client::Private::set(QString key, QJsonObject obj)
{
	Future<Result<ok>> ret;

	QtConcurrent::run([ret, key, obj, this]() {
		databaseLock.lock();

		QSqlQuery query("", db);
		if (!query.prepare("REPLACE INTO data (key, data) VALUES (:key, :data);")) {
			ret.settle(Result<ok>(error(Errors::DatabaseQueryFailure, query.lastError().text())));
			return;
		}
		query.bindValue(":key", key);
		query.bindValue(":data", QJsonDocument(obj).toJson());

		if (!query.exec()) {
			ret.settle(Result<ok>(error(Errors::DatabaseQueryFailure, query.lastError().text())));
			return;
		}

		ret.settle(Result<ok>(ok()));

		databaseLock.unlock();
	});

	return ret;
}

};
