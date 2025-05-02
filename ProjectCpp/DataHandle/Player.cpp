#include "Player.h"

void Player::UpGrade(UpgradeType type, int amount)
{
	if (type == STR)
	{
		str += amount;
	}
	else if (type == DEX)
	{
		dex += amount;
	}
	else if (type == INTEL)
	{
		intel += amount;
	}
	else if (type == LUK)
	{
		luk += amount;
	}
	else if (type == NONE)
	{
		return;
	}
}

void Player::UpGrade(Item& item)
{
	UpGrade(item.dataType.type, item.dataType.amount);
}


