#include "Enemy.h"

void Enemy::Attacked()
{
	cout << "공격 받음" << endl;
	HP -= 10;
}

void Enemy::Defence()
{
	cout << "방어함" << endl;
	DEF += 5;
}

void Enemy::Recovery()
{
	cout << "회복함" << endl;
	HP += 10;
}

void Enemy::BehaviorAI()
{
	if (HP > 5)
	{
		currentPattern = 드세다;
	}
	else if (HP % 2 == 0)
	{
		currentPattern = 방어한다;
	}
	else if (HP <= 5)
	{
		currentPattern = 약하다;
	}
}

void Enemy::Action()
{
	// 몬스터 차례가 되면 행동을 선택한다. 
	BehaviorAI();
	// 그 행동에 따라서 기능을 실행한다. 

	switch (currentPattern)
	{
	case 드세다:
		Attacked();
		break;
	case 방어한다:
		Defence();
		break;
	case 약하다:
		Recovery();
		break;
	default:
		break;
	}

}
