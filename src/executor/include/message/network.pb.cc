// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: network.proto

#include "network.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_network_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PortArray_network_2eproto;
namespace com {
namespace nus {
namespace dbsytem {
namespace falcon {
namespace v0 {
class NetworkConfigDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<NetworkConfig> _instance;
} _NetworkConfig_default_instance_;
class PortArrayDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PortArray> _instance;
} _PortArray_default_instance_;
}  // namespace v0
}  // namespace falcon
}  // namespace dbsytem
}  // namespace nus
}  // namespace com
static void InitDefaultsscc_info_NetworkConfig_network_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::com::nus::dbsytem::falcon::v0::_NetworkConfig_default_instance_;
    new (ptr) ::com::nus::dbsytem::falcon::v0::NetworkConfig();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_NetworkConfig_network_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_NetworkConfig_network_2eproto}, {
      &scc_info_PortArray_network_2eproto.base,}};

static void InitDefaultsscc_info_PortArray_network_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::com::nus::dbsytem::falcon::v0::_PortArray_default_instance_;
    new (ptr) ::com::nus::dbsytem::falcon::v0::PortArray();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PortArray_network_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_PortArray_network_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_network_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_network_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_network_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_network_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::com::nus::dbsytem::falcon::v0::NetworkConfig, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::com::nus::dbsytem::falcon::v0::NetworkConfig, ips_),
  PROTOBUF_FIELD_OFFSET(::com::nus::dbsytem::falcon::v0::NetworkConfig, executor_executor_port_arrays_),
  PROTOBUF_FIELD_OFFSET(::com::nus::dbsytem::falcon::v0::NetworkConfig, executor_mpc_port_array_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::com::nus::dbsytem::falcon::v0::PortArray, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::com::nus::dbsytem::falcon::v0::PortArray, ports_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::com::nus::dbsytem::falcon::v0::NetworkConfig)},
  { 8, -1, sizeof(::com::nus::dbsytem::falcon::v0::PortArray)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::com::nus::dbsytem::falcon::v0::_NetworkConfig_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::com::nus::dbsytem::falcon::v0::_PortArray_default_instance_),
};

const char descriptor_table_protodef_network_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rnetwork.proto\022\031com.nus.dbsytem.falcon."
  "v0\"\260\001\n\rNetworkConfig\022\013\n\003ips\030\001 \003(\t\022K\n\035exe"
  "cutor_executor_port_arrays\030\002 \003(\0132$.com.n"
  "us.dbsytem.falcon.v0.PortArray\022E\n\027execut"
  "or_mpc_port_array\030\003 \001(\0132$.com.nus.dbsyte"
  "m.falcon.v0.PortArray\"\032\n\tPortArray\022\r\n\005po"
  "rts\030\001 \003(\005B\005Z\003/v0b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_network_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_network_2eproto_sccs[2] = {
  &scc_info_NetworkConfig_network_2eproto.base,
  &scc_info_PortArray_network_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_network_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_network_2eproto = {
  false, false, descriptor_table_protodef_network_2eproto, "network.proto", 264,
  &descriptor_table_network_2eproto_once, descriptor_table_network_2eproto_sccs, descriptor_table_network_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_network_2eproto::offsets,
  file_level_metadata_network_2eproto, 2, file_level_enum_descriptors_network_2eproto, file_level_service_descriptors_network_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_network_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_network_2eproto)), true);
