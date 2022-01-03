#pragma once

#include "client.h"
#include "protos.h"

namespace SDK
{

// retry in 0.5 seconds
const int initialDelay = 500;

// don't wait more than 20 seconds to retry
const int maximumDelay = 20000;

struct Client::Private
{
	QString homeserver;
	QSharedPointer<Receive__protocol_chat_v1_StreamEventsResponse__Send__protocol_chat_v1_StreamEventsRequest__Stream> eventStream;

	std::string authID;

	quint64 userID;
	std::string session;

	ConnectionState state = ConnectionState::NotApplicable;
	QDateTime when;

	int wsDelay = initialDelay;
	void increaseDelay() {
		wsDelay *= 2;
		wsDelay = qMin(wsDelay, maximumDelay);
	}
};

};
