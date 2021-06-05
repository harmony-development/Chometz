#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QFuture>
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
	void CreateGuildCallback(std::function<void(Result<protocol::chat::v1::CreateGuildResponse>)> callback, const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::CreateGuildResponse>> CreateGuild(const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateInviteResponse> CreateInviteSync(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateInviteCallback(std::function<void(Result<protocol::chat::v1::CreateInviteResponse>)> callback, const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::CreateInviteResponse>> CreateInvite(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateChannelResponse> CreateChannelSync(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateChannelCallback(std::function<void(Result<protocol::chat::v1::CreateChannelResponse>)> callback, const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::CreateChannelResponse>> CreateChannel(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateEmotePackResponse> CreateEmotePackSync(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	void CreateEmotePackCallback(std::function<void(Result<protocol::chat::v1::CreateEmotePackResponse>)> callback, const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::CreateEmotePackResponse>> CreateEmotePack(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildListResponse> GetGuildListSync(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildListCallback(std::function<void(Result<protocol::chat::v1::GetGuildListResponse>)> callback, const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetGuildListResponse>> GetGuildList(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::AddGuildToGuildListResponse> AddGuildToGuildListSync(const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	void AddGuildToGuildListCallback(std::function<void(Result<protocol::chat::v1::AddGuildToGuildListResponse>)> callback, const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::AddGuildToGuildListResponse>> AddGuildToGuildList(const protocol::chat::v1::AddGuildToGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::RemoveGuildFromGuildListResponse> RemoveGuildFromGuildListSync(const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	void RemoveGuildFromGuildListCallback(std::function<void(Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>)> callback, const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::RemoveGuildFromGuildListResponse>> RemoveGuildFromGuildList(const protocol::chat::v1::RemoveGuildFromGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildResponse> GetGuildSync(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildCallback(std::function<void(Result<protocol::chat::v1::GetGuildResponse>)> callback, const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetGuildResponse>> GetGuild(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildInvitesResponse> GetGuildInvitesSync(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildInvitesCallback(std::function<void(Result<protocol::chat::v1::GetGuildInvitesResponse>)> callback, const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetGuildInvitesResponse>> GetGuildInvites(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildMembersResponse> GetGuildMembersSync(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildMembersCallback(std::function<void(Result<protocol::chat::v1::GetGuildMembersResponse>)> callback, const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetGuildMembersResponse>> GetGuildMembers(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildChannelsResponse> GetGuildChannelsSync(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildChannelsCallback(std::function<void(Result<protocol::chat::v1::GetGuildChannelsResponse>)> callback, const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetGuildChannelsResponse>> GetGuildChannels(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetChannelMessagesResponse> GetChannelMessagesSync(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetChannelMessagesCallback(std::function<void(Result<protocol::chat::v1::GetChannelMessagesResponse>)> callback, const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetChannelMessagesResponse>> GetChannelMessages(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetMessageResponse> GetMessageSync(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	void GetMessageCallback(std::function<void(Result<protocol::chat::v1::GetMessageResponse>)> callback, const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetMessageResponse>> GetMessage(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetEmotePacksResponse> GetEmotePacksSync(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	void GetEmotePacksCallback(std::function<void(Result<protocol::chat::v1::GetEmotePacksResponse>)> callback, const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetEmotePacksResponse>> GetEmotePacks(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetEmotePackEmotesResponse> GetEmotePackEmotesSync(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetEmotePackEmotesCallback(std::function<void(Result<protocol::chat::v1::GetEmotePackEmotesResponse>)> callback, const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetEmotePackEmotesResponse>> GetEmotePackEmotes(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateGuildInformationSync(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateGuildInformationCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> UpdateGuildInformation(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateChannelInformationSync(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateChannelInformationCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> UpdateChannelInformation(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateChannelOrderSync(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateChannelOrderCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> UpdateChannelOrder(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateMessageTextSync(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	void UpdateMessageTextCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> UpdateMessageText(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> AddEmoteToPackSync(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	void AddEmoteToPackCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> AddEmoteToPack(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteGuildSync(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteGuildCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteGuild(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteInviteSync(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteInviteCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteInvite(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteChannelSync(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteChannelCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteChannel(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteMessageSync(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteMessageCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteMessage(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteEmoteFromPackSync(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteEmoteFromPackCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteEmoteFromPack(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteEmotePackSync(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteEmotePackCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteEmotePack(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DequipEmotePackSync(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	void DequipEmotePackCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DequipEmotePack(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::JoinGuildResponse> JoinGuildSync(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void JoinGuildCallback(std::function<void(Result<protocol::chat::v1::JoinGuildResponse>)> callback, const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::JoinGuildResponse>> JoinGuild(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> LeaveGuildSync(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void LeaveGuildCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> LeaveGuild(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> TriggerActionSync(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	void TriggerActionCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> TriggerAction(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::SendMessageResponse> SendMessageSync(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	void SendMessageCallback(std::function<void(Result<protocol::chat::v1::SendMessageResponse>)> callback, const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::SendMessageResponse>> SendMessage(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::QueryPermissionsResponse> QueryHasPermissionSync(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	void QueryHasPermissionCallback(std::function<void(Result<protocol::chat::v1::QueryPermissionsResponse>)> callback, const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::QueryPermissionsResponse>> QueryHasPermission(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> SetPermissionsSync(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	void SetPermissionsCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> SetPermissions(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetPermissionsResponse> GetPermissionsSync(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	void GetPermissionsCallback(std::function<void(Result<protocol::chat::v1::GetPermissionsResponse>)> callback, const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetPermissionsResponse>> GetPermissions(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::MoveRoleResponse> MoveRoleSync(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void MoveRoleCallback(std::function<void(Result<protocol::chat::v1::MoveRoleResponse>)> callback, const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::MoveRoleResponse>> MoveRole(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildRolesResponse> GetGuildRolesSync(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetGuildRolesCallback(std::function<void(Result<protocol::chat::v1::GetGuildRolesResponse>)> callback, const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetGuildRolesResponse>> GetGuildRoles(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::AddGuildRoleResponse> AddGuildRoleSync(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void AddGuildRoleCallback(std::function<void(Result<protocol::chat::v1::AddGuildRoleResponse>)> callback, const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::AddGuildRoleResponse>> AddGuildRole(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ModifyGuildRoleSync(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void ModifyGuildRoleCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> ModifyGuildRole(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteGuildRoleSync(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	void DeleteGuildRoleCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> DeleteGuildRole(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ManageUserRolesSync(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	void ManageUserRolesCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> ManageUserRoles(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserRolesResponse> GetUserRolesSync(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserRolesCallback(std::function<void(Result<protocol::chat::v1::GetUserRolesResponse>)> callback, const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetUserRolesResponse>> GetUserRoles(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream* StreamEvents(QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserResponse> GetUserSync(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserCallback(std::function<void(Result<protocol::chat::v1::GetUserResponse>)> callback, const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetUserResponse>> GetUser(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserBulkResponse> GetUserBulkSync(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserBulkCallback(std::function<void(Result<protocol::chat::v1::GetUserBulkResponse>)> callback, const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetUserBulkResponse>> GetUserBulk(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserMetadataResponse> GetUserMetadataSync(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	void GetUserMetadataCallback(std::function<void(Result<protocol::chat::v1::GetUserMetadataResponse>)> callback, const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::GetUserMetadataResponse>> GetUserMetadata(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ProfileUpdateSync(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	void ProfileUpdateCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> ProfileUpdate(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> TypingSync(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	void TypingCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> Typing(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::PreviewGuildResponse> PreviewGuildSync(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	void PreviewGuildCallback(std::function<void(Result<protocol::chat::v1::PreviewGuildResponse>)> callback, const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<protocol::chat::v1::PreviewGuildResponse>> PreviewGuild(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> BanUserSync(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	void BanUserCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> BanUser(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> KickUserSync(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	void KickUserCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> KickUser(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UnbanUserSync(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
	void UnbanUserCallback(std::function<void(Result<google::protobuf::Empty>)> callback, const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] QFuture<Result<google::protobuf::Empty>> UnbanUser(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
};
