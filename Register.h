#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Register{
private:
    string fName;
    string lName;
    string email;
    int otp;
public:

    //Default constructor
    Register() {
        fName = "";
        lName = "";
        otp = 0 ;
        email = "";
    }

    // primary constructors
    Register(string f, string l, string e) {
        fName = f;
        lName = l;
        email = e;
        otp = 0;
    }

    //setters and getters
    void setFirstName(string f) {fName = f;}
    void setLastName(string l) {lName = l;}
    void setOtp(int o) {otp = o;}
    void setEmail(string e) {email = e;}
    string getFirstName() {return fName;}
    string getLastName() {return lName;}
    int getOtp() {return otp;}
    string getEmail() {return email;}

    //function to register a new customer
    void registerCustomer() {
        cout << "Enter first name: ";
        cin >> fName;
        cout << "Enter last name: ";
        cin >> lName;
        cout << "Enter email: ";
        cin >> email;
        cout << "Registration successful!" << endl;
    }

    //verify registered customer
    void verifyCustomer() {
        int inputOtp;
        cout << "Enter OTP to verify: ";
        cin >> inputOtp;

        if (inputOtp == otp) {
            cout << "Verification successful!" << endl;
        } else {
            cout << "Verification failed! Please try again." << endl;
        }
    }

    // display registered customer detail.
    void displayCustomerDetails() {
        cout << "Customer Details: " << endl;
        cout << "First Name: " << fName << endl;
        cout << "Last Name: " << lName << endl;
        cout << "Email: " << email << endl;
    }

    // gernate OTP for customer registration
    void generateOtp() {
        otp = (rand() % 10000); // Generate a random 4-digit OTP
        cout << "Check your email for OTP, this is to be used at Login: " << otp << endl;
    }

    // store verified customer details in a file
    void storeCustomerDetails() {
        ofstream outFile("customers.txt", ios::app);
        if (outFile.is_open()) {
            outFile << fName << " " << lName << " " << email << " " << otp << endl;
            outFile.close();
            cout << "Customer details stored successfully!" << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

};
#endif