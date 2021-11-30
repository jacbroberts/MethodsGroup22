/*
    User
    Description: Provides the user class which handles login and account info.
    Written by: Morgen Malinoski
*/

#include "user.h"

#include <fstream>

User::User()
: loggedIn(false)
{
    // If user file does not exist, make it
    std::ifstream userFile(USER_FILE);
    if(!userFile.good()) { // File does not exist
        std::ofstream newUserFile(USER_FILE);
        newUserFile.close();
    }
}

bool User::OpenUserFileRead(std::ifstream &f, std::ostream &os) const {
    f.open(USER_FILE);
    if(!f.is_open()) {
        os << "File could not be opened.\n";
        return false; // File not opened
    }
    return true;
}

bool User::OpenUserFileWrite(std::ofstream &f, std::ostream &os, bool append) const {
    if(append)
        f.open(USER_FILE, std::ios_base::app);
    else
        f.open(USER_FILE);
    if(!f.is_open()) {
        os << "File could not be opened.\n";
        return false; // File not opened
    }
    return true;
}

bool User::LoadUserFromFile(std::string inUsername, std::string &outPassword, std::string &outFirstName, std::string &outLastName, 
std::string &outShipping, std::string &outPayment, int &outCartID) const {
    // Open user file
    std::ifstream userFile;
    if(!OpenUserFileRead(userFile, OutStream)) {
        return false;
    }

    // Check if user is in the file
    bool userExists = false;
    std::string line;
    while(std::getline(userFile, line)) {
        if(line.substr(0, 5) == "user:") {
            size_t userEnd = line.find(":", 5);
            std::string currUsername = line.substr(5, userEnd-5);
            if(currUsername == inUsername) {
                userExists = true;

                // Get the password from the file
                size_t passwordStart = line.find(":", userEnd+1);
                size_t passwordEnd = line.find(":", passwordStart+1);
                outPassword = line.substr(passwordStart+1, passwordEnd-passwordStart-1);

                // Get Firstname
                size_t firstNameStart = line.find(":", passwordEnd+1);
                size_t firstNameEnd = line.find(":", firstNameStart+1);
                outFirstName = line.substr(firstNameStart+1, firstNameEnd-firstNameStart-1);

                // Get Lastname
                size_t lastNameStart = line.find(":", firstNameEnd+1);
                size_t lastNameEnd = line.find(":", lastNameStart+1);
                outLastName = line.substr(lastNameStart+1, lastNameEnd-lastNameStart-1);

                // Get Shipping address
                size_t shippingStart = line.find(":", lastNameEnd+1);
                size_t shippingEnd = line.find(":", shippingStart+1);
                outShipping = line.substr(shippingStart+1, shippingEnd-shippingStart-1);
                
                // Get Payment Info
                size_t paymentStart = line.find(":", shippingEnd+1);
                size_t paymentEnd = line.find(":", paymentStart+1);
                outPayment = line.substr(paymentStart+1, paymentEnd-paymentStart-1);

                // Get cart ID
                size_t cartStart = line.find(":", paymentEnd+1);
                outCartID = std::atoi(line.substr(cartStart).c_str());
                break;
            }
        }
    }
    userFile.close();
    return userExists;
}

bool User::GetUserExists(std::string inUsername) const {
    std::string p,f,l,s,y;
    int c;
    return LoadUserFromFile(inUsername, p,f,l,s,y,c); 
}

bool User::ExportUserToString(std::string &outString) const {
    if(loggedIn) {
        outString = "user:" + username + ":password:" + password + ":firstname:" + firstName + ":lastname:" + lastName+ ":shipping:" + shippingAddress+ ":payment:" + paymentInfo + ":cartID:" + " " + "\n";
        return true;
    }
    else {
        return false;
    }
}

bool User::UpdateUserToFile() { 
    // Open user file
    std::ifstream userFile;
    if(!OpenUserFileRead(userFile, OutStream)) {
        return false;
    }

    // Keep everything except current user in file, which is updated at the end
    std::string contents;
    std::string line;
    while(std::getline(userFile, line)) {
        if(line.substr(0, 5) == "user:") {
            size_t userEnd = line.find(":", 5);
            std::string currUsername = line.substr(5, userEnd-5);
            if(currUsername != username) {
                contents += line + '\n';
            }
        }
    }
    userFile.close();

    std::ofstream userFileW;
    if(!OpenUserFileWrite(userFileW, OutStream, false)) {
        return false;
    }

    // Write to file
    userFileW << contents;

    std::string currUser;
    if(!ExportUserToString(currUser)) {
        return false;
    }

    userFileW << currUser;

    userFileW.close();

    return true;
}

