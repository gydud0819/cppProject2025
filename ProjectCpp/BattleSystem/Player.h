#pragma once
#include "Common.h"
#include "Image.h"
#include "Enemy.h"

struct Enemy;

struct Player		// 플레이어 구조체
{
	int HP;		// helthPoint
	int AP;		// attackPower
	int DEF;	// defencer
	int skill;
	string name;
	char Image[IMAGEHEIGHT][IMAGEWIDTH + 1];
	BattleState battleState;

	int posX;
	int posY;

	bool isDeath;

	Player(int HP, int AP, int DEF, int skill, string name, char Image[IMAGEHEIGHT][IMAGEWIDTH + 1], BattleState battleState)
		: HP(HP), AP(AP), DEF(DEF), skill(skill), name(name), battleState(battleState)
	{
		posX = 10;
		posY = 10;

		isDeath = false;

		for (int y = 0; y < IMAGEHEIGHT; y++)
		{
			for (int x = 0; x < IMAGEWIDTH + 1; x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}
	}

	void ChangePlayerImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);	// 플레이어 이미지를 바꿔주는 함수
	void ShowPlayerImage();							// 플레이어 이미지를 보여주는 함수

	bool IsFight();
	bool IsWalk();
	bool IsIdle(int x, int y);

	void SetPlayerBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);	// 플레이어의 이미지와 바꿔주는걸 모두 포함한 함수

	// 플레이어가 전투에 필요한 기능
	void Attacked(int damage);
	void Defence();
	void UseItem(int Heal);
	void Skill(Enemy* slime, int damage);
};