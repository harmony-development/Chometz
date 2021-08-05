#pragma once

#include <QString>
#include <QSharedPointer>

#define create_id(num) public: static constexpr int ID = num;\
public: int getID() const override { return ID; }

#define returns(t) public: using ResultType = t; using SResultType = SRef<t>;

#define null_load_store void store(Storer& s) const override { Object::doStore(s); } \
bool load(Loader& s) override { return Object::doLoad(s); }

namespace Chometz {

template<typename T>
using Ref = const T&;

template<typename T>
using SRef = QSharedPointer<T>;

class Storer;
class Loader;

#define pub public:
#define priv private:

// The base class of all objects in Chometz.
class Object
{
protected:
    void doStore(Storer&) const;
    bool doLoad(Loader&);
public:
    virtual ~Object() = 0;

    virtual int getID() const = 0;
    virtual void store(Storer&) const = 0;
    virtual bool load(Loader&) = 0;
};

class Function : public Object
{
};

class ok final : public Object
{
    create_id(5);
    virtual ~ok() override;

    pub void store(Storer&) const override;
    pub bool load(Loader&) override;
};

class error final : public Object
{
    create_id(6);
    virtual ~error() override;

    pub qint32 code_ = 0;
    pub QString message_;

    pub error(qint32 code, QString message) : code_(code), message_(message) { }

    pub void store(Storer&) const override;
    pub bool load(Loader&) override;
};

class Update : public Object
{
};

class start final : public Function
{
    create_id(4);
    returns(ok);
    virtual ~start() override;

    pub void store(Storer&) const override;
    pub bool load(Loader&) override;
};

}
