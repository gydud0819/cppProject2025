#include "Enemy.h"

void Enemy::ChangeImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1])
{
	for (int y = 0; y < IMAGEHEIGHT; y++)
	{
		for (int x = 0; x < IMAGEWIDTH + 1; x++)
		{
			this->Image[y][x] = Image[y][x];
		}
	}
}

void Enemy::ShowImage()
{
	for (int y = 0; y < IMAGEHEIGHT; y++)
	{
		for (int x = 0; x < IMAGEWIDTH + 1; x++)
		{
			// 특정 좌표로 이동하라는 코드도 필요하다. 
			GoToXY(posX + x, posY + y);		// 이미지도 같은 위치에 나오기 때문에 위치에다 x와 y를 더해준다.
			cout << Image[y][x];
		}
		cout << endl;
	}
}

bool Enemy::IsBattle()
{
	if (posX <= 40)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Enemy::IsWalk()
{
	if (posX <= 39)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::SetBattleImage(char Image[IMAGEHEIGHT][IMAGEWIDTH + 1])
{

	ChangeImage(Image);

	// 이동 로직
	if (posX <= 40)
		posX = 40;
	else
		posX--;

	ShowImage();
}

void Enemy::Attacked(int damage)
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
	// HP가 0보다 작거나 같으면 몬스터가 죽었다는 사실을 외부에 알려야한다.  - Bool isdeath;
}

void Enemy::MSkill()
{

}
