#include "chat/v1/chat.hrpc.client.h"
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
auto ChatServiceServiceClient::CreateGuildSync(const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::CreateGuildResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateGuild"));

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

	protocol::chat::v1::CreateGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::CreateGuildResponse, QString> ChatServiceServiceClient::CreateGuild(const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::CreateGuildResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateGuild"));

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

		protocol::chat::v1::CreateGuildResponse ret;
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
auto ChatServiceServiceClient::CreateInviteSync(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::CreateInviteResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateInvite"));

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

	protocol::chat::v1::CreateInviteResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::CreateInviteResponse, QString> ChatServiceServiceClient::CreateInvite(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::CreateInviteResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateInvite"));

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

		protocol::chat::v1::CreateInviteResponse ret;
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
auto ChatServiceServiceClient::CreateChannelSync(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::CreateChannelResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateChannel"));

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

	protocol::chat::v1::CreateChannelResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::CreateChannelResponse, QString> ChatServiceServiceClient::CreateChannel(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::CreateChannelResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateChannel"));

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

		protocol::chat::v1::CreateChannelResponse ret;
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
auto ChatServiceServiceClient::CreateEmotePackSync(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::CreateEmotePackResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateEmotePack"));

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

	protocol::chat::v1::CreateEmotePackResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::CreateEmotePackResponse, QString> ChatServiceServiceClient::CreateEmotePack(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::CreateEmotePackResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/CreateEmotePack"));

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

		protocol::chat::v1::CreateEmotePackResponse ret;
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
auto ChatServiceServiceClient::GetGuildListSync(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildListResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildList"));

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

	protocol::chat::v1::GetGuildListResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetGuildListResponse, QString> ChatServiceServiceClient::GetGuildList(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetGuildListResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildList"));

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

		protocol::chat::v1::GetGuildListResponse ret;
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
auto ChatServiceServiceClient::GetGuildSync(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuild"));

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

	protocol::chat::v1::GetGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetGuildResponse, QString> ChatServiceServiceClient::GetGuild(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetGuildResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuild"));

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

		protocol::chat::v1::GetGuildResponse ret;
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
auto ChatServiceServiceClient::GetGuildInvitesSync(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildInvitesResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildInvites"));

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

	protocol::chat::v1::GetGuildInvitesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetGuildInvitesResponse, QString> ChatServiceServiceClient::GetGuildInvites(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetGuildInvitesResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildInvites"));

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

		protocol::chat::v1::GetGuildInvitesResponse ret;
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
auto ChatServiceServiceClient::GetGuildMembersSync(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildMembersResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildMembers"));

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

	protocol::chat::v1::GetGuildMembersResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetGuildMembersResponse, QString> ChatServiceServiceClient::GetGuildMembers(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetGuildMembersResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildMembers"));

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

		protocol::chat::v1::GetGuildMembersResponse ret;
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
auto ChatServiceServiceClient::GetGuildChannelsSync(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildChannelsResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildChannels"));

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

	protocol::chat::v1::GetGuildChannelsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetGuildChannelsResponse, QString> ChatServiceServiceClient::GetGuildChannels(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetGuildChannelsResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildChannels"));

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

		protocol::chat::v1::GetGuildChannelsResponse ret;
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
auto ChatServiceServiceClient::GetChannelMessagesSync(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetChannelMessagesResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetChannelMessages"));

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

	protocol::chat::v1::GetChannelMessagesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetChannelMessagesResponse, QString> ChatServiceServiceClient::GetChannelMessages(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetChannelMessagesResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetChannelMessages"));

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

		protocol::chat::v1::GetChannelMessagesResponse ret;
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
auto ChatServiceServiceClient::GetMessageSync(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetMessageResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetMessage"));

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

	protocol::chat::v1::GetMessageResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetMessageResponse, QString> ChatServiceServiceClient::GetMessage(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetMessageResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetMessage"));

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

		protocol::chat::v1::GetMessageResponse ret;
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
auto ChatServiceServiceClient::GetEmotePacksSync(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetEmotePacksResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetEmotePacks"));

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

	protocol::chat::v1::GetEmotePacksResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetEmotePacksResponse, QString> ChatServiceServiceClient::GetEmotePacks(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetEmotePacksResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetEmotePacks"));

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

		protocol::chat::v1::GetEmotePacksResponse ret;
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
auto ChatServiceServiceClient::GetEmotePackEmotesSync(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetEmotePackEmotesResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetEmotePackEmotes"));

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

	protocol::chat::v1::GetEmotePackEmotesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetEmotePackEmotesResponse, QString> ChatServiceServiceClient::GetEmotePackEmotes(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetEmotePackEmotesResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetEmotePackEmotes"));

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

		protocol::chat::v1::GetEmotePackEmotesResponse ret;
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
auto ChatServiceServiceClient::UpdateGuildInformationSync(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateGuildInformation"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::UpdateGuildInformation(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateGuildInformation"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::UpdateChannelInformationSync(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateChannelInformation"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::UpdateChannelInformation(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateChannelInformation"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::UpdateChannelOrderSync(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateChannelOrder"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::UpdateChannelOrder(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateChannelOrder"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::UpdateAllChannelOrderSync(const protocol::chat::v1::UpdateAllChannelOrderRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateAllChannelOrder"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::UpdateAllChannelOrder(const protocol::chat::v1::UpdateAllChannelOrderRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateAllChannelOrder"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::UpdateMessageTextSync(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateMessageText"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::UpdateMessageText(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UpdateMessageText"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::AddEmoteToPackSync(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddEmoteToPack"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::AddEmoteToPack(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddEmoteToPack"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteGuildSync(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteGuild"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteGuild(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteGuild"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteInviteSync(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteInvite"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteInvite(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteInvite"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteChannelSync(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteChannel"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteChannel(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteChannel"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteMessageSync(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteMessage"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteMessage(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteMessage"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteEmoteFromPackSync(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteEmoteFromPack"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteEmoteFromPack(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteEmoteFromPack"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteEmotePackSync(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteEmotePack"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteEmotePack(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteEmotePack"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DequipEmotePackSync(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DequipEmotePack"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DequipEmotePack(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DequipEmotePack"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::EquipEmotePackSync(const protocol::chat::v1::EquipEmotePackRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/EquipEmotePack"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::EquipEmotePack(const protocol::chat::v1::EquipEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/EquipEmotePack"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::JoinGuildSync(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::JoinGuildResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/JoinGuild"));

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

	protocol::chat::v1::JoinGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::JoinGuildResponse, QString> ChatServiceServiceClient::JoinGuild(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::JoinGuildResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/JoinGuild"));

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

		protocol::chat::v1::JoinGuildResponse ret;
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
auto ChatServiceServiceClient::LeaveGuildSync(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/LeaveGuild"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::LeaveGuild(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/LeaveGuild"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::TriggerActionSync(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/TriggerAction"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::TriggerAction(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/TriggerAction"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::SendMessageSync(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::SendMessageResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/SendMessage"));

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

	protocol::chat::v1::SendMessageResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::SendMessageResponse, QString> ChatServiceServiceClient::SendMessage(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::SendMessageResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/SendMessage"));

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

		protocol::chat::v1::SendMessageResponse ret;
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
auto ChatServiceServiceClient::QueryHasPermissionSync(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::QueryPermissionsResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/QueryHasPermission"));

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

	protocol::chat::v1::QueryPermissionsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::QueryPermissionsResponse, QString> ChatServiceServiceClient::QueryHasPermission(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::QueryPermissionsResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/QueryHasPermission"));

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

		protocol::chat::v1::QueryPermissionsResponse ret;
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
auto ChatServiceServiceClient::BatchQueryHasPermissionSync(const protocol::chat::v1::BatchQueryPermissionsRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::BatchQueryPermissionsResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/BatchQueryHasPermission"));

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

	protocol::chat::v1::BatchQueryPermissionsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::BatchQueryPermissionsResponse, QString> ChatServiceServiceClient::BatchQueryHasPermission(const protocol::chat::v1::BatchQueryPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::BatchQueryPermissionsResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/BatchQueryHasPermission"));

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

		protocol::chat::v1::BatchQueryPermissionsResponse ret;
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
auto ChatServiceServiceClient::SetPermissionsSync(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/SetPermissions"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::SetPermissions(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/SetPermissions"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::GetPermissionsSync(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetPermissionsResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetPermissions"));

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

	protocol::chat::v1::GetPermissionsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetPermissionsResponse, QString> ChatServiceServiceClient::GetPermissions(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetPermissionsResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetPermissions"));

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

		protocol::chat::v1::GetPermissionsResponse ret;
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
auto ChatServiceServiceClient::MoveRoleSync(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::MoveRoleResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/MoveRole"));

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

	protocol::chat::v1::MoveRoleResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::MoveRoleResponse, QString> ChatServiceServiceClient::MoveRole(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::MoveRoleResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/MoveRole"));

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

		protocol::chat::v1::MoveRoleResponse ret;
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
auto ChatServiceServiceClient::GetGuildRolesSync(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildRolesResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildRoles"));

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

	protocol::chat::v1::GetGuildRolesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetGuildRolesResponse, QString> ChatServiceServiceClient::GetGuildRoles(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetGuildRolesResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetGuildRoles"));

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

		protocol::chat::v1::GetGuildRolesResponse ret;
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
auto ChatServiceServiceClient::AddGuildRoleSync(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::AddGuildRoleResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddGuildRole"));

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

	protocol::chat::v1::AddGuildRoleResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::AddGuildRoleResponse, QString> ChatServiceServiceClient::AddGuildRole(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::AddGuildRoleResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddGuildRole"));

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

		protocol::chat::v1::AddGuildRoleResponse ret;
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
auto ChatServiceServiceClient::ModifyGuildRoleSync(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/ModifyGuildRole"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::ModifyGuildRole(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/ModifyGuildRole"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::DeleteGuildRoleSync(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteGuildRole"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::DeleteGuildRole(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/DeleteGuildRole"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::ManageUserRolesSync(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/ManageUserRoles"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::ManageUserRoles(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/ManageUserRoles"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::GetUserRolesSync(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetUserRolesResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUserRoles"));

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

	protocol::chat::v1::GetUserRolesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetUserRolesResponse, QString> ChatServiceServiceClient::GetUserRoles(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetUserRolesResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUserRoles"));

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

		protocol::chat::v1::GetUserRolesResponse ret;
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
auto ChatServiceServiceClient::StreamEvents(QMap<QByteArray,QString> headers) -> Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream*
{
auto url = QUrl(wsProtocol()+host); url.setPath(QStringLiteral("/protocol.chat.v1.ChatService/StreamEvents")); auto req = QNetworkRequest(url);

					for (const auto& item : universalHeaders.keys()) {
						req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
					}
					for (const auto& item : headers.keys()) {
						req.setRawHeader(item, headers[item].toLocal8Bit());
					}
				
	auto sock = new Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream();
	sock->open(req);
	return sock;
}
auto ChatServiceServiceClient::GetUserSync(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetUserResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUser"));

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

	protocol::chat::v1::GetUserResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetUserResponse, QString> ChatServiceServiceClient::GetUser(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetUserResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUser"));

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

		protocol::chat::v1::GetUserResponse ret;
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
auto ChatServiceServiceClient::GetUserBulkSync(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetUserBulkResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUserBulk"));

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

	protocol::chat::v1::GetUserBulkResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetUserBulkResponse, QString> ChatServiceServiceClient::GetUserBulk(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetUserBulkResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUserBulk"));

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

		protocol::chat::v1::GetUserBulkResponse ret;
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
auto ChatServiceServiceClient::GetUserMetadataSync(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::GetUserMetadataResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUserMetadata"));

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

	protocol::chat::v1::GetUserMetadataResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::GetUserMetadataResponse, QString> ChatServiceServiceClient::GetUserMetadata(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::GetUserMetadataResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/GetUserMetadata"));

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

		protocol::chat::v1::GetUserMetadataResponse ret;
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
auto ChatServiceServiceClient::ProfileUpdateSync(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/ProfileUpdate"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::ProfileUpdate(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/ProfileUpdate"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::TypingSync(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/Typing"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::Typing(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/Typing"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::PreviewGuildSync(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::PreviewGuildResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/PreviewGuild"));

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

	protocol::chat::v1::PreviewGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<protocol::chat::v1::PreviewGuildResponse, QString> ChatServiceServiceClient::PreviewGuild(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<protocol::chat::v1::PreviewGuildResponse, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/PreviewGuild"));

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

		protocol::chat::v1::PreviewGuildResponse ret;
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
auto ChatServiceServiceClient::BanUserSync(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/BanUser"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::BanUser(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/BanUser"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::KickUserSync(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/KickUser"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::KickUser(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/KickUser"));

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

		google::protobuf::Empty ret;
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
auto ChatServiceServiceClient::UnbanUserSync(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UnbanUser"));

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

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
FutureResult<google::protobuf::Empty, QString> ChatServiceServiceClient::UnbanUser(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers)

{
	FutureResult<google::protobuf::Empty, QString> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.fail({QStringLiteral("failed to serialize protobuf")}); return res; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/UnbanUser"));

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

		google::protobuf::Empty ret;
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
