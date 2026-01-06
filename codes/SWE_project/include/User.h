#ifndef USER_H
#define USER_H

// Libraries
#include <string>

using namespace std;


class User
{
private:
    int id;
    string userName;
    string password;


public:
        // Constructor
        User(int _id, string _userName, string _password){
            this->id = _id;
            this->userName = _userName;
            this->password = _password;
        }

        // Setters & Getters

        void setID(int _id){
            this->id = _id;
        }

        int getID(){
            return this->id;
        }

        void setUserName(string _userName){
            this->userName = _userName;
        }

        string getUserName(){
            return this->userName;
        }

          void setPassword(string _password){
            this->password = _password;
        }

        string getPassword(){
            return this->password;
        }

        virtual void login() = 0;

        virtual ~User() {}


};

#endif // USER_H
