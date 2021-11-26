/*
  Cart
  Description: provides functions for shopping cart
  Written by: Jacob Roberts
*/

#pragma once
#include <vector>
#include <string>

using std::string;
using std::vector;

struct itemInfo
{
  string id;
  int quantity;
};

class Cart
{
private:
    string username;
    vector<itemInfo> items;

public:
    Cart(string username);

    void viewCart();

    bool addItem(string id, int quantity);
    bool removeItem(string id);

    bool checkout();

};
