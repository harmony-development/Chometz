#ifdef __clang__

#include <experimental/coroutine>
namespace costd = std::experimental;

#else

#include <coroutine>
namespace costd = std;

#endif

#include <QFuture>

extern QFuture<QString> it();

class Promise
{
    costd::suspend_never initial_suspend() const noexcept {
        return {};
    }
};


template<typename T>
class FutureAwaiter
{
	QFuture<T> m_future;
	QSharedPointer<QFutureWatcher<T>> m_futureWatcher;
public:
	explicit FutureAwaiter(QFuture<T> value) noexcept
	: m_future(value), m_futureWatcher(value) {

	}
	~FutureAwaiter() {
	}
	bool await_ready() noexcept {
		return m_future.isFinished();
	}
	void await_suspend(costd::coroutine_handle<> awaiting) noexcept {
		connect(m_futureWatcher, &QFutureWatcher<T>::finished, this, [awaiting]() mutable {
			awaiting.resume();
		});
	}
	T await_resume() noexcept {
		return m_future->result();
	}
};

template<typename T>
auto operator co_await(QFuture<T> it)
{
	return FutureAwaiter<T>(it);
};

void test()
{
    co_await it();
}
