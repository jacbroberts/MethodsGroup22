/*
  Cart
  Description: provides functions for shopping cart
  Written by: Jacob Roberts
*/

#include "cart.h"
#include <iostream>


using std::cout;
using std::endl;

Cart::Cart(string username)
{
  this->username = username;
  vector<string> items;
}

void Cart::viewCart()
{
  cout << "Shopping Cart Items: " << endl;
  for(int i = 0; i < items.size(); i++)
  {
    cout << "item id: " << items[i] << " quantity: " << quantity[i] << endl;
  }
}

bool Cart::addItem(string id, int quantity)
{
  //todo: check if item is in inventory and quantity available


  items.push_back(id);
  this->quantity.push_back(quantity);


  return true;
}

bool Cart::changeQuantity(string id, int quantity)
{
  //check if item is in Cart
  for(int i = 0; i < items.size(); i++)
  {
    if(items[i] == id)
    {
      //todo: check if quantity desired is available
      //change item quantity
      this->quantity[i] = quantity;
      return true;
    }
  }
  return false;

}


bool Cart::removeItem(string id)
{
  //if item is in cart, remove it
  for(int i = 0; i < items.size(); i++)
  {
    if(items[i] == id)
    {
      items.erase(items.begin() + i);
    }
  }
  return true;
}

bool Cart::checkout()
{
  //checkout items in cart:
    //decrement items in inventory

  for(int i = 0; i < items.size(); i++)
  {
    //DecrementStock(items[i], quantity[i]);
  }
    //add items to user history
  History history(username, items, quantity);
  items.clear();

  return true;
}
