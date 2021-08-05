#pragma once

#include <variant>

#include "requests.h"

namespace Chometz {

template <typename T>
struct Result
{
	std::variant<T, error> it;

	Result(T t) : it(t) {}
	Result(error e) : it(e) {}

	bool ok() {
		return std::holds_alternative<T>(it);
	}
	T value() {
#ifdef Q_OS_MACOS
		return *std::get_if<T>(&it);
#else
		return std::get<T>(it);
#endif
	}
	error err() {
#ifdef Q_OS_MACOS
		return *std::get_if<error>(&it);
#else
		return std::get<error>(it);
#endif
	}
};

};
