// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sync/v1/sync.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_sync_2fv1_2fsync_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_sync_2fv1_2fsync_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/empty.pb.h>
#include <google/protobuf/any.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_sync_2fv1_2fsync_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_sync_2fv1_2fsync_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_sync_2fv1_2fsync_2eproto;
namespace protocol {
namespace sync {
namespace v1 {
class PostBoxEvent;
class PostBoxEventDefaultTypeInternal;
extern PostBoxEventDefaultTypeInternal _PostBoxEvent_default_instance_;
class PostEventRequest;
class PostEventRequestDefaultTypeInternal;
extern PostEventRequestDefaultTypeInternal _PostEventRequest_default_instance_;
class SyncRequest;
class SyncRequestDefaultTypeInternal;
extern SyncRequestDefaultTypeInternal _SyncRequest_default_instance_;
}  // namespace v1
}  // namespace sync
}  // namespace protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::protocol::sync::v1::PostBoxEvent* Arena::CreateMaybeMessage<::protocol::sync::v1::PostBoxEvent>(Arena*);
template<> ::protocol::sync::v1::PostEventRequest* Arena::CreateMaybeMessage<::protocol::sync::v1::PostEventRequest>(Arena*);
template<> ::protocol::sync::v1::SyncRequest* Arena::CreateMaybeMessage<::protocol::sync::v1::SyncRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protocol {
namespace sync {
namespace v1 {

// ===================================================================

class SyncRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.sync.v1.SyncRequest) */ {
 public:
  inline SyncRequest() : SyncRequest(nullptr) {};
  virtual ~SyncRequest();

  SyncRequest(const SyncRequest& from);
  SyncRequest(SyncRequest&& from) noexcept
    : SyncRequest() {
    *this = ::std::move(from);
  }

  inline SyncRequest& operator=(const SyncRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline SyncRequest& operator=(SyncRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SyncRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SyncRequest* internal_default_instance() {
    return reinterpret_cast<const SyncRequest*>(
               &_SyncRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SyncRequest& a, SyncRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(SyncRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SyncRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SyncRequest* New() const final {
    return CreateMaybeMessage<SyncRequest>(nullptr);
  }

  SyncRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SyncRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SyncRequest& from);
  void MergeFrom(const SyncRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SyncRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.sync.v1.SyncRequest";
  }
  protected:
  explicit SyncRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_sync_2fv1_2fsync_2eproto);
    return ::descriptor_table_sync_2fv1_2fsync_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTokenFieldNumber = 1,
    kHostFieldNumber = 2,
  };
  // string token = 1;
  void clear_token();
  const std::string& token() const;
  void set_token(const std::string& value);
  void set_token(std::string&& value);
  void set_token(const char* value);
  void set_token(const char* value, size_t size);
  std::string* mutable_token();
  std::string* release_token();
  void set_allocated_token(std::string* token);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_token();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_token(
      std::string* token);
  private:
  const std::string& _internal_token() const;
  void _internal_set_token(const std::string& value);
  std::string* _internal_mutable_token();
  public:

  // string host = 2;
  void clear_host();
  const std::string& host() const;
  void set_host(const std::string& value);
  void set_host(std::string&& value);
  void set_host(const char* value);
  void set_host(const char* value, size_t size);
  std::string* mutable_host();
  std::string* release_host();
  void set_allocated_host(std::string* host);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_host();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_host(
      std::string* host);
  private:
  const std::string& _internal_host() const;
  void _internal_set_host(const std::string& value);
  std::string* _internal_mutable_host();
  public:

  // @@protoc_insertion_point(class_scope:protocol.sync.v1.SyncRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr token_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr host_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_sync_2fv1_2fsync_2eproto;
};
// -------------------------------------------------------------------

class PostBoxEvent PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.sync.v1.PostBoxEvent) */ {
 public:
  inline PostBoxEvent() : PostBoxEvent(nullptr) {};
  virtual ~PostBoxEvent();

  PostBoxEvent(const PostBoxEvent& from);
  PostBoxEvent(PostBoxEvent&& from) noexcept
    : PostBoxEvent() {
    *this = ::std::move(from);
  }

  inline PostBoxEvent& operator=(const PostBoxEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline PostBoxEvent& operator=(PostBoxEvent&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const PostBoxEvent& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PostBoxEvent* internal_default_instance() {
    return reinterpret_cast<const PostBoxEvent*>(
               &_PostBoxEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PostBoxEvent& a, PostBoxEvent& b) {
    a.Swap(&b);
  }
  inline void Swap(PostBoxEvent* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PostBoxEvent* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PostBoxEvent* New() const final {
    return CreateMaybeMessage<PostBoxEvent>(nullptr);
  }

  PostBoxEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PostBoxEvent>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PostBoxEvent& from);
  void MergeFrom(const PostBoxEvent& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PostBoxEvent* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.sync.v1.PostBoxEvent";
  }
  protected:
  explicit PostBoxEvent(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_sync_2fv1_2fsync_2eproto);
    return ::descriptor_table_sync_2fv1_2fsync_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEventFieldNumber = 1,
  };
  // .google.protobuf.Any event = 1;
  bool has_event() const;
  private:
  bool _internal_has_event() const;
  public:
  void clear_event();
  const PROTOBUF_NAMESPACE_ID::Any& event() const;
  PROTOBUF_NAMESPACE_ID::Any* release_event();
  PROTOBUF_NAMESPACE_ID::Any* mutable_event();
  void set_allocated_event(PROTOBUF_NAMESPACE_ID::Any* event);
  private:
  const PROTOBUF_NAMESPACE_ID::Any& _internal_event() const;
  PROTOBUF_NAMESPACE_ID::Any* _internal_mutable_event();
  public:
  void unsafe_arena_set_allocated_event(
      PROTOBUF_NAMESPACE_ID::Any* event);
  PROTOBUF_NAMESPACE_ID::Any* unsafe_arena_release_event();

  // @@protoc_insertion_point(class_scope:protocol.sync.v1.PostBoxEvent)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  PROTOBUF_NAMESPACE_ID::Any* event_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_sync_2fv1_2fsync_2eproto;
};
// -------------------------------------------------------------------

class PostEventRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.sync.v1.PostEventRequest) */ {
 public:
  inline PostEventRequest() : PostEventRequest(nullptr) {};
  virtual ~PostEventRequest();

  PostEventRequest(const PostEventRequest& from);
  PostEventRequest(PostEventRequest&& from) noexcept
    : PostEventRequest() {
    *this = ::std::move(from);
  }

  inline PostEventRequest& operator=(const PostEventRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline PostEventRequest& operator=(PostEventRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const PostEventRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PostEventRequest* internal_default_instance() {
    return reinterpret_cast<const PostEventRequest*>(
               &_PostEventRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(PostEventRequest& a, PostEventRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(PostEventRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PostEventRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline PostEventRequest* New() const final {
    return CreateMaybeMessage<PostEventRequest>(nullptr);
  }

  PostEventRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PostEventRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PostEventRequest& from);
  void MergeFrom(const PostEventRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PostEventRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.sync.v1.PostEventRequest";
  }
  protected:
  explicit PostEventRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_sync_2fv1_2fsync_2eproto);
    return ::descriptor_table_sync_2fv1_2fsync_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSyncRequestFieldNumber = 1,
    kEventFieldNumber = 2,
  };
  // .protocol.sync.v1.SyncRequest sync_request = 1;
  bool has_sync_request() const;
  private:
  bool _internal_has_sync_request() const;
  public:
  void clear_sync_request();
  const ::protocol::sync::v1::SyncRequest& sync_request() const;
  ::protocol::sync::v1::SyncRequest* release_sync_request();
  ::protocol::sync::v1::SyncRequest* mutable_sync_request();
  void set_allocated_sync_request(::protocol::sync::v1::SyncRequest* sync_request);
  private:
  const ::protocol::sync::v1::SyncRequest& _internal_sync_request() const;
  ::protocol::sync::v1::SyncRequest* _internal_mutable_sync_request();
  public:
  void unsafe_arena_set_allocated_sync_request(
      ::protocol::sync::v1::SyncRequest* sync_request);
  ::protocol::sync::v1::SyncRequest* unsafe_arena_release_sync_request();

  // .protocol.sync.v1.PostBoxEvent event = 2;
  bool has_event() const;
  private:
  bool _internal_has_event() const;
  public:
  void clear_event();
  const ::protocol::sync::v1::PostBoxEvent& event() const;
  ::protocol::sync::v1::PostBoxEvent* release_event();
  ::protocol::sync::v1::PostBoxEvent* mutable_event();
  void set_allocated_event(::protocol::sync::v1::PostBoxEvent* event);
  private:
  const ::protocol::sync::v1::PostBoxEvent& _internal_event() const;
  ::protocol::sync::v1::PostBoxEvent* _internal_mutable_event();
  public:
  void unsafe_arena_set_allocated_event(
      ::protocol::sync::v1::PostBoxEvent* event);
  ::protocol::sync::v1::PostBoxEvent* unsafe_arena_release_event();

  // @@protoc_insertion_point(class_scope:protocol.sync.v1.PostEventRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::protocol::sync::v1::SyncRequest* sync_request_;
  ::protocol::sync::v1::PostBoxEvent* event_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_sync_2fv1_2fsync_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SyncRequest

// string token = 1;
inline void SyncRequest::clear_token() {
  token_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& SyncRequest::token() const {
  // @@protoc_insertion_point(field_get:protocol.sync.v1.SyncRequest.token)
  return _internal_token();
}
inline void SyncRequest::set_token(const std::string& value) {
  _internal_set_token(value);
  // @@protoc_insertion_point(field_set:protocol.sync.v1.SyncRequest.token)
}
inline std::string* SyncRequest::mutable_token() {
  // @@protoc_insertion_point(field_mutable:protocol.sync.v1.SyncRequest.token)
  return _internal_mutable_token();
}
inline const std::string& SyncRequest::_internal_token() const {
  return token_.Get();
}
inline void SyncRequest::_internal_set_token(const std::string& value) {
  
  token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void SyncRequest::set_token(std::string&& value) {
  
  token_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:protocol.sync.v1.SyncRequest.token)
}
inline void SyncRequest::set_token(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:protocol.sync.v1.SyncRequest.token)
}
inline void SyncRequest::set_token(const char* value,
    size_t size) {
  
  token_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:protocol.sync.v1.SyncRequest.token)
}
inline std::string* SyncRequest::_internal_mutable_token() {
  
  return token_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* SyncRequest::release_token() {
  // @@protoc_insertion_point(field_release:protocol.sync.v1.SyncRequest.token)
  return token_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SyncRequest::set_allocated_token(std::string* token) {
  if (token != nullptr) {
    
  } else {
    
  }
  token_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), token,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:protocol.sync.v1.SyncRequest.token)
}
inline std::string* SyncRequest::unsafe_arena_release_token() {
  // @@protoc_insertion_point(field_unsafe_arena_release:protocol.sync.v1.SyncRequest.token)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return token_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void SyncRequest::unsafe_arena_set_allocated_token(
    std::string* token) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (token != nullptr) {
    
  } else {
    
  }
  token_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      token, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protocol.sync.v1.SyncRequest.token)
}

// string host = 2;
inline void SyncRequest::clear_host() {
  host_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& SyncRequest::host() const {
  // @@protoc_insertion_point(field_get:protocol.sync.v1.SyncRequest.host)
  return _internal_host();
}
inline void SyncRequest::set_host(const std::string& value) {
  _internal_set_host(value);
  // @@protoc_insertion_point(field_set:protocol.sync.v1.SyncRequest.host)
}
inline std::string* SyncRequest::mutable_host() {
  // @@protoc_insertion_point(field_mutable:protocol.sync.v1.SyncRequest.host)
  return _internal_mutable_host();
}
inline const std::string& SyncRequest::_internal_host() const {
  return host_.Get();
}
inline void SyncRequest::_internal_set_host(const std::string& value) {
  
  host_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void SyncRequest::set_host(std::string&& value) {
  
  host_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:protocol.sync.v1.SyncRequest.host)
}
inline void SyncRequest::set_host(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  host_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:protocol.sync.v1.SyncRequest.host)
}
inline void SyncRequest::set_host(const char* value,
    size_t size) {
  
  host_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:protocol.sync.v1.SyncRequest.host)
}
inline std::string* SyncRequest::_internal_mutable_host() {
  
  return host_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* SyncRequest::release_host() {
  // @@protoc_insertion_point(field_release:protocol.sync.v1.SyncRequest.host)
  return host_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SyncRequest::set_allocated_host(std::string* host) {
  if (host != nullptr) {
    
  } else {
    
  }
  host_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), host,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:protocol.sync.v1.SyncRequest.host)
}
inline std::string* SyncRequest::unsafe_arena_release_host() {
  // @@protoc_insertion_point(field_unsafe_arena_release:protocol.sync.v1.SyncRequest.host)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return host_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void SyncRequest::unsafe_arena_set_allocated_host(
    std::string* host) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (host != nullptr) {
    
  } else {
    
  }
  host_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      host, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protocol.sync.v1.SyncRequest.host)
}

// -------------------------------------------------------------------

// PostBoxEvent

// .google.protobuf.Any event = 1;
inline bool PostBoxEvent::_internal_has_event() const {
  return this != internal_default_instance() && event_ != nullptr;
}
inline bool PostBoxEvent::has_event() const {
  return _internal_has_event();
}
inline const PROTOBUF_NAMESPACE_ID::Any& PostBoxEvent::_internal_event() const {
  const PROTOBUF_NAMESPACE_ID::Any* p = event_;
  return p != nullptr ? *p : *reinterpret_cast<const PROTOBUF_NAMESPACE_ID::Any*>(
      &PROTOBUF_NAMESPACE_ID::_Any_default_instance_);
}
inline const PROTOBUF_NAMESPACE_ID::Any& PostBoxEvent::event() const {
  // @@protoc_insertion_point(field_get:protocol.sync.v1.PostBoxEvent.event)
  return _internal_event();
}
inline void PostBoxEvent::unsafe_arena_set_allocated_event(
    PROTOBUF_NAMESPACE_ID::Any* event) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(event_);
  }
  event_ = event;
  if (event) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protocol.sync.v1.PostBoxEvent.event)
}
inline PROTOBUF_NAMESPACE_ID::Any* PostBoxEvent::release_event() {
  auto temp = unsafe_arena_release_event();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Any* PostBoxEvent::unsafe_arena_release_event() {
  // @@protoc_insertion_point(field_release:protocol.sync.v1.PostBoxEvent.event)
  
  PROTOBUF_NAMESPACE_ID::Any* temp = event_;
  event_ = nullptr;
  return temp;
}
inline PROTOBUF_NAMESPACE_ID::Any* PostBoxEvent::_internal_mutable_event() {
  
  if (event_ == nullptr) {
    auto* p = CreateMaybeMessage<PROTOBUF_NAMESPACE_ID::Any>(GetArena());
    event_ = p;
  }
  return event_;
}
inline PROTOBUF_NAMESPACE_ID::Any* PostBoxEvent::mutable_event() {
  // @@protoc_insertion_point(field_mutable:protocol.sync.v1.PostBoxEvent.event)
  return _internal_mutable_event();
}
inline void PostBoxEvent::set_allocated_event(PROTOBUF_NAMESPACE_ID::Any* event) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(event_);
  }
  if (event) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(event)->GetArena();
    if (message_arena != submessage_arena) {
      event = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, event, submessage_arena);
    }
    
  } else {
    
  }
  event_ = event;
  // @@protoc_insertion_point(field_set_allocated:protocol.sync.v1.PostBoxEvent.event)
}

