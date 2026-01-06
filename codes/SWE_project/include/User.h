#ifndef USER_H
#define USER_H
#include "DB_Manipulation.h"
#include <string>
#include <iostream>


using namespace std;

class User
{
private:
    int id;
    string userName;
    string password;

public:
    // Constructor
    User(int _id, string _userName, string _password) {
        this->id = _id;
        this->userName = _userName;
        this->password = _password;
    }


    virtual ~User() {}

    // --- Setters ---
    void setID(int _id) {
        this->id = _id;
    }

    void setUserName(string _userName) {
        this->userName = _userName;
    }

    void setPassword(string _password) {
        this->password = _password;
    }

    // --- Getters ---
    int getID() const {
        return this->id;
    }

    string getUserName() const {
        return this->userName;
    }

    string getPassword() const {
        return this->password;
    }


    virtual bool login(sqlite3* db, const string& username, const string& password) = 0;
};

#endif // USER_H
