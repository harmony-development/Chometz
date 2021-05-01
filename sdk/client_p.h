#pragma once

#include "client.h"
#include "protos.h"

namespace SDK
{

struct Client::Private
{
	QString homeserver;

	std::unique_ptr<ChatServiceServiceClient> chatKit;
	std::unique_ptr<AuthServiceServiceClient> authKit;
	std::unique_ptr<MediaProxyServiceServiceClient> mediaProxyKit;

	QSharedPointer<Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream> eventStream;

	std::string authID;
};

};
