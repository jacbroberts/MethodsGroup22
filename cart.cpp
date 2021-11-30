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

  //jr: check if item is already in cart, if so, add quantity to current Quantity
  bool itemInInventory;
  for(int i = 0; i < items.size(); i++)
  {
    if(items[i] == id)
    {
      this->quantity[i] += quantity; //jr: increases quantity in inventory by amount given
      itemInInventory = true;
    }
  }

  //if item is not in cart, add to cart with given quantity
  if (!itemInInventory)
  {
    items.push_back(id);
    this->quantity.push_back(quantity);
  }


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

      //jr: change item quantity
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
      quantity.erase(quantity.begin() + i);
    }
  }
  return true;
}

bool Cart::checkout()
{
  for(int i = 0; i < items.size(); i++)
  {
    //jr: decrement the items in inventory by given amount
    //DecrementStock(items[i], quantity[i]);
  }
  //jr: add items to user history
  History history(username, items, quantity);
  //jr: remove items from User's Cart
  items.clear();

  return true;
}
