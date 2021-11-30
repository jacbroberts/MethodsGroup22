#include <iostream>
#include "cart.h"

using namespace std;

int main()
 {
  string answer;
  cout<<"Hello! Welcome to our T-shirt shop.\n\n";
  cout<<"We have a variety of Brands and colors at cheap prices to choose from.\n\n";
  cout<<"Do you have an account with us? ";
  cin>>answer;
    if (answer == "no")
     {
        string b;
        cout << "Would you like to create an account? ";
        cin >> b;
        if (b == "no")
        {
         cout<<"Goodbye.";
         return 0;
        }
        if (b == "yes")
        {
          string username;

          cout<<"Splendid!\n";
          cout<<"Enter new username: ";
          cin>>username;

          Cart cart(username);
          History userHistory(username);

          string choice;
          while(true)
            {
              cout << "Enter Action: ";
              cin >> choice;
              if(choice == "add")
              {
                string id;
                int quantity;
                cout << "Enter id: ";
                cin.ignore();
                getline(cin, id);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << endl;
                cart.addItem(id, quantity);

              }
              if(choice == "remove")
              {
                string id;
                cout << "Enter id: ";
                cin.ignore();
                getline(cin, id);
                cart.removeItem(id);
                cout << "Item removed from Cart" << endl;
              }
              if(choice == "viewcart")
              {
                cart.viewCart();
              }
              if(choice == "viewhistory")
              {
                userHistory.Display();
              }
              if(choice == "checkout")
              {
                cart.checkout();
              }
              if(choice == "changequantity")
              {
                string id;
                int quantity;
                cout << "Enter id: ";
                cin.ignore();
                getline(cin, id);
                cout << "Quantity desired: ";
                cin >> quantity;
                cart.changeQuantity(id, quantity);
              }
            }


        }
     }
    // rt: Yes I do have an account
    if (answer == "yes")
    {
      cout << "Login" << endl;
    }


 }
