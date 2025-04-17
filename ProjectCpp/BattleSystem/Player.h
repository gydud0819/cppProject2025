#pragma once
#include "Common.h"
#include "Image.h"

struct Player		// �÷��̾� ����ü
{
	string name;
	char Image[IMAGEHEIGHT][IMAGEWIDTH + 1];

	Player(string name, char Image[IMAGEHEIGHT][IMAGEWIDTH + 1])
		: name(name)
	{
		for (int y = 0; y < IMAGEHEIGHT; y++)
		{
			for (int x = 0; x < IMAGEWIDTH + 1; x++)
			{
				this->Image[y][x] = Image[y][x];
			}
		}
	}

	void ChangePlayerImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);	// �÷��̾� �̹����� �ٲ��ִ� �Լ�
	void ShowPlayerImage(int& posX, int& posY);							// �÷��̾� �̹����� �����ִ� �Լ�

	bool IsFight(int x, int y);

	void SetPlayerBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1], int& posX, int& posY);	// �÷��̾��� �̹����� �ٲ��ִ°� ��� ������ �Լ�
};