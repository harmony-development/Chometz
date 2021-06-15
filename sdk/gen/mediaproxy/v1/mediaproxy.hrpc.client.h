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
#include "mediaproxy/v1/mediaproxy.hrpc.types.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/timestamp.hrpc.types.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/empty.hrpc.types.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/any.hrpc.types.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/descriptor.hrpc.types.h"
#include "harmonytypes/v1/types.pb.h"
#include "harmonytypes/v1/types.hrpc.types.h"

class MediaProxyServiceServiceClient {
	QString host;
	bool secure;
	QString httpProtocol() const { return secure ? QStringLiteral("https://") : QStringLiteral("http://"); }
	QString wsProtocol() const { return secure ? QStringLiteral("wss://") : QStringLiteral("ws://"); }
	public: explicit MediaProxyServiceServiceClient(const QString& host, bool secure) : host(host), secure(secure) {}
public:
	QMap<QByteArray,QString> universalHeaders;
	template<typename T> using Result = std::variant<T, QString>;
	[[ nodiscard ]] Result<protocol::mediaproxy::v1::FetchLinkMetadataResponse> FetchLinkMetadataSync(const protocol::mediaproxy::v1::FetchLinkMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::mediaproxy::v1::FetchLinkMetadataResponse, QString> FetchLinkMetadata(const protocol::mediaproxy::v1::FetchLinkMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::mediaproxy::v1::InstantViewResponse> InstantViewSync(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::mediaproxy::v1::InstantViewResponse, QString> InstantView(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::mediaproxy::v1::CanInstantViewResponse> CanInstantViewSync(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::mediaproxy::v1::CanInstantViewResponse, QString> CanInstantView(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
};
