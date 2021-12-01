/*
  Cart
  Description: provides functions for shopping cart
  Written by: Jacob Roberts
*/

#pragma once
#include <vector>
#include <string>
#include "history.h"
#include "inventory.h"

using std::string;
using std::vector;



class Cart
{
private:
    string username;
    vector<Inventory> items;
    vector<int> quantity;


public:

    Cart();
    Cart(string username);

    void setUsername(string username);

    void viewCart();
    bool addItem(Inventory item, int quantity = 1);
    bool changeQuantity(Inventory item, int quantity);
    bool removeItem(Inventory item);
    bool checkout(vector<Inventory> brands, vector<int>& decrements);



};
