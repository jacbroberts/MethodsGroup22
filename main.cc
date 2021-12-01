#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "inventory.h"
#include "history.h"
#include "cart.h"
#include "user.h"

using namespace std;

void goodbye()
{
    cout << "\nJust T-Shirts says GOODBYE!\n";
    exit(EXIT_FAILURE);
}

void Login(User &user)
{
    string LoginUsername;
    string LoginPassword;
    // rt: username
    cout << "\nGreat, let's get you logged in.\n";
    cout << "Enter username: ";
    cin >> LoginUsername;
    // rt: EXIT
    if (LoginUsername == "EXIT") { goodbye(); }
    // rt: password
    cout << "Enter password: ";
    cin >> LoginPassword;
    // rt: EXIT
    if (LoginPassword == "EXIT") { goodbye(); }

    if(user.Login(LoginUsername, LoginPassword)) 
    {
        cout << "Successfully logged in as " << LoginUsername << '\n';
    }
}

void Register(User &user) 
{
    string username, password, firstname, lastname, shipping, payment;

    // Get user input
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << " Enter first name: ";
    cin >> firstname;
    cout << "Enter last name: ";
    cin >> lastname;
    cout << "Enter shipping address: ";
    cin >> shipping;
    cout << "Enter payment info (Credit card number, Debit, etc.): ";
    cin >> payment;


    if(user.Register(username, password, firstname, lastname, shipping, payment))
    {
        cout << "Successfully created new user!\n";
    }
}

