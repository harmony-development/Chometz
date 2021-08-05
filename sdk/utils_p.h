#pragma once

#include <QCoreApplication>
#include <QTimer>
#include <functional>

inline void dispatchToMainThread(std::function<void()> callback)
{
	// any thread
	QTimer* timer = new QTimer();
	timer->moveToThread(QCoreApplication::instance()->thread());
	timer->setSingleShot(true);
	QObject::connect(timer, &QTimer::timeout, [=]()
	{
		// main thread
		callback();
		timer->deleteLater();
	});
	QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 0));
}
