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
#include "chat/v1/streaming.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
#include "chat/v1/profile.pb.h"
#include "chat/v1/guilds.pb.h"
#include "chat/v1/channels.pb.h"
#include "chat/v1/messages.pb.h"
#include "chat/v1/emotes.pb.h"
#include "chat/v1/permissions.pb.h"
Q_DECLARE_METATYPE(protocol::chat::v1::StreamEventsRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::Event)
Q_DECLARE_METATYPE(protocol::chat::v1::StreamEventsRequest::SubscribeToGuild)
Q_DECLARE_METATYPE(protocol::chat::v1::StreamEventsRequest::SubscribeToActions)
Q_DECLARE_METATYPE(protocol::chat::v1::StreamEventsRequest::SubscribeToHomeserverEvents)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::MessageSent)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::MessageUpdated)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::MessageDeleted)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::ChannelCreated)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::ChannelUpdated)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::ChannelDeleted)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::GuildUpdated)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::GuildDeleted)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::MemberJoined)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::MemberLeft)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::GuildAddedToList)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::GuildRemovedFromList)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::ActionPerformed)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::RoleMoved)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::ProfileUpdated)
Q_DECLARE_METATYPE(protocol::chat::v1::Event::Typing)
