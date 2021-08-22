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
#include "auth/v1/auth.pb.h"
#include <QWebSocket>
#include "google/protobuf/timestamp.pb.h"
#include "google/protobuf/empty.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/descriptor.pb.h"
#include "harmonytypes/v1/types.pb.h"
Q_DECLARE_METATYPE(protocol::auth::v1::BeginAuthResponse)
Q_DECLARE_METATYPE(protocol::auth::v1::Session)
Q_DECLARE_METATYPE(protocol::auth::v1::AuthStep)
Q_DECLARE_METATYPE(protocol::auth::v1::NextStepRequest)
Q_DECLARE_METATYPE(protocol::auth::v1::StepBackRequest)
Q_DECLARE_METATYPE(protocol::auth::v1::StreamStepsRequest)
Q_DECLARE_METATYPE(protocol::auth::v1::FederateRequest)
Q_DECLARE_METATYPE(protocol::auth::v1::FederateReply)
Q_DECLARE_METATYPE(protocol::auth::v1::KeyReply)
Q_DECLARE_METATYPE(protocol::auth::v1::LoginFederatedRequest)
Q_DECLARE_METATYPE(protocol::auth::v1::TokenData)
Q_DECLARE_METATYPE(protocol::auth::v1::AuthStep::Choice)
Q_DECLARE_METATYPE(protocol::auth::v1::AuthStep::Form)
Q_DECLARE_METATYPE(protocol::auth::v1::AuthStep::Waiting)
Q_DECLARE_METATYPE(protocol::auth::v1::AuthStep::Form::FormField)
Q_DECLARE_METATYPE(protocol::auth::v1::NextStepRequest::Choice)
Q_DECLARE_METATYPE(protocol::auth::v1::NextStepRequest::FormFields)
Q_DECLARE_METATYPE(protocol::auth::v1::NextStepRequest::Form)
