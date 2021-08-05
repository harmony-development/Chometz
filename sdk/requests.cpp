#include "requests.h"
#include "storer_p.h"

#define must(val) if (!val) { return false; }

namespace Chometz
{

void Object::doStore(Storer& s) const
{
    s.store("id", getID());
}

bool Object::doLoad(Loader& s)
{
    if (s.load("id") != getID()) {
        return false;
    }

    return true;
}

void error::store(Storer& s) const
{
    Object::doStore(s);

    s.store("code", code_);
    s.store("message", message_);
}

bool error::load(Loader& s)
{
    must(Object::doLoad(s))
    must(s.has({"code", "message"}))

    code_ = s.load("code").toInt();
    message_ = s.load("message").toString();

    return true;
}

bool ok::load(Loader& s)
{
    must(Object::doLoad(s))

    return true;
}

bool start::load(Loader& s)
{
    must(Object::doLoad(s))

    return true;
}

};
