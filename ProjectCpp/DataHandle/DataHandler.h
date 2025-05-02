#pragma once
#include "Common.h"

const int MAX_ITEMS = 100;

enum UpgradeType
{
	STR, DEX, INTEL, LUK, NONE
};

struct ItemDataType
{
	UpgradeType type;
	int amount;

	ItemDataType()
	{
		type = UpgradeType::NONE;
		amount = 0;
	}

	ItemDataType(int typeCount, int amount) : amount(amount)
	{
		if (typeCount == 0)
		{
			type = UpgradeType::STR;
		}
		else if (typeCount == 1)
		{
			type = UpgradeType::DEX;
		}
		else if (typeCount == 2)
		{
			type = UpgradeType::INTEL;
		}
		else if (typeCount == 3)
		{
			type = UpgradeType::LUK;
		}
		else
		{
			type = UpgradeType::NONE;
		}
	}
};

// 가져올 데이터의 타입을 하나의 이름으로 가져오기 위해서 Item class를 구현했다.
class Item
{
public:
	int index;
	string name;
	int price;
	ItemDataType dataType;

public:
	Item() : index(0), name(""), price(0), dataType(ItemDataType()) {}
	Item(int index, string name, int price, ItemDataType dataType) : index(index), name(name), price(price), dataType(dataType) {}
	
};

class DataHandler
{
public:
	// filename으로부터 메모장을 열어서 가져온다, Items(메모장의 정보를 저장할 매개체)
	int LoadItems(const string& filename, Item items[]);	// 파일로부터 아이템을 가져오겠다라는 의미의 함수, Item을 배열로 가져온다. 

};

