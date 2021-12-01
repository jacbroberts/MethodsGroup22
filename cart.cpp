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
  if(items.size() == 0)
  {
    cout << "Shopping Cart Empty" << endl;
  }
  else
  {
    cout << "Shopping Cart Items: " << endl;
  }
  for(int i = 0; i < items.size(); i++)
  {
    cout << "item id: " << items[i].GetID() << " quantity: " << quantity[i] << endl;
  }
}

void Cart::setUsername(string user)
{
  username = user;
}

bool Cart::addItem(Inventory item, int quantity)
{
  //todo: check if item is in inventory and quantity available
  if(item.IsAvailable())
  {
    if(item.GetCount() >= quantity)
    {
      //jr: check if item is already in cart, if so, add quantity to current Quantity
      bool itemInCart;
      for(int i = 0; i < items.size(); i++)
      {
        if(items[i].GetID() == item.GetID())
        {
          this->quantity[i] += quantity; //jr: increases quantity in inventory by amount given
          itemInCart = true;
        }
      }

      //if item is not in cart, add to cart with given quantity
      if (!itemInCart)
      {
        items.push_back(item);
        this->quantity.push_back(quantity);
      }


      return true;
    }
    else
    {
      return false;
    }
  }
  else return false;

}

bool Cart::changeQuantity(Inventory item, int quantity)
{
  //check if item is in Cart
  for(int i = 0; i < items.size(); i++)
  {
    if(items[i].GetID() == item.GetID())
    {
      //todo: check if quantity desired is available

      //jr: change item quantity
      this->quantity[i] = quantity;
      return true;
    }
  }
  return false;

}


bool Cart::removeItem(Inventory item)
{
  //if item is in cart, remove it
  for(int i = 0; i < items.size(); i++)
  {
    if(items[i].GetID() == item.GetID())
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
    items[i].DecrementStock(quantity[i]);
  }
  //jr: add items to user history
  History history(username, items, quantity);
  //jr: remove items from User's Cart
  items.clear();

  return true;
}
