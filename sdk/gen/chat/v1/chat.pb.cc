// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: chat/v1/chat.proto

#include "chat/v1/chat.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace protocol {
namespace chat {
namespace v1 {
}  // namespace v1
}  // namespace chat
}  // namespace protocol
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_chat_2fv1_2fchat_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_chat_2fv1_2fchat_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_chat_2fv1_2fchat_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_chat_2fv1_2fchat_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_chat_2fv1_2fchat_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022chat/v1/chat.proto\022\020protocol.chat.v1\032\033"
  "google/protobuf/empty.proto\032\033harmonytype"
  "s/v1/types.proto\032\025chat/v1/profile.proto\032"
  "\024chat/v1/guilds.proto\032\026chat/v1/channels."
  "proto\032\026chat/v1/messages.proto\032\024chat/v1/e"
  "motes.proto\032\031chat/v1/permissions.proto\032\027"
  "chat/v1/streaming.proto2\311,\n\013ChatService\022"
  "f\n\013CreateGuild\022$.protocol.chat.v1.Create"
  "GuildRequest\032%.protocol.chat.v1.CreateGu"
  "ildResponse\"\n\232D\002\010\001\232D\002\032\000\022~\n\014CreateInvite\022"
  "%.protocol.chat.v1.CreateInviteRequest\032&"
  ".protocol.chat.v1.CreateInviteResponse\"\037"
  "\232D\002\010\001\232D\027\032\025invites.manage.create\022\202\001\n\rCrea"
  "teChannel\022&.protocol.chat.v1.CreateChann"
  "elRequest\032\'.protocol.chat.v1.CreateChann"
  "elResponse\" \232D\002\010\001\232D\030\032\026channels.manage.cr"
  "eate\022m\n\017CreateEmotePack\022(.protocol.chat."
  "v1.CreateEmotePackRequest\032).protocol.cha"
  "t.v1.CreateEmotePackResponse\"\005\232D\002\010\001\022d\n\014G"
  "etGuildList\022%.protocol.chat.v1.GetGuildL"
  "istRequest\032&.protocol.chat.v1.GetGuildLi"
  "stResponse\"\005\232D\002\010\001\022X\n\010GetGuild\022!.protocol"
  ".chat.v1.GetGuildRequest\032\".protocol.chat"
  ".v1.GetGuildResponse\"\005\232D\002\010\001\022~\n\017GetGuildI"
  "nvites\022(.protocol.chat.v1.GetGuildInvite"
  "sRequest\032).protocol.chat.v1.GetGuildInvi"
  "tesResponse\"\026\232D\002\010\001\232D\016\032\014invites.view\022m\n\017G"
  "etGuildMembers\022(.protocol.chat.v1.GetGui"
  "ldMembersRequest\032).protocol.chat.v1.GetG"
  "uildMembersResponse\"\005\232D\002\010\001\022p\n\020GetGuildCh"
  "annels\022).protocol.chat.v1.GetGuildChanne"
  "lsRequest\032*.protocol.chat.v1.GetGuildCha"
  "nnelsResponse\"\005\232D\002\010\001\022\210\001\n\022GetChannelMessa"
  "ges\022+.protocol.chat.v1.GetChannelMessage"
  "sRequest\032,.protocol.chat.v1.GetChannelMe"
  "ssagesResponse\"\027\232D\002\010\001\232D\017\032\rmessages.view\022"
  "p\n\nGetMessage\022#.protocol.chat.v1.GetMess"
  "ageRequest\032$.protocol.chat.v1.GetMessage"
  "Response\"\027\232D\002\010\001\232D\017\032\rmessages.view\022g\n\rGet"
  "EmotePacks\022&.protocol.chat.v1.GetEmotePa"
  "cksRequest\032\'.protocol.chat.v1.GetEmotePa"
  "cksResponse\"\005\232D\002\010\001\022v\n\022GetEmotePackEmotes"
  "\022+.protocol.chat.v1.GetEmotePackEmotesRe"
  "quest\032,.protocol.chat.v1.GetEmotePackEmo"
  "tesResponse\"\005\232D\002\010\001\022\214\001\n\026UpdateGuildInform"
  "ation\022/.protocol.chat.v1.UpdateGuildInfo"
  "rmationRequest\032\026.google.protobuf.Empty\")"
  "\232D\002\010\001\232D!\032\037guild.manage.change-informatio"
  "n\022\223\001\n\030UpdateChannelInformation\0221.protoco"
  "l.chat.v1.UpdateChannelInformationReques"
  "t\032\026.google.protobuf.Empty\",\232D\002\010\001\232D$\032\"cha"
  "nnels.manage.change-information\022y\n\022Updat"
  "eChannelOrder\022+.protocol.chat.v1.UpdateC"
  "hannelOrderRequest\032\026.google.protobuf.Emp"
  "ty\"\036\232D\002\010\001\232D\026\032\024channels.manage.move\022\177\n\025Up"
  "dateAllChannelOrder\022..protocol.chat.v1.U"
  "pdateAllChannelOrderRequest\032\026.google.pro"
  "tobuf.Empty\"\036\232D\002\010\001\232D\026\032\024channels.manage.m"
  "ove\022p\n\021UpdateMessageText\022*.protocol.chat"
  ".v1.UpdateMessageTextRequest\032\026.google.pr"
  "otobuf.Empty\"\027\232D\002\010\001\232D\017\032\rmessages.send\022X\n"
  "\016AddEmoteToPack\022\'.protocol.chat.v1.AddEm"
  "oteToPackRequest\032\026.google.protobuf.Empty"
  "\"\005\232D\002\010\001\022j\n\013DeleteGuild\022$.protocol.chat.v"
  "1.DeleteGuildRequest\032\026.google.protobuf.E"
  "mpty\"\035\232D\002\010\001\232D\025\032\023guild.manage.delete\022n\n\014D"
  "eleteInvite\022%.protocol.chat.v1.DeleteInv"
  "iteRequest\032\026.google.protobuf.Empty\"\037\232D\002\010"
  "\001\232D\027\032\025invites.manage.delete\022q\n\rDeleteCha"
  "nnel\022&.protocol.chat.v1.DeleteChannelReq"
  "uest\032\026.google.protobuf.Empty\" \232D\002\010\001\232D\030\032\026"
  "channels.manage.delete\022V\n\rDeleteMessage\022"
  "&.protocol.chat.v1.DeleteMessageRequest\032"
  "\026.google.protobuf.Empty\"\005\232D\002\010\001\022b\n\023Delete"
  "EmoteFromPack\022,.protocol.chat.v1.DeleteE"
  "moteFromPackRequest\032\026.google.protobuf.Em"
  "pty\"\005\232D\002\010\001\022Z\n\017DeleteEmotePack\022(.protocol"
  ".chat.v1.DeleteEmotePackRequest\032\026.google"
  ".protobuf.Empty\"\005\232D\002\010\001\022Z\n\017DequipEmotePac"
  "k\022(.protocol.chat.v1.DequipEmotePackRequ"
  "est\032\026.google.protobuf.Empty\"\005\232D\002\010\001\022X\n\016Eq"
  "uipEmotePack\022\'.protocol.chat.v1.EquipEmo"
  "tePackRequest\032\026.google.protobuf.Empty\"\005\232"
  "D\002\010\001\022[\n\tJoinGuild\022\".protocol.chat.v1.Joi"
  "nGuildRequest\032#.protocol.chat.v1.JoinGui"
  "ldResponse\"\005\232D\002\010\001\022P\n\nLeaveGuild\022#.protoc"
  "ol.chat.v1.LeaveGuildRequest\032\026.google.pr"
  "otobuf.Empty\"\005\232D\002\010\001\022j\n\rTriggerAction\022&.p"
  "rotocol.chat.v1.TriggerActionRequest\032\026.g"
  "oogle.protobuf.Empty\"\031\232D\002\010\001\232D\021\032\017actions."
  "trigger\022s\n\013SendMessage\022$.protocol.chat.v"
  "1.SendMessageRequest\032%.protocol.chat.v1."
  "SendMessageResponse\"\027\232D\002\010\001\232D\017\032\rmessages."
  "send\022r\n\022QueryHasPermission\022).protocol.ch"
  "at.v1.QueryPermissionsRequest\032*.protocol"
  ".chat.v1.QueryPermissionsResponse\"\005\232D\002\010\001"
  "\022\201\001\n\027BatchQueryHasPermission\022..protocol."
  "chat.v1.BatchQueryPermissionsRequest\032/.p"
  "rotocol.chat.v1.BatchQueryPermissionsRes"
  "ponse\"\005\232D\002\010\001\022s\n\016SetPermissions\022\'.protoco"
  "l.chat.v1.SetPermissionsRequest\032\026.google"
  ".protobuf.Empty\" \232D\002\010\001\232D\030\032\026permissions.m"
  "anage.set\022\205\001\n\016GetPermissions\022\'.protocol."
  "chat.v1.GetPermissionsRequest\032(.protocol"
  ".chat.v1.GetPermissionsResponse\" \232D\002\010\001\232D"
  "\030\032\026permissions.manage.get\022i\n\010MoveRole\022!."
  "protocol.chat.v1.MoveRoleRequest\032\".proto"
  "col.chat.v1.MoveRoleResponse\"\026\232D\002\010\001\232D\016\032\014"
  "roles.manage\022u\n\rGetGuildRoles\022&.protocol"
  ".chat.v1.GetGuildRolesRequest\032\'.protocol"
  ".chat.v1.GetGuildRolesResponse\"\023\232D\002\010\001\232D\013"
  "\032\troles.get\022u\n\014AddGuildRole\022%.protocol.c"
  "hat.v1.AddGuildRoleRequest\032&.protocol.ch"
  "at.v1.AddGuildRoleResponse\"\026\232D\002\010\001\232D\016\032\014ro"
  "les.manage\022k\n\017ModifyGuildRole\022(.protocol"
  ".chat.v1.ModifyGuildRoleRequest\032\026.google"
  ".protobuf.Empty\"\026\232D\002\010\001\232D\016\032\014roles.manage\022"
  "k\n\017DeleteGuildRole\022(.protocol.chat.v1.De"
  "leteGuildRoleRequest\032\026.google.protobuf.E"
  "mpty\"\026\232D\002\010\001\232D\016\032\014roles.manage\022p\n\017ManageUs"
  "erRoles\022(.protocol.chat.v1.ManageUserRol"
  "esRequest\032\026.google.protobuf.Empty\"\033\232D\002\010\001"
  "\232D\023\032\021roles.user.manage\022d\n\014GetUserRoles\022%"
  ".protocol.chat.v1.GetUserRolesRequest\032&."
  "protocol.chat.v1.GetUserRolesResponse\"\005\232"
  "D\002\010\001\022Y\n\014StreamEvents\022%.protocol.chat.v1."
  "StreamEventsRequest\032\027.protocol.chat.v1.E"
  "vent\"\005\232D\002\010\001(\0010\001\022U\n\007GetUser\022 .protocol.ch"
  "at.v1.GetUserRequest\032!.protocol.chat.v1."
  "GetUserResponse\"\005\232D\002\010\001\022a\n\013GetUserBulk\022$."
  "protocol.chat.v1.GetUserBulkRequest\032%.pr"
  "otocol.chat.v1.GetUserBulkResponse\"\005\232D\002\010"
  "\001\022m\n\017GetUserMetadata\022(.protocol.chat.v1."
  "GetUserMetadataRequest\032).protocol.chat.v"
  "1.GetUserMetadataResponse\"\005\232D\002\010\001\022V\n\rProf"
  "ileUpdate\022&.protocol.chat.v1.ProfileUpda"
  "teRequest\032\026.google.protobuf.Empty\"\005\232D\002\010\001"
  "\022Z\n\006Typing\022\037.protocol.chat.v1.TypingRequ"
  "est\032\026.google.protobuf.Empty\"\027\232D\002\010\001\232D\017\032\rm"
  "essages.send\022d\n\014PreviewGuild\022%.protocol."
  "chat.v1.PreviewGuildRequest\032&.protocol.c"
  "hat.v1.PreviewGuildResponse\"\005\232D\002\010\000\022^\n\007Ba"
  "nUser\022 .protocol.chat.v1.BanUserRequest\032"
  "\026.google.protobuf.Empty\"\031\232D\002\010\001\232D\021\032\017user."
  "manage.ban\022a\n\010KickUser\022!.protocol.chat.v"
  "1.KickUserRequest\032\026.google.protobuf.Empt"
  "y\"\032\232D\002\010\001\232D\022\032\020user.manage.kick\022d\n\tUnbanUs"
  "er\022\".protocol.chat.v1.UnbanUserRequest\032\026"
  ".google.protobuf.Empty\"\033\232D\002\010\001\232D\023\032\021user.m"
  "anage.unbanB3Z1github.com/harmony-develo"
  "pment/legato/gen/chat/v1b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_chat_2fv1_2fchat_2eproto_deps[9] = {
  &::descriptor_table_chat_2fv1_2fchannels_2eproto,
  &::descriptor_table_chat_2fv1_2femotes_2eproto,
  &::descriptor_table_chat_2fv1_2fguilds_2eproto,
  &::descriptor_table_chat_2fv1_2fmessages_2eproto,
  &::descriptor_table_chat_2fv1_2fpermissions_2eproto,
  &::descriptor_table_chat_2fv1_2fprofile_2eproto,
  &::descriptor_table_chat_2fv1_2fstreaming_2eproto,
  &::descriptor_table_google_2fprotobuf_2fempty_2eproto,
  &::descriptor_table_harmonytypes_2fv1_2ftypes_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_chat_2fv1_2fchat_2eproto_sccs[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_chat_2fv1_2fchat_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_chat_2fv1_2fchat_2eproto = {
  false, false, descriptor_table_protodef_chat_2fv1_2fchat_2eproto, "chat/v1/chat.proto", 6032,
  &descriptor_table_chat_2fv1_2fchat_2eproto_once, descriptor_table_chat_2fv1_2fchat_2eproto_sccs, descriptor_table_chat_2fv1_2fchat_2eproto_deps, 0, 9,
  schemas, file_default_instances, TableStruct_chat_2fv1_2fchat_2eproto::offsets,
  file_level_metadata_chat_2fv1_2fchat_2eproto, 0, file_level_enum_descriptors_chat_2fv1_2fchat_2eproto, file_level_service_descriptors_chat_2fv1_2fchat_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_chat_2fv1_2fchat_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_chat_2fv1_2fchat_2eproto)), true);
namespace protocol {
namespace chat {
namespace v1 {

// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace chat
}  // namespace protocol
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
