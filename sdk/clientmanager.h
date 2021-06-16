#pragma once

#include <QObject>

#include "protos.h"

class ChatServiceServiceClient;
class AuthServiceServiceClient;
class MediaProxyServiceServiceClient;

namespace SDK
{

class Client;

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

	Client* clientForHomeserver(const QString& homeserver);

	Future<bool> checkLogin(const QString& token, const QString& hs, quint64 userID);

	Q_SIGNAL void ready(const QString& hs, quint64 userID, const QString& token);

	Q_SIGNAL void authEvent(protocol::auth::v1::AuthStep step);
	Q_SIGNAL void hsEvent(protocol::chat::v1::Event ev);

	Q_SIGNAL void chatEvent(QString homeserver, protocol::chat::v1::Event ev);
	Q_SIGNAL void actionTriggered(QString homeserver, protocol::chat::v1::Event::ActionPerformed action);

	ChatServiceServiceClient* chatKit();
	AuthServiceServiceClient* authKit();
	MediaProxyServiceServiceClient* mediaProxyKit();

};

};
