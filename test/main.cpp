#include <QObject>
#include <QTest>
#include <QSignalSpy>
#include <QRegularExpression>

#include <optional>

#include "clientmanager.h"
#include "client.h"
#include "protos.h"
#include "coroutine_integration.h"

class Test : public QObject
{
	Q_OBJECT

private:
	SDK::ClientManager* client;

	QString randString() {
		QString str = QUuid::createUuid().toString();
		str.remove(QRegularExpression("{|}|-"));
		return str;
	}

private Q_SLOTS:
	void initTestCase()
	{
		client = new SDK::ClientManager;
	}

	void testAuth()
	{
		QSignalSpy spy(client, &SDK::ClientManager::authEvent);

		{
			client->beginAuthentication("http://localhost:2289");

			QVERIFY(spy.wait());
			QCOMPARE(spy.count(), 1);
		}
		{
			auto it = spy.at(0).at(0).value<protocol::auth::v1::AuthStep>();
			auto opts = it.choice().options();

			QCOMPARE(it.step_case(), protocol::auth::v1::AuthStep::kChoice);
			QVERIFY(std::find(opts.begin(), opts.end(), "register") != opts.end());
		}
		{
			auto req = protocol::auth::v1::NextStepRequest{};
			auto choice = new protocol::auth::v1::NextStepRequest::Choice;
			choice->set_choice("register");
			req.set_allocated_choice(choice);

			client->continueAuthentication(req);

			QVERIFY(spy.wait());
			QCOMPARE(spy.count(), 2);
		}
		{
			auto it = spy.at(1).at(0).value<protocol::auth::v1::AuthStep>();

			QCOMPARE(it.step_case(), protocol::auth::v1::AuthStep::kForm);
		}
		{
			auto req = protocol::auth::v1::NextStepRequest{};
			req.set_allocated_form(new protocol::auth::v1::NextStepRequest::Form);

			auto field = req.mutable_form()->mutable_fields()->Add();
			field->set_string(QString("%1@hey.com").arg(randString()).toStdString());

			field = req.mutable_form()->mutable_fields()->Add();
			field->set_string(randString().toStdString());

			field = req.mutable_form()->mutable_fields()->Add();
			field->set_bytes(randString().toStdString());

			client->continueAuthentication(req);

			QVERIFY(spy.wait());
			QCOMPARE(spy.count(), 3);
		}
	}

	Future<> testGuildCreate()
	{
		auto req = protocol::chat::v1::CreateGuildRequest{};
		req.set_name("hello");

		auto resp = co_await client->chatKit()->CreateGuild(req);
		Q_ASSERT(resp.ok());

		co_return;
	}

	Future<> testHostEquivalence()
	{
		auto c1 = (co_await client->clientForHomeserver("local"));
		auto c2 = (co_await client->clientForHomeserver("localhost"));
		auto c3 = (co_await client->clientForHomeserver("https://localhost"));
		auto c4 = (co_await client->clientForHomeserver("https://localhost:12345"));

		Q_ASSERT(c1 == c2);
		Q_ASSERT(c1 == c3);
		Q_ASSERT(c1 == c4);
 
		co_return;
	}

	void cleanupTestCase()
	{
		client->deleteLater();
		client = nullptr;
	}
};

QTEST_MAIN(Test)

#include "main.moc"
