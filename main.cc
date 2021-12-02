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


bool Login(User &user)
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
        return true;
    }
    else {
        return false;
    }
}


bool Register(User &user)
{
    string username, password, firstname, lastname, shipping, payment;

    // Get user input
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter first name: ";
    cin >> firstname;
    cout << "Enter last name: ";
    cin >> lastname;
    cout << "Enter shipping address: ";;
    cin.ignore(1, '\n'); // Ignore last endline value
    getline(cin, shipping);
    cout << "Enter payment info (Credit card number, Debit, etc.): ";
    getline(cin, payment);



    if(user.Register(username, password, firstname, lastname, shipping, payment))
    {
        cout << "Successfully created new user!\n";
        return true;
    }
    else {
        return false;
    }

}

int main()
{
    //jar: initializing cart and History
    Cart userCart;
    History userHistory;

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
    while(true) {
        User user;
        string answer;
        int cont;
        int conttwo;
        while (answer != "y" && answer != "n" && answer != "EXIT")
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
            while (b != "y" && b != "n" && b != "EXIT")
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

                if(Register(user)) {
                    //cont = 1;
                    string a;
                    cout << "Would you like to login now? (y/n): ";
                    cin >> a;
                    if(a == "y" || a == "YES" || a == "yes" || a == "Yes") {
                        if(Login(user)) {
                            cont = 1;
                        }
                    }
                    else if(a == "EXIT") {
                        answer = "EXIT";
                    }
                    else {
                        continue;
                    }
                }
            }
            // rt: EXIT

            if (b == "EXIT") { goodbye(); }

        }


        // rt: Yes I do have an account
        if (answer == "y")
        {
            if(Login(user))
                cont = 1;
        }


        // rt: EXIT
        if (answer == "EXIT") { goodbye(); }

        if (cont == 1)
        {
            conttwo = 1;
            string MainMenuOption;
            //while (MainMenuOption != "ACCOUNTINFO" && MainMenuOption != "CART" && MainMenuOption != "INVENTORY" && MainMenuOption != "EXIT")
            string userGet;
            user.GetUsername(userGet);
            Cart userCart(userGet);
            History userHistory(userGet);

            while(MainMenuOption != "EXIT" && user.GetIsLoggedIn())
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

                    while(AccountInfoOption != "BACK" && user.GetIsLoggedIn())
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
                        cout << "To logout of your account\n\n";
                        cout << "Enter: DELETE\n";
                        cout << "To delete you account\n\n";
                        cout << "Select an option: ";
                        cin >> AccountInfoOption;
                        cout << "\n";
                        // rt: go to details function
                        if (AccountInfoOption == "DETAILS")
                        {

                        }

                        // rt: go to viewshipping information function
                        if (AccountInfoOption == "VIEWSHIPPING")
                        {
                            string shipping;

                            if(user.GetShipping(shipping)) {
                                std::cout << "Shipping Address: " << shipping << '\n';
                            }
                            else {
                                cout << "There was an error getting the user shipping info!\n";
                            }
                        }

                        // rt: go to edit shipping information function
                        if (AccountInfoOption == "EDITSHIPPING")
                        {
                            bool edit = true;

                            while(edit) { // Repeat until user confirms accuracy
                                // Get shipping info
                                string shipping;
                                cout << "Enter new shipping address: ";
                                cin.ignore(1, '\n'); // Ignore last endline value
                                getline(cin, shipping);

                                //Confirm shipping info
                                string confirm;
                                cout << "Is this information accurate?: ";
                                cin >> confirm;

                                if(confirm == "y" || confirm == "Y" || confirm == "Yes" || confirm == "YES" || confirm == "yes") { // Confirmed
                                    if(user.EditShipping(shipping)) {
                                        cout << "Updated shipping info.\n";
                                    }
                                    else {
                                        cout << "An error occurred while updating shipping info! Going back...\n";
                                    }
                                    edit = false;
                                }
                            }
                        }

                        // rt: go to view payment information function
                        if (AccountInfoOption == "VIEWPAYINFO")
                        {
                            string payment;

                            if(user.GetPayment(payment)) {
                                std::cout << "Payment Info: " << payment << '\n';
                            }
                            else {
                                cout << "There was an error getting the user payment info!\n";
                            }
                        }

                        // rt: go to edit payment information function
                        if (AccountInfoOption == "EDITPAYINFO")
                        {
                            bool edit = true;

                            while(edit) { // Repeat until user confirms accuracy
                                // Get shipping info
                                string payment;
                                cout << "Enter new payment info: ";
                                cin.ignore(1, '\n'); // Ignore last endline value
                                getline(cin, payment);

                                //Confirm shipping info
                                string confirm;
                                cout << "Is this information accurate?: ";
                                cin >> confirm;

                                if(confirm == "y" || confirm == "Y" || confirm == "Yes" || confirm == "YES" || confirm == "yes") { // Confirmed
                                    if(user.EditPayment(payment)) {
                                        cout << "Updated payment info.\n";
                                    }
                                    else {
                                        cout << "An error occurred while updating payment info! Going back...\n";
                                    }
                                    edit = false;
                                }
                            }
                        }

                        // rt: go to history function
                        if (AccountInfoOption == "HISTORY")
                        {
                          userHistory.Display();
                        }

                        // rt: go to logout function
                        // rt: basically back to welcome? or just exit?
                        if (AccountInfoOption == "LOGOUT")
                        {
                            user.Logout();
                        }

                        // rt: go to delete account function
                        if (AccountInfoOption == "DELETE")
                        {
                            if(user.DeleteUser()) {
                                cout << "User deleted.\n";
                            }
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
                    //while (CartOption != "CART" && CartOption != "REMOVEITEM" && CartOption != "ADDITEM" && CartOption != "QUANTITY" && CartOption != "CHECKOUT" && CartOption != "EXIT")
                    while(CartOption != "BACK")
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
                        cout << "\n";

                        // rt: go to view cart function
                        if (CartOption == "CART")
                        {
                          userCart.viewCart();
                        }

                        // rt: go to remove an item function
                        if (CartOption == "REMOVEITEM")
                        {
                          string itemBrand;

                          cout << "Enter Item Brand: ";
                          cin >> itemBrand;


                          if(itemBrand == "GUCCI")
                          {
                            userCart.removeItem(Gucci);
                          }
                          else if(itemBrand == "WALMART")
                          {
                            userCart.removeItem(Walmart);
                          }
                          else if(itemBrand == "HAILSTATE")
                          {
                            userCart.removeItem(State);
                          }
                          else
                          {
                            cout << "Not an inventory item." << endl;
                          }



                        }


                        // rt: go to add an item function
                        if (CartOption == "ADDITEM")
                        {
                          string itemBrand;
                          int itemQuantity;
                          cout << "Enter Item Brand: ";
                          cin >> itemBrand;
                          cout << "Enter Desired Quantity: ";
                          cin >> itemQuantity;
                          if(itemQuantity > 0)
                          {
                            if(itemBrand == "GUCCI")
                            {
                              userCart.addItem(Gucci, itemQuantity);
                            }
                            else if(itemBrand == "WALMART")
                            {
                              userCart.addItem(Walmart, itemQuantity);
                            }
                            else if(itemBrand == "HAILSTATE")
                            {
                              userCart.addItem(State, itemQuantity);
                            }
                            else
                            {
                              cout << "Not an inventory item." << endl;
                            }
                          }
                          else
                          {
                            cout << "Not a valid quantity." << endl;
                          }
                        }

                        // rt: go to quantity function
                        if (CartOption == "QUANTITY")
                        {
                          bool inCart;
                          string itemBrand;
                          int itemQuantity;
                          cout << "Enter Item Brand: ";
                          cin >> itemBrand;
                          cout << "Enter Desired Quantity: ";
                          cin >> itemQuantity;
                          if(itemQuantity > 0)
                          {
                            if(itemBrand == "GUCCI")
                            {
                              inCart = userCart.changeQuantity(Gucci, itemQuantity);
                            }
                            else if(itemBrand == "WALMART")
                            {
                              inCart = userCart.changeQuantity(Walmart, itemQuantity);
                            }
                            else if(itemBrand == "HAILSTATE")
                            {
                              inCart = userCart.changeQuantity(State, itemQuantity);
                            }
                            else
                            {
                              cout << "Not an inventory item." << endl;
                            }
                          }
                          else
                          {
                            cout << "Not a valid quantity." << endl;
                          }
                          if(!inCart)
                          {

                          }

                        }

                        // rt: go to edit checkout function
                        if (CartOption == "CHECKOUT")
                        {
                          vector<Inventory> brands;
                          brands.push_back(Gucci);
                          brands.push_back(Walmart);
                          brands.push_back(State);


                          vector<int> decrements;
                          bool checkoutStatus;
                          checkoutStatus = userCart.checkout(brands, decrements);
                          if(checkoutStatus)
                          {
                            cout << "Checkout Successful" << endl;

                            // Decrement stock of items after purchase
                            Gucci.DecrementStock(decrements[0]);
                            Walmart.DecrementStock(decrements[1]);
                            State.DecrementStock(decrements[2]);

                            // Updating inventory file
                            ofstream outfile;
                            outfile.open("inventory.txt");
                            outfile << Gucci.GetID() << endl;
                            outfile << Gucci.GetCount() << endl;
                            outfile << Walmart.GetID() << endl;
                            outfile << Walmart.GetCount() << endl;
                            outfile << State.GetID() << endl;
                            outfile << State.GetCount() << endl;
                            outfile.close();
                          }
                          else
                          {
                            cout << "Checkout Unsuccessful" << endl;
                          }
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
                    while(InvOption != "BACK")
                    {
                        cout << "\n##############################################";
                        cout << "\nThis is where you can browse our inventory\n\n";
                        cout << "We carry Gucci, Walmart Brand, and Hail State merch\n";
                        cout << "Which brand would you like view? (Enter: GUCCI, WALMART, HAILSTATE, or ALL) \n";
                        cout << "Select an option: ";

                        cin >> InvOption;

                        cout << "\n";
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
                        if (InvOption == "HAILSTATE")
                        {
                            cout << State.GetBrand() << ":   In Stock: " << State.GetCount() << "   Price: $" << State.GetPrice() << endl;
                        }

                        // jdr: view price and stock of all items
                        if (InvOption == "ALL")
                        {
                            cout << Gucci.GetBrand() << ":   In Stock: " << Gucci.GetCount() << "   Price: $" << Gucci.GetPrice() << endl;
                            cout << Walmart.GetBrand() << ":   In Stock: " << Walmart.GetCount() << "   Price: $" << Walmart.GetPrice() << endl;
                            cout << State.GetBrand() << ":   In Stock: " << State.GetCount() << "   Price: $" << State.GetPrice() << endl;
                        }

                        // rt: BACK
                        if (InvOption == "BACK") {}

                        // rt: EXIT
                        if (InvOption == "EXIT") { goodbye(); }

                    }
                }

                // rt: EXIT
                if (MainMenuOption == "EXIT") { goodbye(); }
            }
        }
    }
    return 0;
} ;