// -------------------------------------------------------------------

// PostEventRequest

// .protocol.sync.v1.SyncRequest sync_request = 1;
inline bool PostEventRequest::_internal_has_sync_request() const {
  return this != internal_default_instance() && sync_request_ != nullptr;
}
inline bool PostEventRequest::has_sync_request() const {
  return _internal_has_sync_request();
}
inline void PostEventRequest::clear_sync_request() {
  if (GetArena() == nullptr && sync_request_ != nullptr) {
    delete sync_request_;
  }
  sync_request_ = nullptr;
}
inline const ::protocol::sync::v1::SyncRequest& PostEventRequest::_internal_sync_request() const {
  const ::protocol::sync::v1::SyncRequest* p = sync_request_;
  return p != nullptr ? *p : *reinterpret_cast<const ::protocol::sync::v1::SyncRequest*>(
      &::protocol::sync::v1::_SyncRequest_default_instance_);
}
inline const ::protocol::sync::v1::SyncRequest& PostEventRequest::sync_request() const {
  // @@protoc_insertion_point(field_get:protocol.sync.v1.PostEventRequest.sync_request)
  return _internal_sync_request();
}
inline void PostEventRequest::unsafe_arena_set_allocated_sync_request(
    ::protocol::sync::v1::SyncRequest* sync_request) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(sync_request_);
  }
  sync_request_ = sync_request;
  if (sync_request) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protocol.sync.v1.PostEventRequest.sync_request)
}
inline ::protocol::sync::v1::SyncRequest* PostEventRequest::release_sync_request() {
  auto temp = unsafe_arena_release_sync_request();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::protocol::sync::v1::SyncRequest* PostEventRequest::unsafe_arena_release_sync_request() {
  // @@protoc_insertion_point(field_release:protocol.sync.v1.PostEventRequest.sync_request)
  
  ::protocol::sync::v1::SyncRequest* temp = sync_request_;
  sync_request_ = nullptr;
  return temp;
}
inline ::protocol::sync::v1::SyncRequest* PostEventRequest::_internal_mutable_sync_request() {
  
  if (sync_request_ == nullptr) {
    auto* p = CreateMaybeMessage<::protocol::sync::v1::SyncRequest>(GetArena());
    sync_request_ = p;
  }
  return sync_request_;
}
inline ::protocol::sync::v1::SyncRequest* PostEventRequest::mutable_sync_request() {
  // @@protoc_insertion_point(field_mutable:protocol.sync.v1.PostEventRequest.sync_request)
  return _internal_mutable_sync_request();
}
inline void PostEventRequest::set_allocated_sync_request(::protocol::sync::v1::SyncRequest* sync_request) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete sync_request_;
  }
  if (sync_request) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(sync_request);
    if (message_arena != submessage_arena) {
      sync_request = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, sync_request, submessage_arena);
    }
    
  } else {
    
  }
  sync_request_ = sync_request;
  // @@protoc_insertion_point(field_set_allocated:protocol.sync.v1.PostEventRequest.sync_request)
}

