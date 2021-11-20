#pragma once

class History
{
private:
    string user;
    string items_ids[];
    int quantities;
    string file_name;

public:
    History(string username, string items[]);
    
    void Display();
    void DeleteHistory();

};