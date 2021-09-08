#pragma once

#include <QDebug>
#include <QNetworkReply>
#include <variant>

#include "future.h"

using namespace Croutons;

#define resultOk(t) resultOkImpl(t, __FILE__, __LINE__)

using Unit = std::monostate;
Q_DECLARE_METATYPE(Unit)

template <typename T>
[[nodiscard]] bool resultOkImpl(const T& t, const char* file, int line) {
	auto result = t.ok();
	if (!result) {
		qDebug() << "Result not OK at" << QStringLiteral("%1:%2").arg(file).arg(line) << t.error();
	}
	return result;
}

inline decltype(auto) transform(QNetworkReply* it) {
	auto future = Future<QNetworkReply*>();

	QObject::connect(it, &QNetworkReply::finished, it, [future, it]() {
		if (it->error() == QNetworkReply::NoError) {
			future.succeed(it);
		} else {
			future.fail(it);
		}
	});

	return future;
}

#define unwrap(t) (t.value())
