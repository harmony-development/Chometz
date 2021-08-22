#include "voice/v1/voice.hrpc.client.h"
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
auto VoiceServiceServiceClient::ConnectSync(const protocol::voice::v1::ConnectRequest& in, QMap<QByteArray,QString> headers) -> VoiceServiceServiceClient::Result<protocol::voice::v1::ConnectResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.voice.v1.VoiceService/Connect"));

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

	auto response = val->readAll();

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2\n%3").arg(val->error()).arg(val->errorString()).arg(QString::fromLocal8Bit(response))};
	}

	protocol::voice::v1::ConnectResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::voice::v1::ConnectResponse, QString> VoiceServiceServiceClient::Connect(const protocol::voice::v1::ConnectRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::voice::v1::ConnectResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.voice.v1.VoiceService/Connect"));

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
		auto response = val->readAll();

		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.fail({QStringLiteral("request failure(%1): %2\n%3").arg(val->error()).arg(val->errorString()).arg(QString::fromLocal8Bit(response))});
			return;
		}

		protocol::voice::v1::ConnectResponse ret;
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
auto VoiceServiceServiceClient::StreamState(const protocol::voice::v1::StreamStateRequest& in, QMap<QByteArray,QString> headers) -> Receive__protocol_voice_v1_Signal__Stream*
{
auto url = QUrl(wsProtocol()+host); url.setPath(QStringLiteral("/protocol.voice.v1.VoiceService/StreamState")); auto req = QNetworkRequest(url);

					for (const auto& item : universalHeaders.keys()) {
						req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
					}
					for (const auto& item : headers.keys()) {
						req.setRawHeader(item, headers[item].toLocal8Bit());
					}
				
	auto sock = new Receive__protocol_voice_v1_Signal__Stream();
	std::string strData;
	if (!in.SerializeToString(&strData)) { return nullptr; }
	QByteArray data = QByteArray::fromStdString(strData);
	sock->open(req);
	QObject::connect(sock, &QWebSocket::connected, [=]() { sock->sendBinaryMessage(data); });
	return sock;
}
