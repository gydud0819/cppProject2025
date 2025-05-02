#pragma once
#include "DataHandler.h"

class Player
{
	int str;
	int dex;
	int intel;
	int luk;
public:
	Player() : str(0), dex(0), intel(0), luk(0) {}

	void UpGrade(UpgradeType type, int amount);
	void UpGrade(Item& item);

	void ShowPlayerInfo()
	{
		cout << "STR : " << str << endl;
		cout << "DEX : " << dex << endl;
		cout << "INT : " << intel << endl;
		cout << "LUK : " << luk << endl;
	}
};

