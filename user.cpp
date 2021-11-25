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