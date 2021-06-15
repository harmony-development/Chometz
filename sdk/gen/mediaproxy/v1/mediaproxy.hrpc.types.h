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
#include "mediaproxy/v1/mediaproxy.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::SiteMetadata)
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::MediaMetadata)
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::FetchLinkMetadataRequest)
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::FetchLinkMetadataResponse)
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::InstantViewRequest)
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::InstantViewResponse)
Q_DECLARE_METATYPE(protocol::mediaproxy::v1::CanInstantViewResponse)