namespace com {
namespace nus {
namespace dbsytem {
namespace falcon {
namespace v0 {

// ===================================================================

class NetworkConfig::_Internal {
 public:
  static const ::com::nus::dbsytem::falcon::v0::PortArray& executor_mpc_port_array(const NetworkConfig* msg);
};

const ::com::nus::dbsytem::falcon::v0::PortArray&
NetworkConfig::_Internal::executor_mpc_port_array(const NetworkConfig* msg) {
  return *msg->executor_mpc_port_array_;
}
NetworkConfig::NetworkConfig(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  ips_(arena),
  executor_executor_port_arrays_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:com.nus.dbsytem.falcon.v0.NetworkConfig)
}
NetworkConfig::NetworkConfig(const NetworkConfig& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      ips_(from.ips_),
      executor_executor_port_arrays_(from.executor_executor_port_arrays_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_executor_mpc_port_array()) {
    executor_mpc_port_array_ = new ::com::nus::dbsytem::falcon::v0::PortArray(*from.executor_mpc_port_array_);
  } else {
    executor_mpc_port_array_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:com.nus.dbsytem.falcon.v0.NetworkConfig)
}

void NetworkConfig::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_NetworkConfig_network_2eproto.base);
  executor_mpc_port_array_ = nullptr;
}

NetworkConfig::~NetworkConfig() {
  // @@protoc_insertion_point(destructor:com.nus.dbsytem.falcon.v0.NetworkConfig)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void NetworkConfig::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete executor_mpc_port_array_;
}

void NetworkConfig::ArenaDtor(void* object) {
  NetworkConfig* _this = reinterpret_cast< NetworkConfig* >(object);
  (void)_this;
}
void NetworkConfig::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void NetworkConfig::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const NetworkConfig& NetworkConfig::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_NetworkConfig_network_2eproto.base);
  return *internal_default_instance();
}


void NetworkConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ips_.Clear();
  executor_executor_port_arrays_.Clear();
  if (GetArena() == nullptr && executor_mpc_port_array_ != nullptr) {
    delete executor_mpc_port_array_;
  }
  executor_mpc_port_array_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* NetworkConfig::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated string ips = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_ips();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "com.nus.dbsytem.falcon.v0.NetworkConfig.ips"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      // repeated .com.nus.dbsytem.falcon.v0.PortArray executor_executor_port_arrays = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_executor_executor_port_arrays(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      // .com.nus.dbsytem.falcon.v0.PortArray executor_mpc_port_array = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_executor_mpc_port_array(), ptr);
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

::PROTOBUF_NAMESPACE_ID::uint8* NetworkConfig::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated string ips = 1;
  for (int i = 0, n = this->_internal_ips_size(); i < n; i++) {
    const auto& s = this->_internal_ips(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "com.nus.dbsytem.falcon.v0.NetworkConfig.ips");
    target = stream->WriteString(1, s, target);
  }

  // repeated .com.nus.dbsytem.falcon.v0.PortArray executor_executor_port_arrays = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_executor_executor_port_arrays_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_executor_executor_port_arrays(i), target, stream);
  }

  // .com.nus.dbsytem.falcon.v0.PortArray executor_mpc_port_array = 3;
  if (this->has_executor_mpc_port_array()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        3, _Internal::executor_mpc_port_array(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:com.nus.dbsytem.falcon.v0.NetworkConfig)
  return target;
}

size_t NetworkConfig::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string ips = 1;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(ips_.size());
  for (int i = 0, n = ips_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      ips_.Get(i));
  }

  // repeated .com.nus.dbsytem.falcon.v0.PortArray executor_executor_port_arrays = 2;
  total_size += 1UL * this->_internal_executor_executor_port_arrays_size();
  for (const auto& msg : this->executor_executor_port_arrays_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .com.nus.dbsytem.falcon.v0.PortArray executor_mpc_port_array = 3;
  if (this->has_executor_mpc_port_array()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *executor_mpc_port_array_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void NetworkConfig::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  GOOGLE_DCHECK_NE(&from, this);
  const NetworkConfig* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<NetworkConfig>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:com.nus.dbsytem.falcon.v0.NetworkConfig)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:com.nus.dbsytem.falcon.v0.NetworkConfig)
    MergeFrom(*source);
  }
}

void NetworkConfig::MergeFrom(const NetworkConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  ips_.MergeFrom(from.ips_);
  executor_executor_port_arrays_.MergeFrom(from.executor_executor_port_arrays_);
  if (from.has_executor_mpc_port_array()) {
    _internal_mutable_executor_mpc_port_array()->::com::nus::dbsytem::falcon::v0::PortArray::MergeFrom(from._internal_executor_mpc_port_array());
  }
}

