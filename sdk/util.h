#pragma once

#include <QDebug>
#include <variant>

#define resultOk(t) resultOkImpl(t, __FILE__, __LINE__)

template <typename T>
[[nodiscard]] bool resultOkImpl(const T& t, const char* file, int line) {
	auto result = t.ok();
	if (!result) {
		qDebug() << "Result not OK at" << QStringLiteral("%1:%2").arg(file).arg(line) << t.error();
	}
	return result;
}

#define unwrap(t) (t.value())
