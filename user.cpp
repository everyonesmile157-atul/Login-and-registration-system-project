#include "user.h"
#include<cctype>
#include<fstream>
#include<sstream>
#include<iostream>

using namespace std;

// Create username conditions
bool user::validateUsername(string username) {

    if(userName.empty()) {
        cout<<"Username cannot be empty"<<endl;
        return false;
    }

    if(userName.length() < 4) {
        cout<<"Enter minimum 4 characters"<<endl;
        return false;
    }

    if(username.length() > 20) {
        cout<<"Character length should be less than 20"<<endl;
        return false;
    }

    for (char ch : userName) {
        if( ch == ' ') {
            cout<<"Spaces are not allowed"<<endl;
            return false;
        }

        if(!isalnum(ch)) {
            cout<<"Only letters and Numbers are allowed"<<endl;
            return false;
        }
    }

    return true;
}

// Create password conditions
bool user::validatepassword( string password ) {

    if (password.empty()) {
        cout << "Password cannot be empty"<<endl;
        return false;
    }

    if (password.length() < 6) {
        cout << "Password must be at least 6 characters long"<<endl;
        return false;
    }

    if (password.length() > 20) {
        cout << "Password cannot be more than 20 characters"<<endl;
        return false;
    }

    bool hasLetter = false;
    bool hasDigit = false;

    for (char ch : password) {

        if (ch == ' ') {
            cout << "Spaces are not allowed in password"<<endl;
            return false;
        }

        if (isalpha(ch))
            hasLetter = true;

        if (isdigit(ch))
            hasDigit = true;
    }

    if (!hasLetter) {
        cout << "At least one alphabet"<<endl;
        return false;
    }

    if (!hasDigit) {
        cout << "At least one digit"<<endl;
        return false;
    }

    return true;
}

// check username existence
bool user::usernameExists( string userName) {
    ifstream file("userDetails.csv");

    string line;
    getline(file , line);

    while(getline(file, line)) {

        stringstream ss(line);

        string Username;
        string Password;

        getline(ss, Username, ',');
        getline(ss, Password, ',');

        if(Username == userName) {
            return true;
        }
    }

    file.close();

    return false;
}

// function for register user
void user::registerUser() {

    while(true) {

        cout<<"Create Username : ";
        cin>>userName;

        if(!validateUsername(userName)) {
            cout<<"Create Valid Username with Our conditions"<<endl;
            continue;
        }

        if(usernameExists(userName)) {
            cout<<"Username Already exits Create different"<<endl;
            continue;
        }

        break;
    }

    do {
        cout<<"Enter password : ";
        cin>>password;

    } while(!validatepassword(password));

    ofstream file("userDetails.csv", ios::app);

    file
        <<userName<<','
        <<password<<endl;

    file.close();

    cout<<"Registration Successful"<<endl;
}

// function for login user
bool user::loginUser() {

    string enterUsername;
    string enterPassword;

    cout<<"Enter Your Username : ";
    cin>>enterUsername;

    cout<<"Enter Password : ";
    cin>>enterPassword;

    ifstream file("userDetails.csv");

    string line;
    getline(file, line);

    while(getline(file, line)) {

        stringstream ss(line);

        string Username;
        string Password;

        getline(ss, Username , ',');
        getline(ss, Password, ',');

        if(enterUsername == Username  && enterPassword == Password) {

            cout<<"Login successfully compleated"<<endl;
            file.close();
            return true;
        }
    }

    file.close();
    cout<<"Invalid Username or Password"<<endl;
    return false;
}