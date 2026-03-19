#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
#include "Product.h"

class User{
private:
    string fname;
    string lname;
    string email;
    string otp;
    ProductList catalogue;


public:
    //Default constructor   
    User() {
        fname = "";
        lname = "";
        email = "";
        otp = "";
    }

    //primary constructor
    User(string f, string l, string e) {
        fname = f;
        lname = l;
        email = e;
        otp = "";
    }

    //setters and getters
    void setFirstName(string f) {fname = f;}
    void setLastName(string l) {lname = l;}
    void setEmail(string e) {email = e;}
    void setOtp(string o) {otp = o;}
    string getFirstName() {return fname;}
    string getLastName() {return lname;}
    string getEmail() {return email;}
    string getOtp() {return otp;}

//function to display user details
    void displayUserDetails() {
        cout << "User Details: " << endl;
        cout << "First Name: " << fname << endl;
        cout << "Last Name: " << lname << endl;
        cout << "Email: " << email << endl;
    }
    // user functions
    void browseCatalogue(){ 
        cout<<"The products available in store are: \n";
        catalogue.displayProducts();

    }
    void addToCart(){
        int productID;
        int qty;

        cout << "Enter Product ID to add: ";
        cin >> productID;
        cout << "Enter quantity: ";
        cin >> qty;
        cout << "Product " << productID << " added to cart (Qty: " << qty << ")\n";

    }
    void changeQuantity(){
        int productID;
        int newQty;

        cout << "Enter Product ID: ";
        cin >> productID;
        cout << "Enter new quantity: ";
        cin >> newQty;
        cout << "Quantity updated for Product " << productID << endl;
    }

    void userMenu(){

        int choice;

        do{
            cout << "\n===========USER MENU===========\n";
            cout << "1. Browse Product Catalogue\n";
            cout << "2. Add Product to Cart\n";
            cout << "3. Change Cart Quantity\n";
            cout << "4. Logout\n";
            cout << "Enter choice: ";

            cin >> choice;

            switch(choice){

                case 1:
                    browseCatalogue();
                    break;

                case 2:
                    addToCart();
                    break;

                case 3:
                 changeQuantity();
                    break;

                case 4:
                    cout << "Logging out...\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        }while(choice != 4);
    }

};
#endif
