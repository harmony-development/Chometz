#pragma once

#include "requests.h"

namespace Chometz {

class updateAuthState final : public Update
{
public:
    create_id(0);
    void store(Storer&) const override;
};

class AuthState : public Object
{
};

class authStateLoggedOut final : public AuthState
{
public:
    create_id(1);
    void store(Storer&) const override;
};

class authStateLoginProcess final : public AuthState
{
public:
    create_id(2);
    void store(Storer&) const override;
};

class authStateLoggedIn final : public AuthState
{
public:
    create_id(3);
    void store(Storer&) const override;
};

}
