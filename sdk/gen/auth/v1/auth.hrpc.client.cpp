#include "auth/v1/auth.hrpc.client.h"
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
auto AuthServiceServiceClient::FederateSync(const protocol::auth::v1::FederateRequest& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<protocol::auth::v1::FederateReply>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/Federate"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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

	protocol::auth::v1::FederateReply ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void AuthServiceServiceClient::Federate(std::function<void(AuthServiceServiceClient::Result<protocol::auth::v1::FederateReply>)> callback, const protocol::auth::v1::FederateRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/Federate"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
		
		protocol::auth::v1::FederateReply ret;
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
auto AuthServiceServiceClient::LoginFederatedSync(const protocol::auth::v1::LoginFederatedRequest& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<protocol::auth::v1::Session>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/LoginFederated"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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

	protocol::auth::v1::Session ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void AuthServiceServiceClient::LoginFederated(std::function<void(AuthServiceServiceClient::Result<protocol::auth::v1::Session>)> callback, const protocol::auth::v1::LoginFederatedRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/LoginFederated"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
		
		protocol::auth::v1::Session ret;
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
auto AuthServiceServiceClient::KeySync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<protocol::auth::v1::KeyReply>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/Key"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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

	protocol::auth::v1::KeyReply ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void AuthServiceServiceClient::Key(std::function<void(AuthServiceServiceClient::Result<protocol::auth::v1::KeyReply>)> callback, const google::protobuf::Empty& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/Key"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
		
		protocol::auth::v1::KeyReply ret;
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
auto AuthServiceServiceClient::BeginAuthSync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<protocol::auth::v1::BeginAuthResponse>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/BeginAuth"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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

	protocol::auth::v1::BeginAuthResponse ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void AuthServiceServiceClient::BeginAuth(std::function<void(AuthServiceServiceClient::Result<protocol::auth::v1::BeginAuthResponse>)> callback, const google::protobuf::Empty& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/BeginAuth"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
		
		protocol::auth::v1::BeginAuthResponse ret;
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
auto AuthServiceServiceClient::NextStepSync(const protocol::auth::v1::NextStepRequest& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<protocol::auth::v1::AuthStep>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/NextStep"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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

	protocol::auth::v1::AuthStep ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void AuthServiceServiceClient::NextStep(std::function<void(AuthServiceServiceClient::Result<protocol::auth::v1::AuthStep>)> callback, const protocol::auth::v1::NextStepRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/NextStep"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
		
		protocol::auth::v1::AuthStep ret;
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
auto AuthServiceServiceClient::StepBackSync(const protocol::auth::v1::StepBackRequest& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<protocol::auth::v1::AuthStep>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/StepBack"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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

	protocol::auth::v1::AuthStep ret;
	if (!ret.ParseFromArray(response.constData(), response.length())) {
		return {QStringLiteral("error parsing response into protobuf")};
	}

	return {ret};

}
void AuthServiceServiceClient::StepBack(std::function<void(AuthServiceServiceClient::Result<protocol::auth::v1::AuthStep>)> callback, const protocol::auth::v1::StepBackRequest& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/StepBack"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
		
		protocol::auth::v1::AuthStep ret;
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
auto AuthServiceServiceClient::StreamSteps(const protocol::auth::v1::StreamStepsRequest& in, QMap<QByteArray,QString> headers) -> Receive__protocol_auth_v1_AuthStep__Stream*
{
auto url = QUrl(wsProtocol()+host); url.setPath(QStringLiteral("/protocol.auth.v1.AuthService/StreamSteps")); auto req = QNetworkRequest(url);

					for (const auto& item : universalHeaders.keys()) {
						req.setRawHeader(item, universalHeaders[item].toLocal8Bit());
					}
					for (const auto& item : headers.keys()) {
						req.setRawHeader(item, headers[item].toLocal8Bit());
					}
				
	auto sock = new Receive__protocol_auth_v1_AuthStep__Stream();
	std::string strData;
	if (!in.SerializeToString(&strData)) { return nullptr; }
	QByteArray data = QByteArray::fromStdString(strData);
	sock->open(req);
	QObject::connect(sock, &QWebSocket::connected, [=]() { sock->sendBinaryMessage(data); });
	return sock;
}
auto AuthServiceServiceClient::CheckLoggedInSync(const google::protobuf::Empty& in, QMap<QByteArray,QString> headers) -> AuthServiceServiceClient::Result<google::protobuf::Empty>

{
	std::string strData;
	if (!in.SerializeToString(&strData)) { return {QStringLiteral("failed to serialize protobuf")}; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/CheckLoggedIn"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
void AuthServiceServiceClient::CheckLoggedIn(std::function<void(AuthServiceServiceClient::Result<google::protobuf::Empty>)> callback, const google::protobuf::Empty& in, QMap<QByteArray,QString> headers)

{
	if (callback == nullptr) {
		callback = [](auto) {};
	}
	std::string strData;
	if (!in.SerializeToString(&strData)) { callback({QStringLiteral("failed to serialize protobuf")}); return; }
	QByteArray data = QByteArray::fromStdString(strData);



	initialiseGlobalNam(secure, host);

	QUrl serviceURL = QUrl(httpProtocol()+host);
	serviceURL.setPath(QStringLiteral("/protocol.auth.v1.AuthService/CheckLoggedIn"));

	QNetworkRequest req(serviceURL);
	for (const auto& item : universalHeaders.keys()) {
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
