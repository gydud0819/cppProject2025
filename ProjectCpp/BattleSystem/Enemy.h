#pragma once
#include "Common.h"
#include "Image.h"

enum TurnSystem
{
	PLAYER,

};

enum BattleState
{
	IDLE,
	MOVE,
	BATTLE
};

struct Enemy
{
	int HP;		// helthPoint
	int AP;		// attackPower
	int DEF;	// defencer
	string name;
	char Image[IMAGEHEIGHT][IMAGEWIDTH + 1];
	BattleState battleState;

	Enemy(int HP, int AP, int DEF, string name, char Image[IMAGEHEIGHT][IMAGEWIDTH + 1])
		: HP(HP), AP(AP), DEF(DEF), name(name)
	{
		for (int y = 0; y < IMAGEHEIGHT; y++)
		{
			for (int x = 0; x < IMAGEWIDTH + 1; x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}
	}

	// 기능을 만들기 위한 선언 함수
	void ChangeImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);
	void ShowImage(int& posX, int& posY);

	// 조건에 해당하는 기능
	bool IsBattle(int x, int y);
	bool IsWalk(int x, int y);
	bool IsIdle(int x, int y);

	// 기능을 조합해서 하나의 새로운 기능으로 표현하는 함수
	void SetBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1], int& posX, int& posY);
};


