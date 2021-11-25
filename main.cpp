/*
    Temporary main file for testing the user code.
*/

#include <iostream>

#include "user.h"

int main() {
    std::cout << "Testing\n";
    User user;
    user.Register("morgen", "pass");
    return 0;
}