/*
    User
    Description: Provides the user class which handles login and account info.
    Written by: Morgen Malinoski
*/

#include <string>

class User {
    // User details
    std::string username;
    std::string password;
    bool loggedIn;

    // Account details
    std::string firstName;
    std::string lastName;
    std::string shippingAddress;
    std::string paymentInfo;
    int cartID;
public:
    User();

    // Register, login, logout
    bool Register(std::string username, std::string password);
    bool Login(std::string username, std::string password);
    void Logout();

    bool DeleteUser();
    bool EditShipping(std::string shipping);
    bool EditPayment(std::string paymentInfo);
};