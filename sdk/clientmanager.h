#pragma once

#include <QObject>

#include "client.h"
#include "protos.h"

namespace SDK
{

class ClientManager : public QObject
{

	Q_OBJECT

	struct Private;
	QScopedPointer<Private> d;

	void connectClient(Client* client, const QString& homeserver);

public:
	ClientManager(QObject* object = nullptr);
	~ClientManager();

	void beginAuthentication(const QString& homeserver);
	void continueAuthentication(const protocol::auth::v1::NextStepRequest& req);

	void subscribeToGuild(const QString& homeserver, quint64 guildID);
	void subscribeToActions();
	void subscribeToHomeserver();

	Future<Client*> clientForHomeserver(QString homeserver);

	Future<bool> checkLogin(QString token, QString hs, quint64 userID);

	Q_SIGNAL void ready(const QString& hs, quint64 userID, const QString& token);

	Q_SIGNAL void authEvent(protocol::auth::v1::AuthStep step);
	Q_SIGNAL void hsEvent(protocol::chat::v1::StreamEvent ev);

	Q_SIGNAL void chatEvent(QString homeserver, protocol::chat::v1::StreamEvent ev);
	Q_SIGNAL void actionTriggered(QString homeserver, protocol::chat::v1::StreamEvent::ActionPerformed action);

	ChatServiceServiceClient* chatKit();
	AuthServiceServiceClient* authKit();
	MediaProxyServiceServiceClient* mediaProxyKit();

	template<typename Request, typename SubClient, typename Method>
	std::result_of_t<Method(std::result_of_t<SubClient(Client*)>, Request, QMap<QByteArray, QString>)>
	dispatch(QString homeserver, Request req, SubClient subclient, Method method)
	{
		using ClientReturn = std::result_of_t<decltype(subclient)(Client*)>;
		using MethodReturn = std::result_of_t<decltype(method)(ClientReturn, Request, QMap<QByteArray, QString>)>;

		MethodReturn ret;

		Client* client_ = co_await clientForHomeserver(homeserver);
		ClientReturn subclient_ = ((client_->*subclient)());

		auto response = co_await ((subclient_->*method)(req, {}));

		if (response.ok()) {
			co_return response.value();
		} else {
			co_return response.error();
		}
	}

};

};
