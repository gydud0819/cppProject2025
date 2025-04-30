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

	void ResultPhase();	// 결과를 보여주는 함수

public:
	GameManager()
	{
		player == new Player();
	}
	void Play();

protected:

};

