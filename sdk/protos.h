#pragma once

#include <chat/v1/chat.hrpc.client.h>
#include <auth/v1/auth.hrpc.client.h>
#include <mediaproxy/v1/mediaproxy.hrpc.client.h>
#include <emote/v1/emote.hrpc.client.h>
#include <profile/v1/profile.hrpc.client.h>
#include <voice/v1/voice.hrpc.client.h>

#include <chat/v1/chat.pb.h>
#include <auth/v1/auth.pb.h>
#include <mediaproxy/v1/mediaproxy.pb.h>
#include <emote/v1/emote.pb.h>
#include <profile/v1/profile.pb.h>
#include <voice/v1/voice.pb.h>

#include "util.h"
#include "coroutine_integration.h"

#include <google/protobuf/util/json_util.h>

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
