//
// Created by Ani Hadagali on 13/09/23.
//

#ifndef MUSIC_PLAYER_SYSTEM_USER_H
#define MUSIC_PLAYER_SYSTEM_USER_H
#include "bits/stdc++.h"

using namespace std;
class User {
private:
    string username,password_hash;
public:
    User(string username, string password);
    bool Login(string username ,string password);
    bool Register();
    string HashPassword(string password);
};


#endif //MUSIC_PLAYER_SYSTEM_USER_H
