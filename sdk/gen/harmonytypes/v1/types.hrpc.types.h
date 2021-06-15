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
#include "harmonytypes/v1/types.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::HarmonyMethodMetadata)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Override)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Action)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::EmbedHeading)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::EmbedField)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Embed)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Attachment)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Metadata)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::ContentText)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::ContentEmbed)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::ContentFiles)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Content)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Message)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Error)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Action::Button)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Action::Dropdown)
Q_DECLARE_METATYPE(protocol::harmonytypes::v1::Action::Input)
