#pragma once
#include "DataHandler.h"

class Shop
{
private:
	DataHandler loader;
	Item items[MAX_ITEMS];
	int count;
public:
	Shop() : count(0)
	{
		LoadItems("data.txt");
	}

	/*Shop(const string& filename) : count(0)
	{
		LoadItems(filename);
	}*/

	bool LoadItems(const string& filename);

	void ShowItems();

	Item& GetITems(int index)
	{
		return items[index];
	}
	
};

