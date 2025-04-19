#pragma once
#include "Common.h"
#include "Image.h"

struct Enemy
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

	Enemy(int HP, int AP, int DEF, int skill, string name, char Image[IMAGEHEIGHT][IMAGEWIDTH + 1], BattleState battleState)
		: HP(HP), AP(AP), DEF(DEF), skill(skill), name(name), battleState(battleState)
	{
		posX = 60;
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

	// 기능을 만들기 위한 선언 함수
	void ChangeImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);
	void ShowImage();

	// 조건에 해당하는 기능
	bool IsBattle();
	bool IsWalk();
	bool IsIdle();

	// 기능을 조합해서 하나의 새로운 기능으로 표현하는 함수
	void SetBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);

	// 전투를 위한 기능
	void Attacked(int damage);

	void Defence();
	//void MSkill(int damage);
};




