#include <iostream>

using namespace std;

void goodbye()
 {
   cout<<"\nJust T-Shirts says GOODBYE!\n";
   return;
 }

void Login()
 {
  string LoginUsername;
  string LoginPassword;
  // rt: username
  cout<<"Great, let's get you logged in.\n";
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
  cout<<"Hello! Welcome to our T-shirt shop.\n\n";
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
        }
        // rt: EXIT
        if (b == "EXIT") {goodbye();}
     }
    
    // rt: Yes I do have an account
    if (answer == "y"){ Login();}

    // rt: EXIT
    if (answer == "EXIT") {goodbye();}
    
    // rt: Welcome user what you wanna do
    string MainMenuOption;
    cout<<"Welcome " << username << " what would you like to do?\n\n";
    cout<<"Enter: ACCOUNTINFO\n";
    cout<<"To see information about your account\n\n";
    cout<<"Enter: CART\n";
    cout<<"To see your carts info\n\n";
    cout<<"Enter: INVENTORY\n";
    cout<<"To browse our inventory\n\n";
    cin>>MainMenuOption;

    // rt: ACCOUNTINFO
    if (MainMenuOption == "ACCOUNTINFO")
     {
       string AccountInfoOption;
       cout<<"This is where you can see information about your account\n\n";
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
       cout<<"To delete you account";
       cin>>AccountInfoOption;

       if (AccountInfoOption == "DETAILS")
        {
         // rt: go to details function
        }

       if (AccountInfoOption == "VIEWSHIPPING")
        {
         // rt: go to viewshipping information function
        }
       
       if (AccountInfoOption == "EDITSHIPPING")
        {
         // rt: go to edit shipping information function
        }

       if (AccountInfoOption == "VIEWPAYINFO")
        {
         // rt: go to view payment information function
        }

       if (AccountInfoOption == "EDITPAYINFO")
        {
         // rt: go to edit payment information function
        }

       if (AccountInfoOption == "HISTORY")
        {
         // rt: go to history function
        }
       
       if (AccountInfoOption == "LOGOUT")
        {
         // rt: go to logout function
         // rt: basically back to welcome? or just exit?
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
    
     }
    
    // rt: INVENTORY
    if (MainMenuOption == "INVENTORY")
     {
    
     }
    
    // rt: EXIT
    if (MainMenuOption == "EXIT") {goodbye();}
 }