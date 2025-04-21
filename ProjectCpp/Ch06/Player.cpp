#include "Player.h"

void Player::AttackedBy(int damage)
{
	if (damage < 0)
	{
		cout << "피해량이 음수가 될 수 없습니다." << endl;
	}

	HP -= damage;
	if (HP <= 0)
	{
		isDeath = true;
	}
}

void Player::Recovery(int heal)
{
	if (HP > MaxHP)
	{
		return;
		HP = MaxHP;
	}

	HP += heal;
}
