#pragma once
#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QFuture>
#include <functional>
#include <variant>
#include <future.h>
#include "chat/v1/channels.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
#include "chat/v1/permissions.pb.h"
#include "chat/v1/emotes.pb.h"
#include "chat/v1/profile.pb.h"
#include "chat/v1/guilds.pb.h"
#include "chat/v1/messages.pb.h"
#include "chat/v1/streaming.pb.h"
Q_DECLARE_METATYPE(protocol::chat::v1::CreateChannelRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::CreateChannelResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildChannelsRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildChannelsResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::UpdateChannelInformationRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::UpdateChannelOrderRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::UpdateAllChannelOrderRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::DeleteChannelRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::TypingRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildChannelsResponse::Channel)
