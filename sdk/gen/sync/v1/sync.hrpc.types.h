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
#include <QWebSocket>
#include "google/protobuf/empty.pb.h"
Q_DECLARE_METATYPE(protocol::sync::v1::Event)
Q_DECLARE_METATYPE(protocol::sync::v1::PostEventRequest)
Q_DECLARE_METATYPE(protocol::sync::v1::Ack)
Q_DECLARE_METATYPE(protocol::sync::v1::Syn)
Q_DECLARE_METATYPE(protocol::sync::v1::Event::UserRemovedFromGuild)
Q_DECLARE_METATYPE(protocol::sync::v1::Event::UserAddedToGuild)
