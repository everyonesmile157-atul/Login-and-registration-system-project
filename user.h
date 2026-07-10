#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>

using namespace std;

class user {
    private:
        // class data members
        string userName;
        string password;

    public:

        // class member functions
        void registerUser();
        bool loginUser();
        bool usernameExists( string userName );
        bool validateUsername( string userName );
        bool validatepassword( string password );

};


#endif