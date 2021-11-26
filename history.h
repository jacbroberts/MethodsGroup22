#pragma once
#include "cart.h"
class History
{
private:
    string user;
    std::vector<std::string> items_ids;
    int quantities;
    string file_name;

public:
    History(string username, std::vector<std::string>);

    void Display();
    void DeleteHistory();

};
