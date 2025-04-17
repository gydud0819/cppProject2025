#pragma once
#include "Common.h"
#include "Image.h"

struct Player
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

	void ShowPlayerImage(int& posX, int& posY);
};