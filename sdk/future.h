#pragma once

#include <QDebug>
#include <functional>
#include <optional>

namespace Chometz
{

template<typename T>
class Future
{

	struct Shared {
		std::optional<T> result;

		// ok, err
		std::function<void(T)> onComplete = [](T) {};
	};
	std::shared_ptr<Shared> d;

public:
	Future() {
		d.reset(new Shared);
	}
	Future(const Future<T>& other) {
		this->d = other.d;
	}
	~Future() {
	}

	void settle(const T& value) const {
		if (d->result.has_value()) {
			return;
		}
		d->result = value;

		d->onComplete(value);
	}
	T result() const {
		return *d->result;
	}
	bool settled() const {
		return d->result.has_value();
	}
	template<typename E>
	Future<E> then(std::function<E(T)> conv) {
		Future<E> ret;

		d->onComplete = [ret, conv](T it) {
			ret.settle(conv(it));
		};

		if (d->result.has_value()) {
			d->onComplete(*d->result);
		}

		return ret;
	}
	void then(std::function<void(T)> it) {
		d->onComplete = it;

		if (d->result.has_value()) {
			d->onComplete(*d->result);
		}
	}
};

};
