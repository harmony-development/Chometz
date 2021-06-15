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
#include "auth/v1/auth.pb.h"
#include "auth/v1/auth.hrpc.types.h"
#include <QWebSocket>
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

class Receive__protocol_auth_v1_AuthStep__Stream : public QWebSocket {
	
	Q_OBJECT

	public: Q_SIGNAL void receivedMessage(protocol::auth::v1::AuthStep msg);

	public: Receive__protocol_auth_v1_AuthStep__Stream(const QString &origin = QString(), QWebSocketProtocol::Version version = QWebSocketProtocol::VersionLatest, QObject *parent = nullptr) : QWebSocket(origin, version, parent)
	{
		connect(this, &QWebSocket::binaryMessageReceived, [=](const QByteArray& msg) {
			protocol::auth::v1::AuthStep incoming;

			if (!incoming.ParseFromArray(msg.constData(), msg.length())) {
				return;
			}

			Q_EMIT receivedMessage(incoming);
		});
	}

};

class AuthServiceServiceClient {
	QString host;
	bool secure;
	QString httpProtocol() const { return secure ? QStringLiteral("https://") : QStringLiteral("http://"); }
	QString wsProtocol() const { return secure ? QStringLiteral("wss://") : QStringLiteral("ws://"); }
	public: explicit AuthServiceServiceClient(const QString& host, bool secure) : host(host), secure(secure) {}
public:
	QMap<QByteArray,QString> universalHeaders;
	template<typename T> using Result = std::variant<T, QString>;
	[[ nodiscard ]] Result<protocol::auth::v1::FederateReply> FederateSync(const protocol::auth::v1::FederateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::auth::v1::FederateReply, QString> Federate(const protocol::auth::v1::FederateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::auth::v1::Session> LoginFederatedSync(const protocol::auth::v1::LoginFederatedRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::auth::v1::Session, QString> LoginFederated(const protocol::auth::v1::LoginFederatedRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::auth::v1::KeyReply> KeySync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::auth::v1::KeyReply, QString> Key(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::auth::v1::BeginAuthResponse> BeginAuthSync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::auth::v1::BeginAuthResponse, QString> BeginAuth(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::auth::v1::AuthStep> NextStepSync(const protocol::auth::v1::NextStepRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::auth::v1::AuthStep, QString> NextStep(const protocol::auth::v1::NextStepRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::auth::v1::AuthStep> StepBackSync(const protocol::auth::v1::StepBackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::auth::v1::AuthStep, QString> StepBack(const protocol::auth::v1::StepBackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Receive__protocol_auth_v1_AuthStep__Stream* StreamSteps(const protocol::auth::v1::StreamStepsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> CheckLoggedInSync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> CheckLoggedIn(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers = {});
};
