#pragma once
#include "Shop.h"
#include "Player.h"

class GameManager	// player shop
{
	Player* player;
	Shop* shop;
public:
	GameManager()
	{
		player = new Player();
		shop = new Shop();
	}
};

