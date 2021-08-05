#include "requests.h"
#include "storer_p.h"

#define must(val) if (!val) { return false; }

namespace Chometz
{

Object::~Object() { }

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

error::~error() { }

bool error::load(Loader& s)
{
    must(Object::doLoad(s))
    must(s.has({"code", "message"}))

    code_ = s.load("code").toInt();
    message_ = s.load("message").toString();

    return true;
}

ok::~ok() { }
void ok::store(Storer& s) const { Object::doStore(s); }
bool ok::load(Loader& s) { must(Object::doLoad(s)); return true; }

start::~start() { }
void start::store(Storer& s) const { Object::doStore(s); }
bool start::load(Loader& s) { must(Object::doLoad(s)); return true; }

};
