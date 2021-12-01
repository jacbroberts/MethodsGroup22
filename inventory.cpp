#include "inventory.h"

Inventory::Inventory()
{
	itemID = "";
	itemBrand = "";
	itemType = "";
	itemCount = 0;
	itemPrice = 0;
}

int Inventory::DecrementStock(int purchased)
{
	this->itemCount = itemCount - purchased;
	return this->itemCount;
}

bool Inventory::IsAvailable()
{
	if (itemCount > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Inventory::GetBrand()
{
	return itemBrand;
}

string Inventory::GetType()
{
	return itemType;
}

string Inventory::GetID()
{
	return itemID;
}

int Inventory::GetCount()
{
	return itemCount;
}
int Inventory::GetPrice()
{
	return itemPrice;
}

void Inventory::SetBrand(string brand)
{
	itemBrand = brand;
}

void Inventory::SetType(string type)
{
	itemType = type;
}

void Inventory::SetID(string id)
{
	itemID = id;
}

void Inventory::SetCount(int count)
{
	itemCount = count;
}

void Inventory::SetPrice(int price)
{
	itemPrice = price;
}
