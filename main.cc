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
  cout<<"Great, let's get you logged in.\n";
  cout<<"Enter username: ";
  cin>>LoginUsername;
  if(LoginUsername == "EXIT") {goodbye();}
  cout<<"Enter password: ";
  cin>>LoginPassword;
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
          string username;
          cout<<"Great, let's make a new account.\n";
          cout<<"Enter new username: ";
          cin>>username;
          // rt: EXIT
          if (username == "EXIT") {goodbye();}

          string password;
          cout<< "Enter password: ";
          cin>>password;
          if (password == "EXIT") {goodbye();}
        }
        // rt: EXIT
        if (b == "EXIT") {goodbye();}
     }
    // rt: Yes I do have an account
    if (answer == "y"){ Login();}

    // rt: EXIT
    if (answer == "EXIT") {goodbye();}
    
    // rt: BACK
    if (answer == "BACK")
     {
      
     }
    
 }