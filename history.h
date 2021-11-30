#pragma once
#include "cart.h"

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
    History(string username);
    History(string username, vector<string> items, vector<int> quantities);

    void Display();
    void DeleteHistory();

};
