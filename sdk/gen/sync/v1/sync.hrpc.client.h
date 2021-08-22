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
#include "sync/v1/sync.hrpc.types.h"
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

class PostboxServiceServiceClient {
	QString host;
	bool secure;
	QString httpProtocol() const { return secure ? QStringLiteral("https://") : QStringLiteral("http://"); }
	QString wsProtocol() const { return secure ? QStringLiteral("wss://") : QStringLiteral("ws://"); }
	public: explicit PostboxServiceServiceClient(const QString& host, bool secure) : host(host), secure(secure) {}
public:
	QMap<QByteArray,QString> universalHeaders;
	template<typename T> using Result = std::variant<T, QString>;
	[[ nodiscard ]] Result<protocol::sync::v1::EventQueue> PullSync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::sync::v1::EventQueue, QString> Pull(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> PushSync(const protocol::sync::v1::Event& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> Push(const protocol::sync::v1::Event& in, QMap<QByteArray,QString> headers = {});
};
