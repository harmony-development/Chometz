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
#include "voice/v1/voice.pb.h"
#include <QWebSocket>
#include "google/protobuf/empty.pb.h"
Q_DECLARE_METATYPE(protocol::voice::v1::Signal)
Q_DECLARE_METATYPE(protocol::voice::v1::ConnectRequest)
Q_DECLARE_METATYPE(protocol::voice::v1::ConnectResponse)
Q_DECLARE_METATYPE(protocol::voice::v1::StreamStateRequest)
