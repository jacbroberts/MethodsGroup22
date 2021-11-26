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
    cout << items[i] << endl;
  }
}

bool Cart::addItem(string id, int quantity)
{

  //if item is in inventory, add to shopping cart
  //for testing, just add id into cart
  for(int i = quantity; i > 0; i--)
  {
    items.push_back(id);
  }

  return true;
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
    //DecrementStock(items[i], 1);
  }
    //add items to user history


  return true;
}
