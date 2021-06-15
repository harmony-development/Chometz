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
#include "chat/v1/permissions.pb.h"
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
#include "chat/v1/streaming.pb.h"
Q_DECLARE_METATYPE(protocol::chat::v1::QueryPermissionsRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::QueryPermissionsResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::Permission)
Q_DECLARE_METATYPE(protocol::chat::v1::PermissionList)
Q_DECLARE_METATYPE(protocol::chat::v1::SetPermissionsRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetPermissionsRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetPermissionsResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::Role)
Q_DECLARE_METATYPE(protocol::chat::v1::MoveRoleRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::MoveRoleResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildRolesRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetGuildRolesResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::AddGuildRoleRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::AddGuildRoleResponse)
Q_DECLARE_METATYPE(protocol::chat::v1::DeleteGuildRoleRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::ModifyGuildRoleRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::ManageUserRolesRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetUserRolesRequest)
Q_DECLARE_METATYPE(protocol::chat::v1::GetUserRolesResponse)