// .protocol.sync.v1.PostBoxEvent event = 2;
inline bool PostEventRequest::_internal_has_event() const {
  return this != internal_default_instance() && event_ != nullptr;
}
inline bool PostEventRequest::has_event() const {
  return _internal_has_event();
}
inline void PostEventRequest::clear_event() {
  if (GetArena() == nullptr && event_ != nullptr) {
    delete event_;
  }
  event_ = nullptr;
}
inline const ::protocol::sync::v1::PostBoxEvent& PostEventRequest::_internal_event() const {
  const ::protocol::sync::v1::PostBoxEvent* p = event_;
  return p != nullptr ? *p : *reinterpret_cast<const ::protocol::sync::v1::PostBoxEvent*>(
      &::protocol::sync::v1::_PostBoxEvent_default_instance_);
}
inline const ::protocol::sync::v1::PostBoxEvent& PostEventRequest::event() const {
  // @@protoc_insertion_point(field_get:protocol.sync.v1.PostEventRequest.event)
  return _internal_event();
}
inline void PostEventRequest::unsafe_arena_set_allocated_event(
    ::protocol::sync::v1::PostBoxEvent* event) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(event_);
  }
  event_ = event;
  if (event) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protocol.sync.v1.PostEventRequest.event)
}
inline ::protocol::sync::v1::PostBoxEvent* PostEventRequest::release_event() {
  auto temp = unsafe_arena_release_event();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::protocol::sync::v1::PostBoxEvent* PostEventRequest::unsafe_arena_release_event() {
  // @@protoc_insertion_point(field_release:protocol.sync.v1.PostEventRequest.event)
  
  ::protocol::sync::v1::PostBoxEvent* temp = event_;
  event_ = nullptr;
  return temp;
}
inline ::protocol::sync::v1::PostBoxEvent* PostEventRequest::_internal_mutable_event() {
  
  if (event_ == nullptr) {
    auto* p = CreateMaybeMessage<::protocol::sync::v1::PostBoxEvent>(GetArena());
    event_ = p;
  }
  return event_;
}
inline ::protocol::sync::v1::PostBoxEvent* PostEventRequest::mutable_event() {
  // @@protoc_insertion_point(field_mutable:protocol.sync.v1.PostEventRequest.event)
  return _internal_mutable_event();
}
inline void PostEventRequest::set_allocated_event(::protocol::sync::v1::PostBoxEvent* event) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete event_;
  }
  if (event) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(event);
    if (message_arena != submessage_arena) {
      event = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, event, submessage_arena);
    }
    
  } else {
    
  }
  event_ = event;
  // @@protoc_insertion_point(field_set_allocated:protocol.sync.v1.PostEventRequest.event)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace sync
}  // namespace protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_sync_2fv1_2fsync_2eproto