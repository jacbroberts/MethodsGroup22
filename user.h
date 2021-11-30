/*
    User
    Description: Provides the user class which handles login and account info.
    Written by: Morgen Malinoski
*/

#pragma once

#include <string>
#include <ostream>
#include <fstream>
#include <iostream>

static const std::string USER_FILE = "users.dat";
static auto &OutStream = std::cout;

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

    bool OpenUserFileRead(std::ifstream &f, std::ostream &os) const;
    bool OpenUserFileWrite(std::ofstream &f, std::ostream &os, bool append) const;
    bool LoadUserFromFile(std::string inUsername, std::string &outPassword, std::string &outFirstName, std::string &outLastName, 
        std::string &outShipping, std::string &outPayment, int &outCartID) const;
    bool GetUserExists(std::string inUsername) const;
    bool ExportUserToString(std::string &outString) const;
    bool UpdateUserToFile();
public:
    User();

    // Register, login, logout
        bool Register(std::string inUsername, std::string inPassword, std::string inFirstName, std::string inLastName,
            std::string inShippingAddress, std::string inPaymentInfo);
    bool Login(std::string inUsername, std::string inPassword);
    void Logout();

    bool DeleteUser();
    bool EditShipping(std::string inShipping);
    bool EditPayment(std::string inPaymentInfo);

    // Getters
    bool GetIsLoggedIn() const;
};