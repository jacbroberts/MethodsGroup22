#pragma once

#include <string>

using std::string;

class Inventory
{
private:
	string itemID, itemBrand, itemType;
	int itemCount, itemPrice;

public:
	Inventory();
	int DecrementStock(int purchased);
	bool IsAvailable();
	string GetBrand();
	string GetType();
	string GetID();
	int GetCount();
	int GetPrice();
	void SetBrand(string brand);
	void SetType(string type);
	void SetID(string id);
	void SetCount(int count);
	void SetPrice(int price);
};
