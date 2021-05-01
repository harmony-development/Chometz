#pragma once

#include <QDebug>
#include <variant>

#define resultOk(t) resultOkImpl(t, __FILE__, __LINE__)

template <typename T>
[[nodiscard]] bool resultOkImpl(const T& t, const char* file, int line) {
	auto result = !std::holds_alternative<QString>(t);
	if (!result) {
		qDebug() << "Result not OK at" << QStringLiteral("%1:%2").arg(file).arg(line) << (*(std::get_if<QString>(&t)));
	}
	return result;
}

#define unwrap(t) (*(std::get_if<0>(&t)))
