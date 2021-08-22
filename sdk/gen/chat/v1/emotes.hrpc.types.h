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
#include "chat/v1/emotes.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
#include "chat/v1/permissions.pb.h"
#include "chat/v1/profile.pb.h"
#include "chat/v1/guilds.pb.h"
#include "chat/v1/channels.pb.h"
#include "chat/v1/messages.pb.h"
#include "chat/v1/streaming.pb.h"
Q_DECLARE_METATYPE(protocol::chat::v1::EmotePack)
Q_DECLARE_METATYPE(protocol::chat::v1::Emote)
Q_DECLARE_METATYPE(protocol::chat::v1::CreateEmotePackRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::CreateEmotePackResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetEmotePacksRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetEmotePacksResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetEmotePackEmotesRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetEmotePackEmotesResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::AddEmoteToPackRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::DeleteEmoteFromPackRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::DeleteEmotePackRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::DequipEmotePackRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::EquipEmotePackRequest)
