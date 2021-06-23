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
#include "chat/v1/chat.pb.h"
#include "chat/v1/chat.hrpc.types.h"
#include <QWebSocket>
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/timestamp.hrpc.types.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/empty.hrpc.types.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/any.hrpc.types.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/descriptor.hrpc.types.h"
#include "harmonytypes/v1/types.pb.h"
#include "harmonytypes/v1/types.hrpc.types.h"
#include "chat/v1/profile.pb.h"
#include "chat/v1/profile.hrpc.types.h"
#include "chat/v1/guilds.pb.h"
#include "chat/v1/guilds.hrpc.types.h"
#include "chat/v1/channels.pb.h"
#include "chat/v1/channels.hrpc.types.h"
#include "chat/v1/messages.pb.h"
#include "chat/v1/messages.hrpc.types.h"
#include "chat/v1/emotes.pb.h"
#include "chat/v1/emotes.hrpc.types.h"
#include "chat/v1/permissions.pb.h"
#include "chat/v1/permissions.hrpc.types.h"
#include "chat/v1/streaming.pb.h"
#include "chat/v1/streaming.hrpc.types.h"

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
	[[ nodiscard ]] FutureResult<protocol::chat::v1::CreateGuildResponse, QString> CreateGuild(const protocol::chat::v1::CreateGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateInviteResponse> CreateInviteSync(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::CreateInviteResponse, QString> CreateInvite(const protocol::chat::v1::CreateInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateChannelResponse> CreateChannelSync(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::CreateChannelResponse, QString> CreateChannel(const protocol::chat::v1::CreateChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::CreateEmotePackResponse> CreateEmotePackSync(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::CreateEmotePackResponse, QString> CreateEmotePack(const protocol::chat::v1::CreateEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildListResponse> GetGuildListSync(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetGuildListResponse, QString> GetGuildList(const protocol::chat::v1::GetGuildListRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildResponse> GetGuildSync(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetGuildResponse, QString> GetGuild(const protocol::chat::v1::GetGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildInvitesResponse> GetGuildInvitesSync(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetGuildInvitesResponse, QString> GetGuildInvites(const protocol::chat::v1::GetGuildInvitesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildMembersResponse> GetGuildMembersSync(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetGuildMembersResponse, QString> GetGuildMembers(const protocol::chat::v1::GetGuildMembersRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildChannelsResponse> GetGuildChannelsSync(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetGuildChannelsResponse, QString> GetGuildChannels(const protocol::chat::v1::GetGuildChannelsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetChannelMessagesResponse> GetChannelMessagesSync(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetChannelMessagesResponse, QString> GetChannelMessages(const protocol::chat::v1::GetChannelMessagesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetMessageResponse> GetMessageSync(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetMessageResponse, QString> GetMessage(const protocol::chat::v1::GetMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetEmotePacksResponse> GetEmotePacksSync(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetEmotePacksResponse, QString> GetEmotePacks(const protocol::chat::v1::GetEmotePacksRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetEmotePackEmotesResponse> GetEmotePackEmotesSync(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetEmotePackEmotesResponse, QString> GetEmotePackEmotes(const protocol::chat::v1::GetEmotePackEmotesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateGuildInformationSync(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> UpdateGuildInformation(const protocol::chat::v1::UpdateGuildInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateChannelInformationSync(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> UpdateChannelInformation(const protocol::chat::v1::UpdateChannelInformationRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateChannelOrderSync(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> UpdateChannelOrder(const protocol::chat::v1::UpdateChannelOrderRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UpdateMessageTextSync(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> UpdateMessageText(const protocol::chat::v1::UpdateMessageTextRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> AddEmoteToPackSync(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> AddEmoteToPack(const protocol::chat::v1::AddEmoteToPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteGuildSync(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteGuild(const protocol::chat::v1::DeleteGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteInviteSync(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteInvite(const protocol::chat::v1::DeleteInviteRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteChannelSync(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteChannel(const protocol::chat::v1::DeleteChannelRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteMessageSync(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteMessage(const protocol::chat::v1::DeleteMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteEmoteFromPackSync(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteEmoteFromPack(const protocol::chat::v1::DeleteEmoteFromPackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteEmotePackSync(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteEmotePack(const protocol::chat::v1::DeleteEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DequipEmotePackSync(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DequipEmotePack(const protocol::chat::v1::DequipEmotePackRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::JoinGuildResponse> JoinGuildSync(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::JoinGuildResponse, QString> JoinGuild(const protocol::chat::v1::JoinGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> LeaveGuildSync(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> LeaveGuild(const protocol::chat::v1::LeaveGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> TriggerActionSync(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> TriggerAction(const protocol::chat::v1::TriggerActionRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::SendMessageResponse> SendMessageSync(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::SendMessageResponse, QString> SendMessage(const protocol::chat::v1::SendMessageRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::QueryPermissionsResponse> QueryHasPermissionSync(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::QueryPermissionsResponse, QString> QueryHasPermission(const protocol::chat::v1::QueryPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> SetPermissionsSync(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> SetPermissions(const protocol::chat::v1::SetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetPermissionsResponse> GetPermissionsSync(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetPermissionsResponse, QString> GetPermissions(const protocol::chat::v1::GetPermissionsRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::MoveRoleResponse> MoveRoleSync(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::MoveRoleResponse, QString> MoveRole(const protocol::chat::v1::MoveRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetGuildRolesResponse> GetGuildRolesSync(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetGuildRolesResponse, QString> GetGuildRoles(const protocol::chat::v1::GetGuildRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::AddGuildRoleResponse> AddGuildRoleSync(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::AddGuildRoleResponse, QString> AddGuildRole(const protocol::chat::v1::AddGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ModifyGuildRoleSync(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> ModifyGuildRole(const protocol::chat::v1::ModifyGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> DeleteGuildRoleSync(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> DeleteGuildRole(const protocol::chat::v1::DeleteGuildRoleRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ManageUserRolesSync(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> ManageUserRoles(const protocol::chat::v1::ManageUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserRolesResponse> GetUserRolesSync(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetUserRolesResponse, QString> GetUserRoles(const protocol::chat::v1::GetUserRolesRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Receive__protocol_chat_v1_Event__Send__protocol_chat_v1_StreamEventsRequest__Stream* StreamEvents(QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserResponse> GetUserSync(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetUserResponse, QString> GetUser(const protocol::chat::v1::GetUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserBulkResponse> GetUserBulkSync(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetUserBulkResponse, QString> GetUserBulk(const protocol::chat::v1::GetUserBulkRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::GetUserMetadataResponse> GetUserMetadataSync(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::GetUserMetadataResponse, QString> GetUserMetadata(const protocol::chat::v1::GetUserMetadataRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> ProfileUpdateSync(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> ProfileUpdate(const protocol::chat::v1::ProfileUpdateRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> TypingSync(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> Typing(const protocol::chat::v1::TypingRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<protocol::chat::v1::PreviewGuildResponse> PreviewGuildSync(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<protocol::chat::v1::PreviewGuildResponse, QString> PreviewGuild(const protocol::chat::v1::PreviewGuildRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> BanUserSync(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> BanUser(const protocol::chat::v1::BanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> KickUserSync(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> KickUser(const protocol::chat::v1::KickUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] Result<google::protobuf::Empty> UnbanUserSync(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
	[[ nodiscard ]] FutureResult<google::protobuf::Empty, QString> UnbanUser(const protocol::chat::v1::UnbanUserRequest& in, QMap<QByteArray,QString> headers = {});
};
