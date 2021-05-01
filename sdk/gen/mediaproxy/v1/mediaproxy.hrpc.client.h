#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <functional>
#include <variant>
#include "mediaproxy/v1/mediaproxy.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"

class MediaProxyServiceServiceClient {
	QString host;
	bool secure;
	QString httpProtocol() const { return secure ? QStringLiteral("https://") : QStringLiteral("http://"); }
	QString wsProtocol() const { return secure ? QStringLiteral("wss://") : QStringLiteral("ws://"); }
	public: explicit MediaProxyServiceServiceClient(const QString& host, bool secure) : host(host), secure(secure) {}
public:
	template<typename T> using Result = std::variant<T, QString>;
	[[ nodiscard ]] Result<protocol::mediaproxy::v1::FetchLinkMetadataResponse> FetchLinkMetadataSync(const protocol::mediaproxy::v1::FetchLinkMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	void FetchLinkMetadata(std::function<void(Result<protocol::mediaproxy::v1::FetchLinkMetadataResponse>)> callback, const protocol::mediaproxy::v1::FetchLinkMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::mediaproxy::v1::InstantViewResponse> InstantViewSync(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
	void InstantView(std::function<void(Result<protocol::mediaproxy::v1::InstantViewResponse>)> callback, const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::mediaproxy::v1::CanInstantViewResponse> CanInstantViewSync(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
	void CanInstantView(std::function<void(Result<protocol::mediaproxy::v1::CanInstantViewResponse>)> callback, const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers = {});
};
