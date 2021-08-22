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
#include "sync/v1/sync.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
Q_DECLARE_METATYPE(protocol::sync::v1::AuthData)
Q_DECLARE_METATYPE(protocol::sync::v1::EventQueue)
Q_DECLARE_METATYPE(protocol::sync::v1::Event)
Q_DECLARE_METATYPE(protocol::sync::v1::Event::UserRemovedFromGuild)
Q_DECLARE_METATYPE(protocol::sync::v1::Event::UserAddedToGuild)
