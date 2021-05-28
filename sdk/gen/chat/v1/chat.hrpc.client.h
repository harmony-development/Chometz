#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <functional>
#include <variant>
#include "chat/v1/chat.pb.h"
#include <QWebSocket>
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
#include "chat/v1/profile.pb.h"
#include "chat/v1/guilds.pb.h"
#include "chat/v1/channels.pb.h"
#include "chat/v1/messages.pb.h"
#include "chat/v1/emotes.pb.h"
#include "chat/v1/permissions.pb.h"
#include "chat/v1/streaming.pb.h"

class Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream : public QWebSocket {

	Q_OBJECT

	public: Q_SIGNAL void receivedMessage(protocol::chat::v1::Event msg);

	public: Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream(const QString &origin = QString(), QWebSocketProtocol::Version version = QWebSocketProtocol::VersionLatest, QObject *parent = nullptr) : QWebSocket(origin, version, parent)
	{
		connect(this, &QWebSocket::binaryMessageReceived, [=](const QByteArray& msg) {
			qDebug() << "incoming!";
			protocol::chat::v1::Event incoming;

			if (!incoming.ParseFromArray(msg.constData(), msg.length())) {
				return;
			}

			Q_EMIT receivedMessage(incoming);
		});
	}


	public: [[nodiscard]] bool send(const protocol::chat::v1::StreamEventsRequest& in) {
		std::string strData;
		if (!in.SerializeToString(&strData)) {
			return false;
		}
		QByteArray data = QByteArray::fromStdString(strData);

		auto count = sendBinaryMessage(data);
		return count == data.length();
	}
};

