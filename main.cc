#include <iostream>
#include <stdlib.h>

using namespace std;

void goodbye()
 {
   cout<<"\nJust T-Shirts says GOODBYE!\n";
   exit(EXIT_FAILURE);
 }

void Login()
 {
  string LoginUsername;
  string LoginPassword;
  // rt: username
  cout<<"\nGreat, let's get you logged in.\n";
  cout<<"Enter username: ";
  cin>>LoginUsername;
  // rt: EXIT
  if(LoginUsername == "EXIT") {goodbye();}
  // rt: password
  cout<<"Enter password: ";
  cin>>LoginPassword;
  // rt: EXIT
  if(LoginPassword == "EXIT") {goodbye();}
 }

int main()
 {
  // rt: Welcome
  string answer;
  int cont;
  cout<<"##############################################";
  cout<<"\nHello! Welcome to our T-shirt shop.\n\n";
  cout<<"We only have T-shirts and the best T-shirts.\n\n";
  cout<<"Enter: EXIT\n";
  cout<<"To leave the site anytime\n\n";
  cout<<"Enter: BACK\n";
  cout<<"To go back a page anytime\n\n";
  cout<<"Do you have an account with us(y/n)? ";
  cin>>answer;
    // rt: No, I do NOT have an account
    if (answer == "n")
     {
        string b;
        cout<<"\nYou must have an account to proceed.\n";
        cout<<"Would you like to create an account(y/n)? ";
        cin>>b;
        // rt: if no i dont want to create an account
        if (b == "n")
         {
          cout<<"\nYou must have an account to proceed.\n";
          goodbye();
         }
        // rt: if yes i do want to create an account
        if (b == "y")
         {
          // rt: Create username
          string username;
          cout<<"Great, let's make a new account.\n";
          cout<<"Enter new username: ";
          cin>>username;
          // rt: EXIT
          if (username == "EXIT") {goodbye();}

          // rt: Create password
          string password;
          cout<< "Enter password: ";
          cin>>password;
          // rt: EXIT
          if (password == "EXIT") {goodbye();}

          // rt: move to login
          Login();
          cont = 1;
        }
        // rt: EXIT
        if (b == "EXIT") {goodbye();}
     }

    // rt: Yes I do have an account
    if (answer == "y")
     {
       Login();
       cont = 1;
     }

    // rt: EXIT
    if (answer == "EXIT") {goodbye();}

    if ( cont == 1)
    {
        // rt: Welcome user what you wanna do
        string MainMenuOption;
        cout<<"##############################################";
        cout<<"\nWelcome! What would you like to do?\n\n";
        cout<<"Enter: ACCOUNTINFO\n";
        cout<<"To see information about your account\n\n";
        cout<<"Enter: CART\n";
        cout<<"To see your carts info\n\n";
        cout<<"Enter: INVENTORY\n";
        cout<<"To browse our inventory\n\n";
        cout<<"Enter a option: ";
        cin>>MainMenuOption;
        cout<<"\n";

        // rt: ACCOUNTINFO
        if (MainMenuOption == "ACCOUNTINFO")
        {
        string AccountInfoOption;
        cout<<"##############################################";
        cout<<"\nThis is where you can see information about your account\n\n";
        cout<<"Enter: DETAILS\n";
        cout<<"To see your account\n\n";
        cout<<"Enter: VIEWSHIPPING\n";
        cout<<"To see your shipping information\n\n";
        cout<<"Enter: EDITSHIPPING\n";
        cout<<"To edit your shipping information\n\n";
        cout<<"Enter: VIEWPAYINFO\n";
        cout<<"To see your payment information\n\n";
        cout<<"Enter: EDITPAYINFO\n";
        cout<<"To edit your payment information\n\n";
        cout<<"Enter: HISTORY\n";
        cout<<"To view order history\n\n";
        cout<<"Enter: LOGOUT\n";
        cout<<"To logout of your account\n";
        cout<<"Enter: DELETE\n";
        cout<<"To delete you account\n\n";
        cout<<"Enter a option: ";
        cin>>AccountInfoOption;

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

            }

        // rt: go to delete account function
        if (AccountInfoOption == "DELETE")
            {

            }

        // rt: EXIT
        if(AccountInfoOption == "EXIT"){goodbye();}

        }

        // rt: CART
        if (MainMenuOption == "CART")
        {
        string CartOption;
        cout<<"##############################################";
        cout<<"\nThis is where you can see information about your cart\n\n";
        cout<<"Enter: CART\n";
        cout<<"To view your cart\n\n";
        cout<<"Enter: REMOVEITEM\n";
        cout<<"To remove an item from your cart\n\n";
        cout<<"Enter: ADDITEM\n";
        cout<<"To add an item to your cart\n\n";
        cout<<"Enter: QUANTITY\n";
        cout<<"To specify how much of an item to add\n\n";
        cout<<"Enter: CHECKOUT\n";
        cout<<"To complete purchase\n\n";
        cout<<"Enter a option: ";
        cin>>CartOption;

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

        // rt: EXIT
        if(CartOption == "EXIT"){goodbye();}

        }

        // rt: INVENTORY
        if (MainMenuOption == "INVENTORY")
        {
        string InvOption;
        cout<<"##############################################";
        cout<<"\nThis is where you can browse our inventory\n\n";
        cout<<"Enter: DISPLAY\n";
        cout<<"To see all of our stock\n\n";
        cout<<"Enter: DISPLAYBRAND <BrandName>\n";
        cout<<"To see all of our stock of a certain brand and the amount available\n\n";
        cout<<"Enter: DISPLAYTYPE\n";
        cout<<"To see items of a certain color and their amount in inventory\n\n";
        cout<<"Enter: DISPLAYITEM\n";
        cout<<"To see an item and how many are in stock\n\n";
        cout<<"Enter a option: ";

        cin>>InvOption;

        // rt: go to view entire inventory function
        if (InvOption == "DISPLAY")
            {

            }

        // rt: go to specifiy a brand function
        if (InvOption == "DISPLAYBRAND")
            {

            }

        // rt: go to a certain color function
        if (InvOption == "DISPLAYTYPE")
            {

            }

        // rt: go to certain item function
        if (InvOption == "DISPLAYITEM")
            {

            }

        // rt: EXIT
        if(InvOption == "EXIT"){goodbye();}

        }

        // rt: EXIT
        if (MainMenuOption == "EXIT") {goodbye();}

    }
    return 0;
 }
