#pragma once

#include <QObject>

#include "auth/v1/auth.pb.h"
#include "chat/v1/chat.pb.h"

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

	Q_SIGNAL void ready();

	Q_SIGNAL void authEvent(protocol::auth::v1::AuthStep step);
	Q_SIGNAL void hsEvent(protocol::chat::v1::Event ev);

	Q_SIGNAL void chatEvent(QString homeserver, protocol::chat::v1::Event ev);
	Q_SIGNAL void actionTriggered(QString homeserver, protocol::chat::v1::Event::ActionPerformed action);

	ChatServiceServiceClient* chatKit();
	AuthServiceServiceClient* authKit();
	MediaProxyServiceServiceClient* mediaProxyKit();

};

};
