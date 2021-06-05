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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::CreateGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::CreateGuildCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::CreateGuildResponse>)> callback, const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::CreateGuildResponse>> ChatServiceServiceClient::CreateGuild(const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::CreateGuildResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::CreateInviteResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::CreateInviteCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::CreateInviteResponse>)> callback, const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateInviteResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::CreateInviteResponse>> ChatServiceServiceClient::CreateInvite(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::CreateInviteResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateInviteResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::CreateChannelResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::CreateChannelCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::CreateChannelResponse>)> callback, const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateChannelResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::CreateChannelResponse>> ChatServiceServiceClient::CreateChannel(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::CreateChannelResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateChannelResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::CreateEmotePackResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::CreateEmotePackCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::CreateEmotePackResponse>)> callback, const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateEmotePackResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::CreateEmotePackResponse>> ChatServiceServiceClient::CreateEmotePack(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::CreateEmotePackResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::CreateEmotePackResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetGuildListResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetGuildListCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildListResponse>)> callback, const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildListResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildListResponse>> ChatServiceServiceClient::GetGuildList(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetGuildListResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildListResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

}
auto ChatServiceServiceClient::AddGuildToGuildListSync(const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::AddGuildToGuildListResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddGuildToGuildList"));

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

	protocol::chat::v1::AddGuildToGuildListResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::AddGuildToGuildListCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::AddGuildToGuildListResponse>)> callback, const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddGuildToGuildList"));

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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::AddGuildToGuildListResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::AddGuildToGuildListResponse>> ChatServiceServiceClient::AddGuildToGuildList(const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::AddGuildToGuildListResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/AddGuildToGuildList"));

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
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::AddGuildToGuildListResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

}
auto ChatServiceServiceClient::RemoveGuildFromGuildListSync(const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers) -> ChatServiceServiceClient::Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/RemoveGuildFromGuildList"));

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

	protocol::chat::v1::RemoveGuildFromGuildListResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::RemoveGuildFromGuildListCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>)> callback, const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/RemoveGuildFromGuildList"));

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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::RemoveGuildFromGuildListResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>> ChatServiceServiceClient::RemoveGuildFromGuildList(const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.chat.v1.ChatService/RemoveGuildFromGuildList"));

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
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::RemoveGuildFromGuildListResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetGuildCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildResponse>)> callback, const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildResponse>> ChatServiceServiceClient::GetGuild(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetGuildResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetGuildInvitesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetGuildInvitesCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildInvitesResponse>)> callback, const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildInvitesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildInvitesResponse>> ChatServiceServiceClient::GetGuildInvites(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetGuildInvitesResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildInvitesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetGuildMembersResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetGuildMembersCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildMembersResponse>)> callback, const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildMembersResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildMembersResponse>> ChatServiceServiceClient::GetGuildMembers(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetGuildMembersResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildMembersResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetGuildChannelsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetGuildChannelsCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildChannelsResponse>)> callback, const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildChannelsResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildChannelsResponse>> ChatServiceServiceClient::GetGuildChannels(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetGuildChannelsResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildChannelsResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetChannelMessagesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetChannelMessagesCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetChannelMessagesResponse>)> callback, const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetChannelMessagesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetChannelMessagesResponse>> ChatServiceServiceClient::GetChannelMessages(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetChannelMessagesResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetChannelMessagesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetMessageResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetMessageCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetMessageResponse>)> callback, const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetMessageResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetMessageResponse>> ChatServiceServiceClient::GetMessage(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetMessageResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetMessageResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetEmotePacksResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetEmotePacksCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetEmotePacksResponse>)> callback, const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetEmotePacksResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetEmotePacksResponse>> ChatServiceServiceClient::GetEmotePacks(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetEmotePacksResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetEmotePacksResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetEmotePackEmotesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetEmotePackEmotesCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetEmotePackEmotesResponse>)> callback, const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetEmotePackEmotesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetEmotePackEmotesResponse>> ChatServiceServiceClient::GetEmotePackEmotes(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetEmotePackEmotesResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetEmotePackEmotesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::UpdateGuildInformationCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::UpdateGuildInformation(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::UpdateChannelInformationCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::UpdateChannelInformation(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::UpdateChannelOrderCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::UpdateChannelOrder(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::UpdateMessageTextCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::UpdateMessageText(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::AddEmoteToPackCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::AddEmoteToPack(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteGuildCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteGuild(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteInviteCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteInvite(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteChannelCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteChannel(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteMessageCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteMessage(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteEmoteFromPackCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteEmoteFromPack(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteEmotePackCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteEmotePack(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DequipEmotePackCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DequipEmotePack(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::JoinGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::JoinGuildCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::JoinGuildResponse>)> callback, const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::JoinGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::JoinGuildResponse>> ChatServiceServiceClient::JoinGuild(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::JoinGuildResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::JoinGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::LeaveGuildCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::LeaveGuild(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::TriggerActionCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::TriggerAction(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::SendMessageResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::SendMessageCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::SendMessageResponse>)> callback, const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::SendMessageResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::SendMessageResponse>> ChatServiceServiceClient::SendMessage(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::SendMessageResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::SendMessageResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::QueryPermissionsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::QueryHasPermissionCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::QueryPermissionsResponse>)> callback, const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::QueryPermissionsResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::QueryPermissionsResponse>> ChatServiceServiceClient::QueryHasPermission(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::QueryPermissionsResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::QueryPermissionsResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::SetPermissionsCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::SetPermissions(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetPermissionsResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetPermissionsCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetPermissionsResponse>)> callback, const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetPermissionsResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetPermissionsResponse>> ChatServiceServiceClient::GetPermissions(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetPermissionsResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetPermissionsResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::MoveRoleResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::MoveRoleCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::MoveRoleResponse>)> callback, const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::MoveRoleResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::MoveRoleResponse>> ChatServiceServiceClient::MoveRole(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::MoveRoleResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::MoveRoleResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetGuildRolesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetGuildRolesCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildRolesResponse>)> callback, const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildRolesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetGuildRolesResponse>> ChatServiceServiceClient::GetGuildRoles(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetGuildRolesResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetGuildRolesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::AddGuildRoleResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::AddGuildRoleCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::AddGuildRoleResponse>)> callback, const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::AddGuildRoleResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::AddGuildRoleResponse>> ChatServiceServiceClient::AddGuildRole(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::AddGuildRoleResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::AddGuildRoleResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::ModifyGuildRoleCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::ModifyGuildRole(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::DeleteGuildRoleCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::DeleteGuildRole(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::ManageUserRolesCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::ManageUserRoles(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetUserRolesResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetUserRolesCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetUserRolesResponse>)> callback, const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserRolesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetUserRolesResponse>> ChatServiceServiceClient::GetUserRoles(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetUserRolesResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserRolesResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetUserResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetUserCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetUserResponse>)> callback, const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetUserResponse>> ChatServiceServiceClient::GetUser(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetUserResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetUserBulkResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetUserBulkCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetUserBulkResponse>)> callback, const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserBulkResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetUserBulkResponse>> ChatServiceServiceClient::GetUserBulk(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetUserBulkResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserBulkResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::GetUserMetadataResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::GetUserMetadataCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::GetUserMetadataResponse>)> callback, const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserMetadataResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::GetUserMetadataResponse>> ChatServiceServiceClient::GetUserMetadata(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::GetUserMetadataResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::GetUserMetadataResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::ProfileUpdateCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::ProfileUpdate(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::TypingCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::Typing(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	protocol::chat::v1::PreviewGuildResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::PreviewGuildCallback(std::function<void(ChatServiceServiceClient::Result<protocol::chat::v1::PreviewGuildResponse>)> callback, const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::PreviewGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<protocol::chat::v1::PreviewGuildResponse>> ChatServiceServiceClient::PreviewGuild(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<protocol::chat::v1::PreviewGuildResponse>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		protocol::chat::v1::PreviewGuildResponse ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::BanUserCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::BanUser(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::KickUserCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::KickUser(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

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

	if (val->error() != QNetworkReply::NoError) {
		return {QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())};
	}

	auto response = val->readAll();

	google::protobuf::Empty ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void ChatServiceServiceClient::UnbanUserCallback(std::function<void(ChatServiceServiceClient::Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
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



	QObject::connect(val, &QNetworkReply::finished, [val, callback]() {
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			callback({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			callback({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		callback({ret});
		return;
	});

}
QFuture<ChatServiceServiceClient::Result<google::protobuf::Empty>> ChatServiceServiceClient::UnbanUser(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers)

{
	QFutureInterface<Result<google::protobuf::Empty>> res;

	std::string strData;
	if (!in.SerializeToString(&strData)) { res.reportResult({QStringLiteral("failed to serialize protobuf")}); return res.future(); }
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
		if (val->error() != QNetworkReply::NoError) {
			val->deleteLater();
			res.reportResult({QStringLiteral("network failure(%1): %2").arg(val->error()).arg(val->errorString())});
			return;
		}
		
		auto response = val->readAll();
		
		google::protobuf::Empty ret;
		if (!ret.ParseFromArray(response.constData(), response.length())) {
			val->deleteLater();
			res.reportResult({QStringLiteral("error parsing response into protobuf")});
			return;
		}
		
		val->deleteLater();
		res.reportResult({ret});
		return;
	});

	return res.future();

}
