/*
    Temporary main file for testing the user code.
*/

#include <iostream>

#include "user.h"

int main() {
    std::cout << "Testing\n";
    User user;
    user.Register("morgen", "pass");

    user.Register("morgen:", "password:");
    user.Login("morgen", "pass");

    if(user.GetIsLoggedIn()) {
        std::cout << "Logged in successfully!\n";
    }
    return 0;
}