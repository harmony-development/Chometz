#include "init_p.h"

#include "protos.h"

Init::Init()
{
    qRegisterMetaType<protocol::auth::v1::AuthStep>();
    qRegisterMetaType<protocol::chat::v1::Event>();
    qRegisterMetaType<protocol::chat::v1::Event::ActionPerformed>();
}