#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
using namespace std;
#include "Product.h"

class Admin{

private:
    string username;
    string password;
    ProductList catalogue;

public:
    Admin() {
        username = "root";
        password = "admin";
    }

    // Admin login verification
    void adminLogin() {
        string user, pass;
        cout << "\n==== Admin Login ====\n";
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;
        if(user == username && pass == password){
            cout << "Admin login successful!\n";
        }
        else{
            cout << "Invalid admin credentials!\n";
        
        }
    }

    // Admin Menu
    void adminMenu(){
        int choice;

        do{

            cout << "\n======= ADMIN MENU =======\n";
            cout << "1. Add Product\n";
            cout << "2. View Products\n";
            cout << "3. Process Orders\n";
            cout << "4. Log out\n";
            cout << "Enter choice: ";

            cin >> choice;

            switch(choice){
 
                case 1:{
                    int id;
                    string name;
                    double price;
                    
                    cout << "Adding product...\n";
                   
                        cout << "Enter Product ID: ";
                        cin >> id;
                    
                        cout << "Enter Product Name: ";
                        cin >> name;
                    
                        cout << "Enter Price: ";
                        cin >> price;
                    
                        Product p(id, name, price);
                    
                        catalogue.addProduct(p);
                    
                        cout << "Product added successfully!\n";
                }
                
                    break;
                case 2:
                    cout << "Viewing products. ..\n";
                    catalogue.displayProducts ();
                    break;
                case 3:
                    processOrders();
                    break;
                case 4:
                    cout << "Logging out...\n";
                    break;
                default:
                    cout << "Invalid option!\n";
            }

        }while(choice != 4);
    }

    // Process orders
    void processOrders(){ 
        cout << "\nProcessing next order from queue...\n";
    }


};
#endif
