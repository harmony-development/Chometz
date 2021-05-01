#pragma once

#include <QObject>

#include "auth/v1/auth.pb.h"

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

public:
	ClientManager(QObject* object = nullptr);
	~ClientManager();

	void beginAuthentication(const QString& homeserver);
	void continueAuthentication(const protocol::auth::v1::NextStepRequest& req);
	Q_SIGNAL void authEvent(protocol::auth::v1::AuthStep step);

	ChatServiceServiceClient* chatKit();
	AuthServiceServiceClient* authKit();
	MediaProxyServiceServiceClient* mediaProxyKit();

};

};
