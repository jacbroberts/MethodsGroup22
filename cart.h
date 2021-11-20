#pragma once

class Cart
{
private:
    string username;
    string items[];

public:
    Cart(string username);
    
    void viewCart();
    
    bool addItem(string id);
    bool removeItem(string id);

    bool checkout();

};