#ifndef AUTH_H
#define AUTH_H
#include <string>
#include "utility/constants.h"

class Auth {
    public:
        bool login(string username, string password, login_type login_type_t);
};

#endif