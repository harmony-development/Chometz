#pragma once

#include <functional>

namespace Chometz
{

template<typename T>
class Future
{

	struct Shared {
		T result;

		// ok, err
		std::function<void(T)> onComplete = [](T) {};

		bool settled = false;
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
		if (d->settled) {
			return;
		}
		d->settled = true;

		d->result = value;
		d->onComplete(d->result);
	}
	T result() const {
		return d->result;
	}
	bool settled() const {
		return d->settled;
	}
	template<typename E>
	Future<E> then(std::function<E(T)> conv) {
		Future<E> ret;

		d->onComplete = [ret, conv](T it) {
			ret.settle(conv(it));
		};

		if (d->settled) {
			d->onComplete(d->result);
		}

		return ret;
	}
	void then(std::function<void(T)> it) {
		d->onComplete = it;

		if (d->settled) {
			d->onComplete(d->result);
		}
	}
};

};
