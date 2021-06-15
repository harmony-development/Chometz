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
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "harmonytypes/v1/types.pb.h"
Q_DECLARE_METATYPE(google::protobuf::FileDescriptorSet)
Q_DECLARE_METATYPE(google::protobuf::FileDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::DescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::ExtensionRangeOptions)
Q_DECLARE_METATYPE(google::protobuf::FieldDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::OneofDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::EnumDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::EnumValueDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::ServiceDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::MethodDescriptorProto)
Q_DECLARE_METATYPE(google::protobuf::FileOptions)
Q_DECLARE_METATYPE(google::protobuf::MessageOptions)
Q_DECLARE_METATYPE(google::protobuf::FieldOptions)
Q_DECLARE_METATYPE(google::protobuf::OneofOptions)
Q_DECLARE_METATYPE(google::protobuf::EnumOptions)
Q_DECLARE_METATYPE(google::protobuf::EnumValueOptions)
Q_DECLARE_METATYPE(google::protobuf::ServiceOptions)
Q_DECLARE_METATYPE(google::protobuf::MethodOptions)
Q_DECLARE_METATYPE(google::protobuf::UninterpretedOption)
Q_DECLARE_METATYPE(google::protobuf::SourceCodeInfo)
Q_DECLARE_METATYPE(google::protobuf::GeneratedCodeInfo)
Q_DECLARE_METATYPE(google::protobuf::DescriptorProto::ExtensionRange)
Q_DECLARE_METATYPE(google::protobuf::DescriptorProto::ReservedRange)
Q_DECLARE_METATYPE(google::protobuf::EnumDescriptorProto::EnumReservedRange)
Q_DECLARE_METATYPE(google::protobuf::UninterpretedOption::NamePart)
Q_DECLARE_METATYPE(google::protobuf::SourceCodeInfo::Location)
Q_DECLARE_METATYPE(google::protobuf::GeneratedCodeInfo::Annotation)
