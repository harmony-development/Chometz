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
#include "google/protobuf/any.pb.h"
Q_DECLARE_METATYPE(protocol::sync::v1::SyncRequest)
Q_DECLARE_METATYPE(protocol::sync::v1::PostBoxEvent)
Q_DECLARE_METATYPE(protocol::sync::v1::PostEventRequest)
