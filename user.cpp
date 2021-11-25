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

bool User::OpenUserFileRead(std::ifstream &f, std::ostream &os){
    f.open(USER_FILE);
    if(!f.is_open()) {
        os << "File could not be opened.\n";
        return false; // File not opened
    }
    return true;
}

bool User::OpenUserFileAppend(std::ofstream &f, std::ostream &os){
    f.open(USER_FILE, std::ios_base::app);
    if(!f.is_open()) {
        os << "File could not be opened.\n";
        return false; // File not opened
    }
    return true;
}

bool User::Register(std::string username, std::string password) {
    if(loggedIn) {
        OutStream << "Registration failed: Already logged in. Logout first!\n";
        return false;
    }
    
    // Open user file
    std::ifstream userFile;
    if(!OpenUserFileRead(userFile, OutStream)) {
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
    bool userExists = false;
    std::string line;
    while(std::getline(userFile, line)) {
        if(line.substr(0, 5) == "user:") {
            size_t userEnd = line.find(":", 5);
            std::string currUsername = line.substr(5, userEnd-5);
            if(currUsername == username) {
                userExists = true;
                break;
            }
        }
    }
    if(userExists) {
        OutStream << "Registration failed: Username already taken!\n";
        return false;
    }

    // Create the user, and add it to the file

    // TODO: Create the cart

    // Open file with append
    userFile.close();
    std::ofstream userFileW;
    if(!OpenUserFileAppend(userFileW, OutStream)) {
        return false;
    }

    // Write to file
    userFileW << "user:" << username;
    userFileW << ":password:" << password;
    userFileW << ":firstname:" << " "; // Blank user info, til it is edited
    userFileW << ":lastname:" << " ";
    userFileW << ":shipping:" << " ";
    userFileW << ":payment:" << " ";
    userFileW << ":cartID:" << " " << '\n';

    userFileW.close();

    // Set user object's values
    username = username;
    password = password;
    loggedIn = true;
    return true;
}


bool User::Login(std::string username, std::string password) {
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

    // Open user file
    std::ifstream userFile;
    if(!OpenUserFileRead(userFile, OutStream)) {
        return false;
    }

    // Check if user is in the file
    bool userExists = false;
    std::string line;
    std::string realPassword;
    while(std::getline(userFile, line)) {
        if(line.substr(0, 5) == "user:") {
            size_t userEnd = line.find(":", 5);
            std::string currUsername = line.substr(5, userEnd-5);
            if(currUsername == username) {
                userExists = true;

                // Get the password from the file
                size_t passwordStart = line.find(":", userEnd+1);
                size_t passwordEnd = line.find(":", passwordStart+1);
                realPassword = line.substr(passwordStart+1, passwordEnd-passwordStart-1);
                break;
            }
        }
    }
    if(!userExists) {
        OutStream << "Login failed: No user exists with the given username!\n";
        return false;
    }

    // Compare password
    if(password != realPassword) {
        OutStream << "Login failed: Passwords do not match!\n";
        return false;
    }
    

    // Successfully logged in
    username = username;
    password = password;
    loggedIn = true;
    return true;
}

void User::Logout() {
    if(loggedIn) {
        loggedIn = false;
    }
}

bool User::GetIsLoggedIn() const {
    return loggedIn;
}