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
#include <QWebSocket>
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/empty.hrpc.types.h"

class Receive__protocol_sync_v1_Syn__Send__protocol_sync_v1_Ack__Stream : public QWebSocket {
	
	Q_OBJECT

	public: Q_SIGNAL void receivedMessage(protocol::sync::v1::Syn msg);

	public: Receive__protocol_sync_v1_Syn__Send__protocol_sync_v1_Ack__Stream(const QString &origin = QString(), QWebSocketProtocol::Version version = QWebSocketProtocol::VersionLatest, QObject *parent = nullptr) : QWebSocket(origin, version, parent)
	{
		connect(this, &QWebSocket::binaryMessageReceived, [=](const QByteArray& msg) {
			protocol::sync::v1::Syn incoming;

			if (!incoming.ParseFromArray(msg.constData(), msg.length())) {
				return;
			}

			Q_EMIT receivedMessage(incoming);
		});
	}


	public: [[nodiscard]] bool send(const protocol::sync::v1::Ack& in) {
		std::string strData;
		if (!in.SerializeToString(&strData)) {
			return false;
		}
		QByteArray data = QByteArray::fromStdString(strData);

		auto count = sendBinaryMessage(data);
		return count == data.length();
	}
};

class PostboxServiceServiceClient {
	QString host;
	bool secure;
	QString httpProtocol() const { return secure ? QStringLiteral("https://") : QStringLiteral("http://"); }
	QString wsProtocol() const { return secure ? QStringLiteral("wss://") : QStringLiteral("ws://"); }
	public: explicit PostboxServiceServiceClient(const QString& host, bool secure) : host(host), secure(secure) {}
public:
	QMap<QByteArray,QString> universalHeaders;
	template<typename T> using Result = std::variant<T, QString>;
	[[ nodiscard ]] Receive__protocol_sync_v1_Syn__Send__protocol_sync_v1_Ack__Stream* Pull(QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> PushSync(const protocol::sync::v1::Event& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> Push(const protocol::sync::v1::Event& in, QMap<QByteArray,QString> headers = {});
};
