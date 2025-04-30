#include "Runner.h"

void Runner::SetMaxSpeed()
{
	run += RandomUtil::GetRandomInt(maxSpeed);		// 1. 캐릭터의 최대 속도를 설정한다. 
}

void Runner::DrawMoveDistance()
{
	for (int i = 0; i < run; i++)					// 2. 이동한다. 
	{
		cout << " ";
	}
}

void Runner::SetShape()
{
	cout << nickName << endl;						// 3. 형태를 그려준다. 
}

void Runner::ShowPlayerGameInfo()
{

}

void Runner::Initialize()
{
	int run = 0;
	isEnd = false;

}

void Runner::Run()
{
	// maxSpeed를 제어해주는 함수 
	SetMaxSpeed();			// 변경해도 되는 함수 (virtual 사용)
	DrawMoveDistance();		// 변경되면 안되는 함수
	SetShape();				// 변경해도 되는 함수 (virtual 사용)

}

bool Runner::CheckEndLine(int length)
{
	if (run >= length)
	{
		isEnd = true;
	}
	else
	{
		isEnd = false;
	}
	return isEnd;
}

void Player::SetMaxSpeed()
{
	int ApplyMaxSpeed = maxSpeed + 1;		// 아이콘, 스킬 이름, 스킬 효과: 플레이어의 최대 속도를 1증가 시켜주는 스킬
	run += RandomUtil::GetRandomInt(maxSpeed);

	//run += OwnSkillA();
}

void Player::SetShape()
{
	int percent = RandomUtil::GetRandomInt(100);
	if (percent >= 50)
	{
		cout << "~" << nickName << endl;

	}
	else
	{
		cout << nickName << endl;
	}
}

void Player::ShowPlayerGameInfo()
{
	ConsoleUtil::GotoXY(0, 20);
	cout << "유저 정보" << endl;
	cout << "최소 속도 : " << minSpeed << endl;
	cout << "최고 속도 : " << maxSpeed << endl;
	cout << "보유 금액 : " << money << endl;
}

void Player::UpGrade(PlayerStat selectedStat)
{
	if (selectedStat == PlayerStat::MINSPEED)
	{
		SetMin(1);
		cout << "최소 속도가 1 증가 했습니다." << endl;
	}
	else if (selectedStat == PlayerStat::MAXSPEED)
	{
		SetMin(1);
		cout << "최고 속도가 5 증가 했습니다." << endl;
	}
	else if (selectedStat == PlayerStat::NONE)
	{
		cout << "적용된 스텟이 없습니다." << endl;
	}

	/*switch (selectedStat)
	{
	case MINSPEED:
		SetMin(1);
		cout << "최소 속도가 1 증가 했습니다." << endl;
		break;
	case MAXSPEED:
		SetMin(1);
		cout<<"최고 속도가 5 증가 했습니다." << endl;
		break;
	case NONE:
		break;
	default:
		break;
	}*/
}

void Player::UpGrade(PlayerStat selectedStat, int amount)
{
	if (selectedStat == PlayerStat::MINSPEED)
	{
		SetMin(amount);
		cout << "최소 속도가" << amount << "증가 했습니다." << endl;
	}
	else if (selectedStat == PlayerStat::MAXSPEED)
	{
		SetMax(amount);
		cout << "최고 속도가 5 증가 했습니다." << endl;
	}
	else if (selectedStat == PlayerStat::NONE)
	{
		cout << "적용된 스텟이 없습니다." << endl;
	}
}

void Player::SetMin(int value)
{
	if (maxSpeed < value)
	{
		value = minSpeed;

	}
	minSpeed = value;
}

void Player::SetMax(int value)
{
	if (10 <= value)
	{
		value = 10;
	}
	maxSpeed = value;
}

void EnemyRunner::EnemyRun()
{
	DrawMoveDistance();
	EnemySetMaxSpeed();
	EnemySetShape();
}

bool EnemyRunner::CheckEndLine(int length)
{
	if (run >= length)
	{
		isEnemyEnd = true;
	}
	else
	{
		isEnemyEnd = false;
	}
	return isEnemyEnd;
}

void EnemyRunner::DrawMoveDistance()
{
	for (int i = 0; i < run; i++)					// 2. 이동한다. 
	{
		cout << " ";
	}
}

void EnemyRunner::EnemySetMaxSpeed()
{
	run += RandomUtil::GetRandomInt(MaxSpeed);
}

void EnemyRunner::EnemySetShape()
{
	int percent = RandomUtil::GetRandomInt(100);
	if (percent >= 50)
	{
		cout << "@" << EnemyShape << endl;

	}
	else
	{
		cout << EnemyShape << endl;
	}
}

void Enemy::EnemySetMaxSpeed()
{
	int ApplyMaxSpeed = MaxSpeed + 5;		// 몬스터 대신 핵 유저 사용으로 적용
	run += RandomUtil::GetRandomInt(ApplyMaxSpeed);
}

void Enemy::EnemySetShape()
{
	cout << EnemyShape << endl;
}
