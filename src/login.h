#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class LoginSystem {
public:
    void showMenu();
    bool registerUser();
    bool authenticateUser();
};

#endif
