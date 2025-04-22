#pragma once
#include <iostream>

/*
* Player 클래스 안에서 사용되는 Money
  플레이어가 돈을 사용하거나 벌어오는 기능
*/

class GameMomey
{
public:
	void Use();
	void Add();
};

class Gem
{
public:
	void Use();
	void Add();
};

// 아이템을 구입한다.
// Player.Use();
class Money
{
private:
	GameMomey gameMoney;
	Gem gem;
public:
	void Use();
	void Add();
};

