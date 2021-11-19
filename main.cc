#include <iostream>

using namespace std;

int main()
 {
  string answer;
  cout<<"Hello! Welcome to our T-shirt shop.\n";
  cout<<"We have a variety of Brands and colors at cheap prices to choose from.\n";
  cout<<"Do you have an account with us? ";
  cin>>answer;
    if (answer == "no")
     {
        string b;
        cout<<"Would you like to create an account? ";
        cin>>b;
        if (b == "no")
        {
        return 0;
        }
        if (b == "yes")
        {
        string username;
        cout<<"Splendid!\n";
        cout<<"Enter new username: ";
        cin>>username;
        }
     }
    // rt: Yes I do have an account
    if (answer == "yes")
     {
        cout<<"Login";
     }
 }