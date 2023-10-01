//
// Created by Ani Hadagali on 13/09/23.
//

#include "User.h"
#include "bits/stdc++.h"
#include "SHA256.h"
#include "fstream"

using namespace std;

string User ::  HashPassword(string password) {
    string hashed_password = sha256(password);
    return hashed_password;
}
User :: User(string username, std::string password) : username(username) {
    password_hash = HashPassword(password);
}

bool User::Register() {
    ifstream usernameFile;
    usernameFile.open("usernames.txt");

    if(usernameFile.is_open()) {
        string line;
        while(getline(usernameFile,line)) {
            istringstream iss(line);
            string storedUsername;
            string storedPassword;
            iss >> storedUsername >> storedPassword;
            if(storedUsername == username) {
                usernameFile.close();
                return false;
            }
        }
        usernameFile.close();
    } else {
        cout << "Error in creating file...\n";
    }

    ofstream usernameFileOut;
    usernameFileOut.open("usernames.txt",ios::app);
    if(usernameFileOut.is_open()) {
        usernameFileOut << username << " " << password_hash << endl;
        usernameFileOut.close();
        return true;
    }
    else {
        cout << "Error in creating file\n";
    }
    return false;

}

bool User::Login(std::string username, std::string password) {

    ifstream passwordFile("usernames.txt");

    if(passwordFile.is_open()) {
        string line;
        while (getline(passwordFile,line)) {
            istringstream iss(line);
            string storedUsername;
            string storedPasswordHash;
            iss >> storedUsername >> storedPasswordHash;
            if(storedUsername == username) {
                string inputPasswordHash = sha256(password);
                if(inputPasswordHash == storedPasswordHash) {
                    passwordFile.close();
                    return true;
                }
                cout << "Password miss match\n";
                return false;
            }
            return false;
        }
        passwordFile.close();
    }
    return false;
}

