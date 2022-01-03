#pragma once

#include <QObject>
#include "protos.h"
#include "req.h"

namespace SDK
{

class ClientManager;

class Client : public QObject, public RequestClient
{

	Q_OBJECT

	ClientManager* cm;

	struct Private;
	QScopedPointer<Private> d;

	friend class ClientManager;

	Future<Unit> startAuth();
	Q_SIGNAL void authEvent(protocol::auth::v1::AuthStep step);

	Future<Client*> federateOtherClient(Client* client, QString target);

	void setSession(const std::string& session, quint64 userID);

	Future<Unit> nextStep(protocol::auth::v1::NextStepRequest nstep);

	void startEvents();

public:

	enum ConnectionState
	{
		NotApplicable,
		Offline,
		ResolvingHost,
		Connecting,
		Connected,
		Disconnecting,
		WaitingToReconnect,
	};
	Q_ENUM(ConnectionState)

	Client(ClientManager* cm, const QString& homeserver);
	~Client();

	std::string session() const;
	quint64 userID() const;
	QString homeserver() const;

	Q_SIGNAL void chatEvent(protocol::chat::v1::StreamEvent ev);
	Q_SIGNAL void hsEvent(protocol::chat::v1::StreamEvent ev);
	Q_SIGNAL void actionTriggered(protocol::chat::v1::StreamEvent::ActionPerformed action);

	ConnectionState connectionState() const;
	QDateTime reconnectingIn() const;
	Q_SIGNAL void connectionStateChanged(ConnectionState);

	void subscribeToGuild(quint64 guildID);
	void subscribeToActions();
	void subscribeToHomeserver();

};

};
