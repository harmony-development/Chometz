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
	std::unique_ptr<EmoteServiceServiceClient> emoteKit;
	std::unique_ptr<ProfileServiceServiceClient> profileKit;

	QSharedPointer<Receive__protocol_chat_v1_StreamEventsResponse__Send__protocol_chat_v1_StreamEventsRequest__Stream> eventStream;

	std::string authID;

	quint64 userID;
	std::string session;
};

};
