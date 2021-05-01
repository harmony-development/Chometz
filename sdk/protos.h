#pragma once

#include "chat/v1/chat.hrpc.client.h"
#include "auth/v1/auth.hrpc.client.h"
#include "mediaproxy/v1/mediaproxy.hrpc.client.h"

#include "chat/v1/chat.pb.h"
#include "auth/v1/auth.pb.h"
#include "mediaproxy/v1/mediaproxy.pb.h"

#include "util.h"

#include <google/protobuf/util/json_util.h>

Q_DECLARE_METATYPE(protocol::auth::v1::AuthStep);

template<typename T>
QString messageToJSON(const T& msg)
{
    std::string jsonified;
    google::protobuf::util::Status status = google::protobuf::util::MessageToJsonString(msg, &jsonified, google::protobuf::util::JsonPrintOptions{});
    if (!status.ok()) {
        return QString::fromStdString(status.ToString());
    }
    return QString::fromStdString(jsonified);
}