class ChatServiceServiceClient {
	QString host;
	bool secure;
	QString httpProtocol() const { return secure ? QStringLiteral("https://") : QStringLiteral("http://"); }
	QString wsProtocol() const { return secure ? QStringLiteral("wss://") : QStringLiteral("ws://"); }
	public: explicit ChatServiceServiceClient(const QString& host, bool secure) : host(host), secure(secure) {}
public:
	QMap<QByteArray,QString> universalHeaders;
	template<typename T> using Result = std::variant<T, QString>;
	[[ nodiscard ]] Result<protocol::chat::v1::CreateGuildResponse> CreateGuildSync(const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateGuild(std::function<void(Result<protocol::chat::v1::CreateGuildResponse>)> callback, const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateInviteResponse> CreateInviteSync(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateInvite(std::function<void(Result<protocol::chat::v1::CreateInviteResponse>)> callback, const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateChannelResponse> CreateChannelSync(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateChannel(std::function<void(Result<protocol::chat::v1::CreateChannelResponse>)> callback, const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateEmotePackResponse> CreateEmotePackSync(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateEmotePack(std::function<void(Result<protocol::chat::v1::CreateEmotePackResponse>)> callback, const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildListResponse> GetGuildListSync(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildList(std::function<void(Result<protocol::chat::v1::GetGuildListResponse>)> callback, const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::AddGuildToGuildListResponse> AddGuildToGuildListSync(const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	void AddGuildToGuildList(std::function<void(Result<protocol::chat::v1::AddGuildToGuildListResponse>)> callback, const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::RemoveGuildFromGuildListResponse> RemoveGuildFromGuildListSync(const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	void RemoveGuildFromGuildList(std::function<void(Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>)> callback, const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildResponse> GetGuildSync(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuild(std::function<void(Result<protocol::chat::v1::GetGuildResponse>)> callback, const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildInvitesResponse> GetGuildInvitesSync(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildInvites(std::function<void(Result<protocol::chat::v1::GetGuildInvitesResponse>)> callback, const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildMembersResponse> GetGuildMembersSync(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildMembers(std::function<void(Result<protocol::chat::v1::GetGuildMembersResponse>)> callback, const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildChannelsResponse> GetGuildChannelsSync(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildChannels(std::function<void(Result<protocol::chat::v1::GetGuildChannelsResponse>)> callback, const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetChannelMessagesResponse> GetChannelMessagesSync(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetChannelMessages(std::function<void(Result<protocol::chat::v1::GetChannelMessagesResponse>)> callback, const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetMessageResponse> GetMessageSync(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	void GetMessage(std::function<void(Result<protocol::chat::v1::GetMessageResponse>)> callback, const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetEmotePacksResponse> GetEmotePacksSync(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	void GetEmotePacks(std::function<void(Result<protocol::chat::v1::GetEmotePacksResponse>)> callback, const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetEmotePackEmotesResponse> GetEmotePackEmotesSync(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetEmotePackEmotes(std::function<void(Result<protocol::chat::v1::GetEmotePackEmotesResponse>)> callback, const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateGuildInformationSync(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateGuildInformation(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateChannelInformationSync(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateChannelInformation(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateChannelOrderSync(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateChannelOrder(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateMessageTextSync(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateMessageText(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> AddEmoteToPackSync(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	void AddEmoteToPack(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteGuildSync(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteGuild(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteInviteSync(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteInvite(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteChannelSync(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteChannel(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteMessageSync(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteMessage(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteEmoteFromPackSync(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteEmoteFromPack(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteEmotePackSync(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteEmotePack(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DequipEmotePackSync(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	void DequipEmotePack(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::JoinGuildResponse> JoinGuildSync(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void JoinGuild(std::function<void(Result<protocol::chat::v1::JoinGuildResponse>)> callback, const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> LeaveGuildSync(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void LeaveGuild(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> TriggerActionSync(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	void TriggerAction(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::SendMessageResponse> SendMessageSync(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	void SendMessage(std::function<void(Result<protocol::chat::v1::SendMessageResponse>)> callback, const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::QueryPermissionsResponse> QueryHasPermissionSync(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	void QueryHasPermission(std::function<void(Result<protocol::chat::v1::QueryPermissionsResponse>)> callback, const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> SetPermissionsSync(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	void SetPermissions(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetPermissionsResponse> GetPermissionsSync(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	void GetPermissions(std::function<void(Result<protocol::chat::v1::GetPermissionsResponse>)> callback, const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::MoveRoleResponse> MoveRoleSync(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void MoveRole(std::function<void(Result<protocol::chat::v1::MoveRoleResponse>)> callback, const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildRolesResponse> GetGuildRolesSync(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildRoles(std::function<void(Result<protocol::chat::v1::GetGuildRolesResponse>)> callback, const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::AddGuildRoleResponse> AddGuildRoleSync(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void AddGuildRole(std::function<void(Result<protocol::chat::v1::AddGuildRoleResponse>)> callback, const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ModifyGuildRoleSync(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void ModifyGuildRole(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteGuildRoleSync(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteGuildRole(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ManageUserRolesSync(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	void ManageUserRoles(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserRolesResponse> GetUserRolesSync(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserRoles(std::function<void(Result<protocol::chat::v1::GetUserRolesResponse>)> callback, const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream* StreamEvents(QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserResponse> GetUserSync(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUser(std::function<void(Result<protocol::chat::v1::GetUserResponse>)> callback, const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserBulkResponse> GetUserBulkSync(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserBulk(std::function<void(Result<protocol::chat::v1::GetUserBulkResponse>)> callback, const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserMetadataResponse> GetUserMetadataSync(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserMetadata(std::function<void(Result<protocol::chat::v1::GetUserMetadataResponse>)> callback, const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ProfileUpdateSync(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	void ProfileUpdate(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> TypingSync(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	void Typing(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::PreviewGuildResponse> PreviewGuildSync(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void PreviewGuild(std::function<void(Result<protocol::chat::v1::PreviewGuildResponse>)> callback, const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> BanUserSync(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	void BanUser(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> KickUserSync(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	void KickUser(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UnbanUserSync(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
	void UnbanUser(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
};
