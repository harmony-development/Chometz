#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QFuture>
#include <functional>
#include <variant>
#include "sync/v1/sync.pb.h"
#include <QWebSocket>
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"

class Receive__protocol_sync_v1_PostBoxEvent__Stream : public QWebSocket {
	
	Q_OBJECT

	public: Q_SIGNAL void receivedMessage(protocol::sync::v1::PostBoxEvent msg);

	public: Receive__protocol_sync_v1_PostBoxEvent__Stream(const QString &origin = QString(), QWebSocketProtocol::Version version = QWebSocketProtocol::VersionLatest, QObject *parent = nullptr) : QWebSocket(origin, version, parent)
	{
		connect(this, &QWebSocket::binaryMessageReceived, [=](const QByteArray& msg) {
			protocol::sync::v1::PostBoxEvent incoming;

			if (!incoming.ParseFromArray(msg.constData(), msg.length())) {
				return;
			}

			Q_EMIT receivedMessage(incoming);
		});
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
	[[ nodiscard ]] Receive__protocol_sync_v1_PostBoxEvent__Stream* Sync(const protocol::sync::v1::SyncRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> PostEventSync(const protocol::sync::v1::PostEventRequest& in, QMap<QByteArray,QString> headers = {});
	void PostEventCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::sync::v1::PostEventRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> PostEvent(const protocol::sync::v1::PostEventRequest& in, QMap<QByteArray,QString> headers = {});
};
