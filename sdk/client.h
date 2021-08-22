#pragma once

#include <QObject>
#include "protos.h"

namespace SDK
{

class ClientManager;

class Client : public QObject
{

	Q_OBJECT

	ClientManager* cm;

	struct Private;
	QScopedPointer<Private> d;

	friend class ClientManager;

	Future<> startAuth();
	Q_SIGNAL void authEvent(protocol::auth::v1::AuthStep step);

	FutureResult<Client*> federateOtherClient(Client* client, QString target);

	void setSession(const std::string& session, quint64 userID);

	Future<> nextStep(protocol::auth::v1::NextStepRequest nstep);

	void startEvents();

	Q_SIGNAL void eventLoopStarted();
	Q_SIGNAL void eventLoopEnded();

public:

	Client(ClientManager* cm, const QString& homeserver);
	~Client();

	std::string session() const;
	quint64 userID() const;
	QString homeserver() const;

	ChatServiceServiceClient* chatKit();
	AuthServiceServiceClient* authKit();
	MediaProxyServiceServiceClient* mediaProxyKit();

	Q_SIGNAL void chatEvent(protocol::chat::v1::Event ev);
	Q_SIGNAL void hsEvent(protocol::chat::v1::Event ev);
	Q_SIGNAL void actionTriggered(protocol::chat::v1::Event::ActionPerformed action);

	void subscribeToGuild(quint64 guildID);
	void subscribeToActions();
	void subscribeToHomeserver();

};

};
