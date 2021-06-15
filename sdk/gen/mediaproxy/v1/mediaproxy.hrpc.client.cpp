#include "mediaproxy/v1/mediaproxy.hrpc.client.h"
#include "QThreadStorage"
namespace {
QThreadStorage<QNetworkAccessManager*> globalNam;
void initialiseGlobalNam(bool secure, const QString& host) {
	if (globalNam.hasLocalData()) {
		return;
	}

	auto split = host.split(":");
	auto hname = split[0];
	auto port = split[1].toInt();
	
	globalNam.setLocalData(new QNetworkAccessManager);
	if (secure) {
		globalNam.localData()->connectToHostEncrypted(hname, port);
	} else {
		globalNam.localData()->connectToHost(hname, port);
	}
}
}
auto MediaProxyServiceServiceClient::FetchLinkMetadataSync(const protocol::mediaproxy::v1::FetchLinkMetadataRequest& in, QMap<QByteArray,QString> headers) -> MediaProxyServiceServiceClient::Result<protocol::mediaproxy::v1::FetchLinkMetadataResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.mediaproxy.v1.MediaProxyService/FetchLinkMetadata"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
		req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
	}
	for (const auto& item : headers.keys()) {
		req.setRawHeader(item, headers[item].toLocal8Bit());
	}
	req.setRawHeader("content-type", "application/hrpc");
	req.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);

	auto nam = globalNam.localData();
	auto val = nam->post(req, data);



	while (!val->isFinished()) {
		QCoreApplication::processEvents();
	}

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::mediaproxy::v1::FetchLinkMetadataResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::mediaproxy::v1::FetchLinkMetadataResponse, QString> MediaProxyServiceServiceClient::FetchLinkMetadata(const protocol::mediaproxy::v1::FetchLinkMetadataRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::mediaproxy::v1::FetchLinkMetadataResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.mediaproxy.v1.MediaProxyService/FetchLinkMetadata"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
		req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
	}
	for (const auto& item : headers.keys()) {
		req.setRawHeader(item, headers[item].toLocal8Bit());
	}
	req.setRawHeader("content-type", "application/hrpc");
	req.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);

	auto nam = globalNam.localData();
	auto val = nam->post(req, data);



	QObject::connect(val, &QNetworkReply::finished, [val, res]() mutable {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.fail({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::mediaproxy::v1::FetchLinkMetadataResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.fail({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.succeed({ret});
		return;
	});

	return res;

}
auto MediaProxyServiceServiceClient::InstantViewSync(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers) -> MediaProxyServiceServiceClient::Result<protocol::mediaproxy::v1::InstantViewResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.mediaproxy.v1.MediaProxyService/InstantView"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
		req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
	}
	for (const auto& item : headers.keys()) {
		req.setRawHeader(item, headers[item].toLocal8Bit());
	}
	req.setRawHeader("content-type", "application/hrpc");
	req.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);

	auto nam = globalNam.localData();
	auto val = nam->post(req, data);



	while (!val->isFinished()) {
		QCoreApplication::processEvents();
	}

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::mediaproxy::v1::InstantViewResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::mediaproxy::v1::InstantViewResponse, QString> MediaProxyServiceServiceClient::InstantView(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::mediaproxy::v1::InstantViewResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.mediaproxy.v1.MediaProxyService/InstantView"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
		req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
	}
	for (const auto& item : headers.keys()) {
		req.setRawHeader(item, headers[item].toLocal8Bit());
	}
	req.setRawHeader("content-type", "application/hrpc");
	req.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);

	auto nam = globalNam.localData();
	auto val = nam->post(req, data);



	QObject::connect(val, &QNetworkReply::finished, [val, res]() mutable {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.fail({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::mediaproxy::v1::InstantViewResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.fail({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.succeed({ret});
		return;
	});

	return res;

}
auto MediaProxyServiceServiceClient::CanInstantViewSync(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers) -> MediaProxyServiceServiceClient::Result<protocol::mediaproxy::v1::CanInstantViewResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.mediaproxy.v1.MediaProxyService/CanInstantView"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
		req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
	}
	for (const auto& item : headers.keys()) {
		req.setRawHeader(item, headers[item].toLocal8Bit());
	}
	req.setRawHeader("content-type", "application/hrpc");
	req.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);

	auto nam = globalNam.localData();
	auto val = nam->post(req, data);



	while (!val->isFinished()) {
		QCoreApplication::processEvents();
	}

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::mediaproxy::v1::CanInstantViewResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::mediaproxy::v1::CanInstantViewResponse, QString> MediaProxyServiceServiceClient::CanInstantView(const protocol::mediaproxy::v1::InstantViewRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::mediaproxy::v1::CanInstantViewResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.mediaproxy.v1.MediaProxyService/CanInstantView"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
		req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
	}
	for (const auto& item : headers.keys()) {
		req.setRawHeader(item, headers[item].toLocal8Bit());
	}
	req.setRawHeader("content-type", "application/hrpc");
	req.setAttribute(QNetworkRequest::Http2AllowedAttribute, true);

	auto nam = globalNam.localData();
	auto val = nam->post(req, data);



	QObject::connect(val, &QNetworkReply::finished, [val, res]() mutable {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.fail({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::mediaproxy::v1::CanInstantViewResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.fail({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.succeed({ret});
		return;
	});

	return res;

}
