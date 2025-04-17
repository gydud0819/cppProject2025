#include "Player.h"

void Player::ChangePlayerImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1])
{
	for (int y = 0; y < IMAGEHEIGHT; y++)
	{
		for (int x = 0; x < IMAGEWIDTH + 1; x++)
		{
			this->Image[y][x] = Image[y][x];
		}
	}
}

void Player::ShowPlayerImage(int& posX, int& posY)
{
	for (int y = 0; y < IMAGEHEIGHT; y++)
	{
		for (int x = 0; x < IMAGEWIDTH + 1; x++)
		{
			GoToXY(posX + x, posY + y);
			cout << Image[y][x];
		}
		cout << endl;
	}
}

bool Player::IsFight(int x, int y)
{
	if (x >= 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::SetPlayerBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1], int& posX, int& posY)
{
	ChangePlayerImage(Image);
	if (posX >= 30)
		posX = 30;
	else
		posX++;
	ShowPlayerImage(posX, posY);
}

