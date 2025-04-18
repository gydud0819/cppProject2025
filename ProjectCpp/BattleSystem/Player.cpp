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

void Player::ShowPlayerImage()
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

bool Player::IsFight()
{
	if (posX >= 30)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::IsWalk()
{
	if (posX >= 29)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::SetPlayerBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1])
{
	ChangePlayerImage(Image);
	if (posX >= 30)
		posX = 30;
	else
		posX++;
	ShowPlayerImage();
}

void Player::Attacked(int damage)
{
	damage = damage - DEF;
	if (damage <= 0)
	{
		damage = 1;
	}

	HP -= damage;
	if (HP <= 0)
	{
		isDeath = true;
	}
}

void Player::Defence()
{
	DEF += 1;
}

void Player::UseItem(int Heal)
{
	HP += Heal;
	
	// 최대 체력 
}

void Player::Skill(int damage)
{
	damage = damage - DEF;
	if (damage <= 0)
	{
		damage = 10;
	}

	HP -= damage;
	if (HP <= 0)
	{
		isDeath = true;
	}
}

