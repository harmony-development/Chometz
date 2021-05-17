// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sync/v1/sync.proto

#include "sync/v1/sync.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_google_2fprotobuf_2fany_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Any_google_2fprotobuf_2fany_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_sync_2fv1_2fsync_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_sync_2fv1_2fsync_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SyncRequest_sync_2fv1_2fsync_2eproto;
namespace protocol {
namespace sync {
namespace v1 {
class SyncRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SyncRequest> _instance;
} _SyncRequest_default_instance_;
class PostBoxEventDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PostBoxEvent> _instance;
} _PostBoxEvent_default_instance_;
class PostEventRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PostEventRequest> _instance;
} _PostEventRequest_default_instance_;
}  // namespace v1
}  // namespace sync
}  // namespace protocol
static void InitDefaultsscc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protocol::sync::v1::_PostBoxEvent_default_instance_;
    new (ptr) ::protocol::sync::v1::PostBoxEvent();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protocol::sync::v1::PostBoxEvent::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto}, {
      &scc_info_Any_google_2fprotobuf_2fany_2eproto.base,}};

static void InitDefaultsscc_info_PostEventRequest_sync_2fv1_2fsync_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protocol::sync::v1::_PostEventRequest_default_instance_;
    new (ptr) ::protocol::sync::v1::PostEventRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protocol::sync::v1::PostEventRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_PostEventRequest_sync_2fv1_2fsync_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_PostEventRequest_sync_2fv1_2fsync_2eproto}, {
      &scc_info_SyncRequest_sync_2fv1_2fsync_2eproto.base,
      &scc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto.base,}};

static void InitDefaultsscc_info_SyncRequest_sync_2fv1_2fsync_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::protocol::sync::v1::_SyncRequest_default_instance_;
    new (ptr) ::protocol::sync::v1::SyncRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::protocol::sync::v1::SyncRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SyncRequest_sync_2fv1_2fsync_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SyncRequest_sync_2fv1_2fsync_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_sync_2fv1_2fsync_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_sync_2fv1_2fsync_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_sync_2fv1_2fsync_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_sync_2fv1_2fsync_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::SyncRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::SyncRequest, token_),
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::SyncRequest, host_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::PostBoxEvent, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::PostBoxEvent, event_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::PostEventRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::PostEventRequest, sync_request_),
  PROTOBUF_FIELD_OFFSET(::protocol::sync::v1::PostEventRequest, event_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::protocol::sync::v1::SyncRequest)},
  { 7, -1, sizeof(::protocol::sync::v1::PostBoxEvent)},
  { 13, -1, sizeof(::protocol::sync::v1::PostEventRequest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protocol::sync::v1::_SyncRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protocol::sync::v1::_PostBoxEvent_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::protocol::sync::v1::_PostEventRequest_default_instance_),
};

const char descriptor_table_protodef_sync_2fv1_2fsync_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022sync/v1/sync.proto\022\020protocol.sync.v1\032\033"
  "google/protobuf/empty.proto\032\031google/prot"
  "obuf/any.proto\"*\n\013SyncRequest\022\r\n\005token\030\001"
  " \001(\t\022\014\n\004host\030\002 \001(\t\"3\n\014PostBoxEvent\022#\n\005ev"
  "ent\030\001 \001(\0132\024.google.protobuf.Any\"v\n\020PostE"
  "ventRequest\0223\n\014sync_request\030\001 \001(\0132\035.prot"
  "ocol.sync.v1.SyncRequest\022-\n\005event\030\002 \001(\0132"
  "\036.protocol.sync.v1.PostBoxEvent2\246\001\n\016Post"
  "boxService\022I\n\004Sync\022\035.protocol.sync.v1.Sy"
  "ncRequest\032\036.protocol.sync.v1.PostBoxEven"
  "t\"\0000\001\022I\n\tPostEvent\022\".protocol.sync.v1.Po"
  "stEventRequest\032\026.google.protobuf.Empty\"\000"
  "B3Z1github.com/harmony-development/legat"
  "o/gen/sync/v1b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_sync_2fv1_2fsync_2eproto_deps[2] = {
  &::descriptor_table_google_2fprotobuf_2fany_2eproto,
  &::descriptor_table_google_2fprotobuf_2fempty_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_sync_2fv1_2fsync_2eproto_sccs[3] = {
  &scc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto.base,
  &scc_info_PostEventRequest_sync_2fv1_2fsync_2eproto.base,
  &scc_info_SyncRequest_sync_2fv1_2fsync_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_sync_2fv1_2fsync_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sync_2fv1_2fsync_2eproto = {
  false, false, descriptor_table_protodef_sync_2fv1_2fsync_2eproto, "sync/v1/sync.proto", 541,
  &descriptor_table_sync_2fv1_2fsync_2eproto_once, descriptor_table_sync_2fv1_2fsync_2eproto_sccs, descriptor_table_sync_2fv1_2fsync_2eproto_deps, 3, 2,
  schemas, file_default_instances, TableStruct_sync_2fv1_2fsync_2eproto::offsets,
  file_level_metadata_sync_2fv1_2fsync_2eproto, 3, file_level_enum_descriptors_sync_2fv1_2fsync_2eproto, file_level_service_descriptors_sync_2fv1_2fsync_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_sync_2fv1_2fsync_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_sync_2fv1_2fsync_2eproto)), true);
