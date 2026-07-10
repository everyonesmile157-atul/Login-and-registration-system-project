#include "user.h"
#include<iostream>
#include<limits>
using namespace std;

int main() {

    user customer;

    int choice;

    while(true) {
    cout<<endl;
    cout<<"----------- welcome ----------------"<<endl;
    cout<<"Enter 1 for Register : "<<endl;
    cout<<"Enter 2 for Login : "<<endl;
    cout<<"Enter 3 for exit : "<<endl;
    cout<<endl;

    cout<<"Enter choice : ";
    cin>>choice;

        if (cin.fail()) {

            cout << "Please enter recommended choice only" <<endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(choice) {
            case 1:
                customer.registerUser();
                cout<<endl;
                break;

            case 2:
                customer.loginUser();
                cout<<endl;
                break;

            case 3:
                cout<<"Thank you"<<endl;
                return 0;

            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}