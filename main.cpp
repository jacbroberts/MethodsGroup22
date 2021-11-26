/*
    Temporary main file for testing the user code.
*/

#include <iostream>

#include "user.h"

int main() {
    std::cout << "Testing\n";
    User user;
    //user.Register("testing", "testPassword", "w", "M", "Test Address 1515", "1515");
    //user.Register("morgen", "pass", "Morgen", "M", "Address", "CCN");

    user.Login("morgen", "pass");

    if(user.GetIsLoggedIn()) {
        std::cout << "Logged in successfully!\n";
    }

    user.EditPayment("New Credit card number");
    //user.DeleteUser();
    user.EditShipping("New Address");
    return 0;
}