namespace protocol {
namespace sync {
namespace v1 {

// ===================================================================

void SyncRequest::InitAsDefaultInstance() {
}
class SyncRequest::_Internal {
 public:
};

SyncRequest::SyncRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protocol.sync.v1.SyncRequest)
}
SyncRequest::SyncRequest(const SyncRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_token().empty()) {
    token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_token(),
      GetArena());
  }
  host_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_host().empty()) {
    host_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_host(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:protocol.sync.v1.SyncRequest)
}

void SyncRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SyncRequest_sync_2fv1_2fsync_2eproto.base);
  token_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  host_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

SyncRequest::~SyncRequest() {
  // @@protoc_insertion_point(destructor:protocol.sync.v1.SyncRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SyncRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  token_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  host_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SyncRequest::ArenaDtor(void* object) {
  SyncRequest* _this = reinterpret_cast< SyncRequest* >(object);
  (void)_this;
}
void SyncRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SyncRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SyncRequest& SyncRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SyncRequest_sync_2fv1_2fsync_2eproto.base);
  return *internal_default_instance();
}


void SyncRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:protocol.sync.v1.SyncRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  token_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  host_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SyncRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string token = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_token();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protocol.sync.v1.SyncRequest.token"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string host = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_host();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "protocol.sync.v1.SyncRequest.host"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* SyncRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.sync.v1.SyncRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string token = 1;
  if (this->token().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_token().data(), static_cast<int>(this->_internal_token().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protocol.sync.v1.SyncRequest.token");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_token(), target);
  }

  // string host = 2;
  if (this->host().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_host().data(), static_cast<int>(this->_internal_host().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "protocol.sync.v1.SyncRequest.host");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_host(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.sync.v1.SyncRequest)
  return target;
}

size_t SyncRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protocol.sync.v1.SyncRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string token = 1;
  if (this->token().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_token());
  }

  // string host = 2;
  if (this->host().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_host());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SyncRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protocol.sync.v1.SyncRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const SyncRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SyncRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protocol.sync.v1.SyncRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protocol.sync.v1.SyncRequest)
    MergeFrom(*source);
  }
}

void SyncRequest::MergeFrom(const SyncRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protocol.sync.v1.SyncRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.token().size() > 0) {
    _internal_set_token(from._internal_token());
  }
  if (from.host().size() > 0) {
    _internal_set_host(from._internal_host());
  }
}

void SyncRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protocol.sync.v1.SyncRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SyncRequest::CopyFrom(const SyncRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protocol.sync.v1.SyncRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SyncRequest::IsInitialized() const {
  return true;
}

void SyncRequest::InternalSwap(SyncRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  token_.Swap(&other->token_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  host_.Swap(&other->host_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata SyncRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void PostBoxEvent::InitAsDefaultInstance() {
  ::protocol::sync::v1::_PostBoxEvent_default_instance_._instance.get_mutable()->event_ = const_cast< PROTOBUF_NAMESPACE_ID::Any*>(
      PROTOBUF_NAMESPACE_ID::Any::internal_default_instance());
}
class PostBoxEvent::_Internal {
 public:
  static const PROTOBUF_NAMESPACE_ID::Any& event(const PostBoxEvent* msg);
};

const PROTOBUF_NAMESPACE_ID::Any&
PostBoxEvent::_Internal::event(const PostBoxEvent* msg) {
  return *msg->event_;
}
void PostBoxEvent::clear_event() {
  if (GetArena() == nullptr && event_ != nullptr) {
    delete event_;
  }
  event_ = nullptr;
}
PostBoxEvent::PostBoxEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protocol.sync.v1.PostBoxEvent)
}
PostBoxEvent::PostBoxEvent(const PostBoxEvent& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_event()) {
    event_ = new PROTOBUF_NAMESPACE_ID::Any(*from.event_);
  } else {
    event_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:protocol.sync.v1.PostBoxEvent)
}

void PostBoxEvent::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto.base);
  event_ = nullptr;
}

PostBoxEvent::~PostBoxEvent() {
  // @@protoc_insertion_point(destructor:protocol.sync.v1.PostBoxEvent)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PostBoxEvent::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete event_;
}

void PostBoxEvent::ArenaDtor(void* object) {
  PostBoxEvent* _this = reinterpret_cast< PostBoxEvent* >(object);
  (void)_this;
}
void PostBoxEvent::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PostBoxEvent::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PostBoxEvent& PostBoxEvent::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PostBoxEvent_sync_2fv1_2fsync_2eproto.base);
  return *internal_default_instance();
}


void PostBoxEvent::Clear() {
// @@protoc_insertion_point(message_clear_start:protocol.sync.v1.PostBoxEvent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && event_ != nullptr) {
    delete event_;
  }
  event_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PostBoxEvent::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .google.protobuf.Any event = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_event(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PostBoxEvent::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.sync.v1.PostBoxEvent)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .google.protobuf.Any event = 1;
  if (this->has_event()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::event(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.sync.v1.PostBoxEvent)
  return target;
}

size_t PostBoxEvent::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protocol.sync.v1.PostBoxEvent)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .google.protobuf.Any event = 1;
  if (this->has_event()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *event_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PostBoxEvent::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protocol.sync.v1.PostBoxEvent)
  GOOGLE_DCHECK_NE(&from, this);
  const PostBoxEvent* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PostBoxEvent>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protocol.sync.v1.PostBoxEvent)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protocol.sync.v1.PostBoxEvent)
    MergeFrom(*source);
  }
}

void PostBoxEvent::MergeFrom(const PostBoxEvent& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protocol.sync.v1.PostBoxEvent)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_event()) {
    _internal_mutable_event()->PROTOBUF_NAMESPACE_ID::Any::MergeFrom(from._internal_event());
  }
}

void PostBoxEvent::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protocol.sync.v1.PostBoxEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PostBoxEvent::CopyFrom(const PostBoxEvent& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protocol.sync.v1.PostBoxEvent)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PostBoxEvent::IsInitialized() const {
  return true;
}

void PostBoxEvent::InternalSwap(PostBoxEvent* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(event_, other->event_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PostBoxEvent::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void PostEventRequest::InitAsDefaultInstance() {
  ::protocol::sync::v1::_PostEventRequest_default_instance_._instance.get_mutable()->sync_request_ = const_cast< ::protocol::sync::v1::SyncRequest*>(
      ::protocol::sync::v1::SyncRequest::internal_default_instance());
  ::protocol::sync::v1::_PostEventRequest_default_instance_._instance.get_mutable()->event_ = const_cast< ::protocol::sync::v1::PostBoxEvent*>(
      ::protocol::sync::v1::PostBoxEvent::internal_default_instance());
}
class PostEventRequest::_Internal {
 public:
  static const ::protocol::sync::v1::SyncRequest& sync_request(const PostEventRequest* msg);
  static const ::protocol::sync::v1::PostBoxEvent& event(const PostEventRequest* msg);
};

const ::protocol::sync::v1::SyncRequest&
PostEventRequest::_Internal::sync_request(const PostEventRequest* msg) {
  return *msg->sync_request_;
}
const ::protocol::sync::v1::PostBoxEvent&
PostEventRequest::_Internal::event(const PostEventRequest* msg) {
  return *msg->event_;
}
PostEventRequest::PostEventRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:protocol.sync.v1.PostEventRequest)
}
PostEventRequest::PostEventRequest(const PostEventRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_sync_request()) {
    sync_request_ = new ::protocol::sync::v1::SyncRequest(*from.sync_request_);
  } else {
    sync_request_ = nullptr;
  }
  if (from._internal_has_event()) {
    event_ = new ::protocol::sync::v1::PostBoxEvent(*from.event_);
  } else {
    event_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:protocol.sync.v1.PostEventRequest)
}

void PostEventRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_PostEventRequest_sync_2fv1_2fsync_2eproto.base);
  ::memset(&sync_request_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&event_) -
      reinterpret_cast<char*>(&sync_request_)) + sizeof(event_));
}

PostEventRequest::~PostEventRequest() {
  // @@protoc_insertion_point(destructor:protocol.sync.v1.PostEventRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PostEventRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete sync_request_;
  if (this != internal_default_instance()) delete event_;
}

void PostEventRequest::ArenaDtor(void* object) {
  PostEventRequest* _this = reinterpret_cast< PostEventRequest* >(object);
  (void)_this;
}
void PostEventRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PostEventRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PostEventRequest& PostEventRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PostEventRequest_sync_2fv1_2fsync_2eproto.base);
  return *internal_default_instance();
}


void PostEventRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:protocol.sync.v1.PostEventRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && sync_request_ != nullptr) {
    delete sync_request_;
  }
  sync_request_ = nullptr;
  if (GetArena() == nullptr && event_ != nullptr) {
    delete event_;
  }
  event_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PostEventRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .protocol.sync.v1.SyncRequest sync_request = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_sync_request(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .protocol.sync.v1.PostBoxEvent event = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_event(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PostEventRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.sync.v1.PostEventRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .protocol.sync.v1.SyncRequest sync_request = 1;
  if (this->has_sync_request()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::sync_request(this), target, stream);
  }

  // .protocol.sync.v1.PostBoxEvent event = 2;
  if (this->has_event()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::event(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.sync.v1.PostEventRequest)
  return target;
}

size_t PostEventRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protocol.sync.v1.PostEventRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .protocol.sync.v1.SyncRequest sync_request = 1;
  if (this->has_sync_request()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *sync_request_);
  }

  // .protocol.sync.v1.PostBoxEvent event = 2;
  if (this->has_event()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *event_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PostEventRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:protocol.sync.v1.PostEventRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const PostEventRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PostEventRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:protocol.sync.v1.PostEventRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:protocol.sync.v1.PostEventRequest)
    MergeFrom(*source);
  }
}

void PostEventRequest::MergeFrom(const PostEventRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protocol.sync.v1.PostEventRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_sync_request()) {
    _internal_mutable_sync_request()->::protocol::sync::v1::SyncRequest::MergeFrom(from._internal_sync_request());
  }
  if (from.has_event()) {
    _internal_mutable_event()->::protocol::sync::v1::PostBoxEvent::MergeFrom(from._internal_event());
  }
}

void PostEventRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:protocol.sync.v1.PostEventRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PostEventRequest::CopyFrom(const PostEventRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protocol.sync.v1.PostEventRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PostEventRequest::IsInitialized() const {
  return true;
}

void PostEventRequest::InternalSwap(PostEventRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PostEventRequest, event_)
      + sizeof(PostEventRequest::event_)
      - PROTOBUF_FIELD_OFFSET(PostEventRequest, sync_request_)>(
          reinterpret_cast<char*>(&sync_request_),
          reinterpret_cast<char*>(&other->sync_request_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PostEventRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1
}  // namespace sync
}  // namespace protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::protocol::sync::v1::SyncRequest* Arena::CreateMaybeMessage< ::protocol::sync::v1::SyncRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protocol::sync::v1::SyncRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::protocol::sync::v1::PostBoxEvent* Arena::CreateMaybeMessage< ::protocol::sync::v1::PostBoxEvent >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protocol::sync::v1::PostBoxEvent >(arena);
}
template<> PROTOBUF_NOINLINE ::protocol::sync::v1::PostEventRequest* Arena::CreateMaybeMessage< ::protocol::sync::v1::PostEventRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::protocol::sync::v1::PostEventRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
