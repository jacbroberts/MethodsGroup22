/*
  Cart
  Description: provides functions for shopping cart
  Written by: Jacob Roberts
*/

#pragma once
#include <vector>
#include <string>
#include "history.h"

using std::string;
using std::vector;



class Cart
{
private:
    string username;
    vector<string> items;
    vector<int> quantity;


public:


    Cart(string username);

    void viewCart();

    bool addItem(string id, int quantity);
    bool removeItem(string id);

    bool checkout();



};
