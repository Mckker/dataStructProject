#include <iostream>

#include "Register.h"
#include "Login.h"
#include "Admin.h"
#include "User.h"

using namespace std;

int main(){
    
    srand(time(0));

    int choice;

    Register reg;
    Login login;
    Admin admin;

    do{

        cout << "\n========== BrandEx System ==========\n";
        cout << "1. Register User\n";
        cout << "2. Login as User\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        User user;

        switch(choice){
        case 1:

            cout << "\n--- User Registration ---\n";

            reg.registerCustomer();
            reg.generateOtp();
            reg.verifyCustomer();
            reg.storeCustomerDetails();

            break;


        case 2:
            cout << "\n--- User Login ---\n";
            login.login();
            user.userMenu();
            break;
        case 3:
            cout << "\n--- Admin Login ---\n";
                admin.adminLogin();
                admin.adminMenu();
            break;
        case 4:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }

    }while(choice != 4);

    return 0;
};