void NetworkConfig::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NetworkConfig::CopyFrom(const NetworkConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:com.nus.dbsytem.falcon.v0.NetworkConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NetworkConfig::IsInitialized() const {
  return true;
}

void NetworkConfig::InternalSwap(NetworkConfig* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ips_.InternalSwap(&other->ips_);
  executor_executor_port_arrays_.InternalSwap(&other->executor_executor_port_arrays_);
  swap(executor_mpc_port_array_, other->executor_mpc_port_array_);
}

::PROTOBUF_NAMESPACE_ID::Metadata NetworkConfig::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class PortArray::_Internal {
 public:
};

PortArray::PortArray(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  ports_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:com.nus.dbsytem.falcon.v0.PortArray)
}
PortArray::PortArray(const PortArray& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      ports_(from.ports_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:com.nus.dbsytem.falcon.v0.PortArray)
}

void PortArray::SharedCtor() {
}

PortArray::~PortArray() {
  // @@protoc_insertion_point(destructor:com.nus.dbsytem.falcon.v0.PortArray)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PortArray::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void PortArray::ArenaDtor(void* object) {
  PortArray* _this = reinterpret_cast< PortArray* >(object);
  (void)_this;
}
void PortArray::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PortArray::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PortArray& PortArray::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PortArray_network_2eproto.base);
  return *internal_default_instance();
}


void PortArray::Clear() {
// @@protoc_insertion_point(message_clear_start:com.nus.dbsytem.falcon.v0.PortArray)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ports_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PortArray::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated int32 ports = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_ports(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8) {
          _internal_add_ports(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
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

::PROTOBUF_NAMESPACE_ID::uint8* PortArray::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:com.nus.dbsytem.falcon.v0.PortArray)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated int32 ports = 1;
  {
    int byte_size = _ports_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          1, _internal_ports(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:com.nus.dbsytem.falcon.v0.PortArray)
  return target;
}

size_t PortArray::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:com.nus.dbsytem.falcon.v0.PortArray)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 ports = 1;
  {
    size_t data_size = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      Int32Size(this->ports_);
    if (data_size > 0) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
            static_cast<::PROTOBUF_NAMESPACE_ID::int32>(data_size));
    }
    int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(data_size);
    _ports_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PortArray::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:com.nus.dbsytem.falcon.v0.PortArray)
  GOOGLE_DCHECK_NE(&from, this);
  const PortArray* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PortArray>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:com.nus.dbsytem.falcon.v0.PortArray)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:com.nus.dbsytem.falcon.v0.PortArray)
    MergeFrom(*source);
  }
}

void PortArray::MergeFrom(const PortArray& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:com.nus.dbsytem.falcon.v0.PortArray)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  ports_.MergeFrom(from.ports_);
}

void PortArray::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:com.nus.dbsytem.falcon.v0.PortArray)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PortArray::CopyFrom(const PortArray& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:com.nus.dbsytem.falcon.v0.PortArray)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PortArray::IsInitialized() const {
  return true;
}

void PortArray::InternalSwap(PortArray* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ports_.InternalSwap(&other->ports_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PortArray::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v0
}  // namespace falcon
}  // namespace dbsytem
}  // namespace nus
}  // namespace com
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::com::nus::dbsytem::falcon::v0::NetworkConfig* Arena::CreateMaybeMessage< ::com::nus::dbsytem::falcon::v0::NetworkConfig >(Arena* arena) {
  return Arena::CreateMessageInternal< ::com::nus::dbsytem::falcon::v0::NetworkConfig >(arena);
}
template<> PROTOBUF_NOINLINE ::com::nus::dbsytem::falcon::v0::PortArray* Arena::CreateMaybeMessage< ::com::nus::dbsytem::falcon::v0::PortArray >(Arena* arena) {
  return Arena::CreateMessageInternal< ::com::nus::dbsytem::falcon::v0::PortArray >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
