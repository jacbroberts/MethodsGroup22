#pragma once
#include "cart.h"
#include "inventory.h"

using std::string;
using std::vector;

class History
{
private:
    string user;
    vector<string> items_ids;
    vector<int> quantities;
    string file_name;

public:
    History()
    {
      user = "";
      file_name = "";
    }
    History(string username);
    History(string username, vector<Inventory> items, vector<int> quantities);

    void setUser(string username);

    void Display();
    void DeleteHistory();

};
