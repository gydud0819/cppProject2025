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

	// ����� ����� ���� ���� �Լ�
	void ChangeImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);
	void ShowImage();

	// ���ǿ� �ش��ϴ� ���
	bool IsBattle();
	bool IsWalk();
	bool IsIdle();

	// ����� �����ؼ� �ϳ��� ���ο� ������� ǥ���ϴ� �Լ�
	void SetBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);

	// ������ ���� ���
	void Attacked(int damage);

	void Defence();
	//void MSkill(int damage);
};




