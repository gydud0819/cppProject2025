#include "Player.h"

void Player::ShowPlayerImage(int& posX, int& posY)
{
	for (int y = 0; y < IMAGEHEIGHT; y++)
	{
		for (int x = 0; x < IMAGEWIDTH + 1; x++)
		{
			GoToXY(posX, posY);
			cout<<Image[y][x];
		}
		cout << endl;
	}
}
