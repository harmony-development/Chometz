#include <QObject>
#include <QTest>
#include <QSignalSpy>
#include <QRegularExpression>

#include <optional>

#include "chometz_client.h"

class Test : public QObject
{
	Q_OBJECT

private:
	Chometz::Client* client;

	QString randString() {
		QString str = QUuid::createUuid().toString();
		str.remove(QRegularExpression("{|}|-"));
		return str;
	}

private Q_SLOTS:
	void initTestCase()
	{
		client = new Chometz::Client(":memory:");
	}

	void test()
	{
		using namespace Chometz;

		auto r = client->request(SRef<start>(new start));
		QVERIFY(r.settled());
	}

	void cleanupTestCase()
	{
		client->deleteLater();
		client = nullptr;
	}
};

QTEST_MAIN(Test)

#include "main.moc"
