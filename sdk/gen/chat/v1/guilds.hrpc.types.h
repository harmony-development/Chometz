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
#include "chat/v1/guilds.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
#include "chat/v1/profile.pb.h"
#include "chat/v1/channels.pb.h"
#include "chat/v1/messages.pb.h"
#include "chat/v1/emotes.pb.h"
#include "chat/v1/permissions.pb.h"
#include "chat/v1/streaming.pb.h"
Q_DECLARE_METATYPE(protocol::chat::v1::CreateGuildRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::CreateGuildResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::CreateInviteRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::CreateInviteResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildListRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildListResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildInvitesRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildInvitesResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildMembersRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildMembersResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::UpdateGuildInformationRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::DeleteGuildRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::DeleteInviteRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::JoinGuildRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::JoinGuildResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::PreviewGuildRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::PreviewGuildResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::LeaveGuildRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::AddGuildToGuildListRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::AddGuildToGuildListResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::RemoveGuildFromGuildListRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::RemoveGuildFromGuildListResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::BanUserRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::KickUserRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::UnbanUserRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildListResponse::GuildListEntry)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildInvitesResponse::Invite)
