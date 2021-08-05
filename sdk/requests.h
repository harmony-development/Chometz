#pragma once

#include <QString>

#define create_id(num) static constexpr int ID = num;\
int getID() const override { return ID; }

namespace Chometz {

template<typename T>
using Ref = const T&;

template<typename T>
using OwnedRef = std::unique_ptr<T>;

class Storer;

// The base class of all objects in Chometz.
class Object
{
public:
    virtual int getID() const = 0;
    virtual void store(Storer&) const = 0;
};

class Function : public Object
{
};

class Update : public Object
{
};

}
