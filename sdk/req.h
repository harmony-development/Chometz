#pragma once

#include "protos.h"

namespace SDK
{

class RequestClient
	: public ChatServiceServiceClient
	, public AuthServiceServiceClient
	, public MediaProxyServiceServiceClient
	, public EmoteServiceServiceClient
	, public ProfileServiceServiceClient
	, public VoiceServiceServiceClient
{
public:
	explicit RequestClient(const QString& host, bool secure)
		: ChatServiceServiceClient(host, secure)
		, AuthServiceServiceClient(host, secure)
		, MediaProxyServiceServiceClient(host, secure)
		, EmoteServiceServiceClient(host, secure)
		, ProfileServiceServiceClient(host, secure)
		, VoiceServiceServiceClient(host, secure)
	{
	}
};

using R = RequestClient;

};
