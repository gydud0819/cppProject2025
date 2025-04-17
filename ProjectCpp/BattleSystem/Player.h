#pragma once
#include "Common.h"
#include "Image.h"

struct Player		// 플레이어 구조체
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

	void ChangePlayerImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1]);	// 플레이어 이미지를 바꿔주는 함수
	void ShowPlayerImage(int& posX, int& posY);							// 플레이어 이미지를 보여주는 함수

	bool IsFight(int x, int y);

	void SetPlayerBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1], int& posX, int& posY);	// 플레이어의 이미지와 바꿔주는걸 모두 포함한 함수
};