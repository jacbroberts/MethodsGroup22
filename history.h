#pragma once
#include "cart.h"
#include "inventory.h"

using std::string;
using std::vector;

class History
{
private:
    string username;
    vector<string> items_ids;
    vector<int> quantities;
    string file_name;

public:
    History();
    History(string user);
    History(string user, vector<Inventory> items, vector<int> quantities);

    void setUsername(string user);

    void Display();
    void DeleteHistory();

};