int main()
{
    // jdr: Initializing the Inventory
    Inventory Gucci, Walmart, State;
    string id, stock;
    int count;
    ifstream invinit;
    invinit.open("inventory.txt");
    if (invinit.is_open())
    {
        getline(invinit, id);
        getline(invinit, stock);
        count = stoi(stock);
        Gucci.SetBrand("Gucci");
        Gucci.SetType("T-Shirt");
        Gucci.SetID(id);
        Gucci.SetPrice(169);
        Gucci.SetCount(count);

        getline(invinit, id);
        getline(invinit, stock);
        count = stoi(stock);
        Walmart.SetBrand("Walmart");
        Walmart.SetType("T-Shirt");
        Walmart.SetID(id);
        Walmart.SetPrice(6);
        Walmart.SetCount(count);

        getline(invinit, id);
        getline(invinit, stock);
        count = stoi(stock);
        State.SetBrand("Hail State");
        State.SetType("T-shirt");
        State.SetID(id);
        State.SetPrice(69);
        State.SetCount(count);

        invinit.close();
    }
    else
    {
        cout << "System could not load properly.\n";
    }

    // rt: Welcome
    User user;
    string answer;
    int cont;
    int conttwo;
    while (answer != "y" && answer != "n")
    {
        cout << "##############################################";
        cout << "\nHello! Welcome to our T-shirt shop.\n\n";
        cout << "We only have T-shirts and the best T-shirts.\n\n";
        cout << "Enter: EXIT\n";
        cout << "To leave the site anytime\n\n";
        cout << "Enter: BACK\n";
        cout << "To go back a page anytime\n\n";
        cout << "Do you have an account with us(y/n)? ";
        cin >> answer;
    }
    // rt: No, I do NOT have an account
    if (answer == "n")
    {
        string b;
        while (b != "y" && b != "n")
        {
            cout << "\nYou must have an account to proceed.\n";
            cout << "Would you like to create an account(y/n)? ";
            cin >> b;
        }
        // rt: if no i dont want to create an account
        if (b == "n")
        {
            cout << "\nYou must have an account to proceed.\n";
            goodbye();
        }
        // rt: if yes i do want to create an account
        if (b == "y")
        {
            // rt: Create username
            string username;
            cout << "Great, let's make a new account.\n";

            // rt: move to login
            //Login();
            Register(user);
            cont = 1;
        }
        // rt: EXIT
        if (b == "EXIT") { goodbye(); }
    }

    // rt: Yes I do have an account
    if (answer == "y")
    {
        Login(user);
        cont = 1;
    }

    // rt: EXIT
    if (answer == "EXIT") { goodbye(); }

    if (cont == 1)
    {
        conttwo = 1;
        while (conttwo == 1)
        {
            string MainMenuOption;
            while (MainMenuOption != "ACCOUNTINFO" && MainMenuOption != "CART" && MainMenuOption != "INVENTORY" && MainMenuOption != "EXIT")
            {
                // rt: Welcome user what you wanna do
                cout << "##############################################";
                cout << "\nWelcome! What would you like to do?\n\n";
                cout << "Enter: ACCOUNTINFO\n";
                cout << "To see information about your account\n\n";
                cout << "Enter: CART\n";
                cout << "To see your carts info\n\n";
                cout << "Enter: INVENTORY\n";
                cout << "To browse our inventory\n\n";
                cout << "Select an option: ";
                cin >> MainMenuOption;
                cout << "\n";

                // rt: ACCOUNTINFO
                if (MainMenuOption == "ACCOUNTINFO")
                {
                    string AccountInfoOption;
                    while (AccountInfoOption != "DETAILS" && AccountInfoOption != "VIEWSHIPPING" && AccountInfoOption != "EDITSHIPPING" && AccountInfoOption != "VIEWPAYINFO" && AccountInfoOption != "EDITPAYINFO" && AccountInfoOption != "HISTORY" && AccountInfoOption != "LOGOUT" && AccountInfoOption != "DELETE" && AccountInfoOption != "EXIT")
                    {
                        cout << "##############################################";
                        cout << "\nThis is where you can see information about your account\n\n";
                        cout << "Enter: DETAILS\n";
                        cout << "To see your account\n\n";
                        cout << "Enter: VIEWSHIPPING\n";
                        cout << "To see your shipping information\n\n";
                        cout << "Enter: EDITSHIPPING\n";
                        cout << "To edit your shipping information\n\n";
                        cout << "Enter: VIEWPAYINFO\n";
                        cout << "To see your payment information\n\n";
                        cout << "Enter: EDITPAYINFO\n";
                        cout << "To edit your payment information\n\n";
                        cout << "Enter: HISTORY\n";
                        cout << "To view order history\n\n";
                        cout << "Enter: LOGOUT\n";
                        cout << "To logout of your account\n";
                        cout << "Enter: DELETE\n";
                        cout << "To delete you account\n\n";
                        cout << "Select an option: ";
                        cin >> AccountInfoOption;

                        // rt: go to details function
                        if (AccountInfoOption == "DETAILS")
                        {

                        }

                        // rt: go to viewshipping information function
                        if (AccountInfoOption == "VIEWSHIPPING")
                        {

                        }

                        // rt: go to edit shipping information function
                        if (AccountInfoOption == "EDITSHIPPING")
                        {

                        }

                        // rt: go to view payment information function
                        if (AccountInfoOption == "VIEWPAYINFO")
                        {

                        }

                        // rt: go to edit payment information function
                        if (AccountInfoOption == "EDITPAYINFO")
                        {

                        }

                        // rt: go to history function
                        if (AccountInfoOption == "HISTORY")
                        {

                        }

                        // rt: go to logout function
                        // rt: basically back to welcome? or just exit?      
                        if (AccountInfoOption == "LOGOUT")
                        {
                            user.Logout();
                            AccountInfoOption = "BACK";
                        }

                        // rt: go to delete account function
                        if (AccountInfoOption == "DELETE")
                        {
                            user.DeleteUser();
                        }

                        // rt: BACK
                        if (AccountInfoOption == "BACK") {}

                        // rt: EXIT
                        if (AccountInfoOption == "EXIT") { goodbye(); }

                    }
                }
                // rt: CART
                if (MainMenuOption == "CART")
                {
                    string CartOption;
                    while (CartOption != "CART" && CartOption != "REMOVEITEM" && CartOption != "ADDITEM" && CartOption != "QUANTITY" && CartOption != "CHECKOUT" && CartOption != "EXIT")
                    {
                        cout << "##############################################";
                        cout << "\nThis is where you can see information about your cart\n\n";
                        cout << "Enter: CART\n";
                        cout << "To view your cart\n\n";
                        cout << "Enter: REMOVEITEM\n";
                        cout << "To remove an item from your cart\n\n";
                        cout << "Enter: ADDITEM\n";
                        cout << "To add an item to your cart\n\n";
                        cout << "Enter: QUANTITY\n";
                        cout << "To specify how much of an item to add\n\n";
                        cout << "Enter: CHECKOUT\n";
                        cout << "To complete purchase\n\n";
                        cout << "Select an option: ";
                        cin >> CartOption;

                        // rt: go to view cart function
                        if (CartOption == "CART")
                        {

                        }

                        // rt: go to remove an item function
                        if (CartOption == "REMOVEITEM")
                        {

                        }

                        // rt: go to add an item function
                        if (CartOption == "ADDITEM")
                        {

                        }

                        // rt: go to quantity function
                        if (CartOption == "QUANTITY")
                        {

                        }

                        // rt: go to edit checkout function
                        if (CartOption == "CHECKOUT")
                        {

                        }

                        // rt: BACK
                        if (CartOption == "BACK") {}

                        // rt: EXIT
                        if (CartOption == "EXIT") { goodbye(); }
                    }
                }

                // rt: INVENTORY
                if (MainMenuOption == "INVENTORY")
                {
                    string InvOption;
                    cout << "##############################################";
                    cout << "\nThis is where you can browse our inventory\n\n";
                    cout << "We carry Gucci, Walmart Brand, and Hail State merch\n";
                    cout << "Which brand would you like view? (Enter: GUCCI, WALMART, or HAIL STATE) \n";
                    cout << "Enter a option: ";

                    cin >> InvOption;

                    // jdr: view price and stock of Gucci
                    if (InvOption == "GUCCI")
                    {
                        cout << Gucci.GetBrand() << ":   In Stock: " << Gucci.GetCount() << "   Price: $" << Gucci.GetPrice() << endl;
                    }

                    // jdr: view price and stock of Walmart
                    if (InvOption == "WALMART")
                    {
                        cout << Walmart.GetBrand() << ":   In Stock: " << Walmart.GetCount() << "   Price: $" << Walmart.GetPrice() << endl;
                    }

                    // jdr: view price and stock of State
                    if (InvOption == "HAIL STATE")
                    {
                        cout << State.GetBrand() << ":   In Stock: " << State.GetCount() << "   Price: $" << State.GetPrice() << endl;
                    }

                    // rt: EXIT
                    if (InvOption == "EXIT") { goodbye(); }

                }

                // rt: EXIT
                if (MainMenuOption == "EXIT") { goodbye(); }
            }
        }
    }
    return 0;
} ;

