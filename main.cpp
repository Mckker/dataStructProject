#include <iostream>
 
using namespace std;


class Register{
    private:
        string firstName, lastName, email, otpPass;
};
class User {
    private:
        string username,password;
    public:
        int option(int choice){

        }
};
class Login{};
class Admin : public User{};
class Customer : public User{};
int main() {

    int n = 1;
    while(n <= 100){
        std::cout << "Test" <<  n  <<" \n";
        n++;
    }
    return 0;
}
