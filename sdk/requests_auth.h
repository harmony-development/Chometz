#pragma once

#include "requests.h"

namespace Chometz {

class AuthState;

class updateAuthState final : public Update
{
public:
    create_id(0);

    SRef<AuthState> state;
};

class AuthState : public Object
{
};

class authStateLoggedOut final : public AuthState
{
public:
    create_id(1);

    null_load_store
};

class authStateLoginProcess final : public AuthState
{
public:
    create_id(2);

    null_load_store
};

class authStateLoggedIn final : public AuthState
{
public:
    create_id(3);

    null_load_store
};

}
