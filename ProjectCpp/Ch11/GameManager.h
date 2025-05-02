/*
* 주제	: 게임 매니저로 게임 구현
*/
#pragma once
#include "Runner.h"

class GameManager
{
private:
	Player* player;
	void ShowTitle();
	void ShopPhase();	// 서브?
	void GamePhase();

public:
	GameManager()
	{
		player = new Player();
	}
	void Play();

protected:

};

