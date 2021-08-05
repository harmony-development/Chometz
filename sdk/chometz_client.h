#pragma once

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "requests.h"

#include "future.h"
#include "result.h"

namespace Chometz
{

class Client final : public QObject
{

	Q_OBJECT

	priv struct Private;
	priv QScopedPointer<Private> d;

	priv Future<Result<SRef<Object>>> _request(SRef<Function> fn);

	pub explicit Client(QString databaseName, QObject* parent = nullptr);
	pub explicit Client(QSqlDatabase store, QObject* parent = nullptr);
	pub ~Client();

	pub Q_SIGNAL void update(SRef<Update> update);

	pub template<typename T>
	Future<Result<typename T::SResultType>> request(SRef<T> fn)
	{
		Future<Result<SRef<Object>>> req = _request(fn);
		Future<Result<typename T::SResultType>> newReq = req.then<Result<typename T::SResultType>>([](Result<SRef<Object>> it) -> Result<typename T::SResultType> {
			if (it.ok()) {
				return Result<typename T::SResultType>(it.value().staticCast<typename T::ResultType>());
			} else {
				return Result<typename T::SResultType>(it.err());
			}
		});
		return newReq;
	}

};

};