bool User::Register(std::string inUsername, std::string inPassword, std::string inFirstName, std::string inLastName, std::string inShippingAddress, std::string inPaymentInfo) {
    if(loggedIn) {
        OutStream << "Registration failed: Already logged in. Logout first!\n";
        return false;
    }

    // Verify username is valid
    if(username.find(":") != std::string::npos){ // Can't have :, which is the file delimeter
        OutStream << "Registration failed: Invalid username!\n";
        return false;
    }

    // Verify password is valid
    if(password.find(":") != std::string::npos){ // Can't have :, which is the file delimeter
        OutStream << "Registration failed: Invalid password!\n";
        return false;
    }

    // Check if user is in the file
    bool userExists = GetUserExists(username);
    if(userExists) {
        OutStream << "Registration failed: Username already taken!\n";
        return false;
    }

    // Create the user, and add it to the file

    // TODO: Create the cart

    // Open file with append
    std::ofstream userFileW;
    if(!OpenUserFileWrite(userFileW, OutStream, true)) {
        return false;
    }

    // Set user object's values
    username = inUsername;
    password = inPassword;
    firstName = inFirstName;
    lastName = inLastName;
    shippingAddress = inShippingAddress;
    paymentInfo = inPaymentInfo;
    loggedIn = true;

    // Write to file
    userFileW << "user:" << username;
    userFileW << ":password:" << password;
    userFileW << ":firstname:" << firstName; // Blank user info, til it is edited
    userFileW << ":lastname:" << lastName;
    userFileW << ":shipping:" << shippingAddress;
    userFileW << ":payment:" << paymentInfo;
    userFileW << ":cartID:" << " " << '\n';

    userFileW.close();
    return true;
}


bool User::Login(std::string inUsername, std::string inPassword) {
    if(loggedIn) {
        OutStream << "Login failed: Already logged in. Logout first!\n";
        return false;
    }

    // Verify username is valid
    if(username.find(":") != std::string::npos){ // Can't have :, which is the file delimeter
        OutStream << "Login failed: Invalid username!\n";
        return false;
    }

    // Verify password is valid
    if(password.find(":") != std::string::npos){ // Can't have :, which is the file delimeter
        OutStream << "Login failed: Invalid password!\n";
        return false;
    }

    std::string realPassword, lFirstname, lLastname, lShipping, lPayment;
    int lCartID;
    bool userExists = LoadUserFromFile(inUsername, realPassword, lFirstname, lLastname, lShipping, lPayment, lCartID);
    if(!userExists) {
        OutStream << "Login failed: No user exists with the given username!\n";
        return false;
    }

    // Compare password
    if(inPassword != realPassword) {
        OutStream << "Login failed: Passwords do not match!\n";
        return false;
    }

    // Successfully logged in
    username = inUsername;
    password = inPassword;
    loggedIn = true;
    firstName = lFirstname;
    lastName = lLastname;
    shippingAddress = lShipping;
    paymentInfo = lPayment;
    cartID = lCartID;

    return true;
}

void User::Logout() {
    if(loggedIn) {
        loggedIn = false;
    }
}

bool User::DeleteUser() {
    if(!loggedIn) {
        OutStream << "Delete User Failed: Must login first!\n";
        return false;
    }
    loggedIn = false; // Logout

    // Open user file
    std::ifstream userFile;
    if(!OpenUserFileRead(userFile, OutStream)) {
        return false;
    }

    // Keep everything except current user in file
    std::string contents;
    std::string line;
    while(std::getline(userFile, line)) {
        if(line.substr(0, 5) == "user:") {
            size_t userEnd = line.find(":", 5);
            std::string currUsername = line.substr(5, userEnd-5);
            if(currUsername != username) {
                contents += line + '\n';
            }
        }
    }
    userFile.close();

    std::ofstream userFileW;
    if(!OpenUserFileWrite(userFileW, OutStream, false)) {
        return false;
    }

    // Write to file
    std::cout << username;
    userFileW << contents;
    userFileW.close();

    return true;
}

bool User::EditShipping(std::string inShipping) {
    if(!loggedIn) {
        OutStream << "Edit Shipping Failed: Must be logged in!\n";
        return false;
    }

    shippingAddress = inShipping;

    if(!UpdateUserToFile()) {
        std::cout << "Failed Editing Shipping: Could not update to user file!\n";
        return false;
    }
    return true;
}

bool User::EditPayment(std::string inPaymentInfo) {
    if(!loggedIn) {
        OutStream << "Edit Payment Failed: Must be logged in!\n";
        return false;
    }

    paymentInfo = inPaymentInfo;
    if(!UpdateUserToFile()) {
        OutStream << "Failed Editing Payment: Could not update to user file!\n";
        return false;
    }

    return true;
}

bool User::GetIsLoggedIn() const {
    return loggedIn;
}