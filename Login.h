#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <string>
using namespace std;
#include "Register.h"
#include "Admin.h"
#include "User.h"

class Login {

private:
    string username;
    int passwordOtp;
    Register newCustomer;// register object to use methods.
    Admin admin;

public:
    //Default constructor
    Login() {
        username = "";
        passwordOtp = 0;
    }

    //primary constructor
    Login(string u, int otp, Register nc): newCustomer(nc){
        username = nc.getFirstName() + nc.getLastName();
        passwordOtp = nc.getOtp();
    }

    //setters and getters
    void setUsername(string u) {username = u;}
    void setPasswordOtp(int otp) {passwordOtp = otp;}
    string getUsername() {return username;}
    int getPasswordOtp() {return passwordOtp;}


    //function to check if the username and password are correct
    void login(){
        string inputUsername;
        int inputPassword;

        cout << "Enter username: ";
        cin >> inputUsername;
        cout << "Enter password: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == passwordOtp ) {
            cout << "Login successful!" << endl;
            newCustomer.displayCustomerDetails();
        } else {
            cout << "Login failed! Please try again." << endl;
        }
    }

    // after user enter otp for registration the user will be forced to change password.
    void changePassword() {
        int newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        passwordOtp = newPassword;
        cout << "Password changed successfully!" << endl;
    }
    //store Login information to a file
    void storeLogin(){
        
        

    }

};
#endif