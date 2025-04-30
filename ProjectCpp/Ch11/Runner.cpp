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

void Runner::UpGrade(PlayerStat selectedStat)
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

// 오버로딩한 스텟 업그레이드 함수 
void Runner::UpGrade(PlayerStat selectedStat, int amount)
{
	if (selectedStat == PlayerStat::MINSPEED)
	{
		SetMin(amount);
		cout << "최소 속도가" << amount << "증가 했습니다." << endl;
	}
	else if (selectedStat == PlayerStat::MAXSPEED)
	{
		SetMax(amount);
		cout << "최고 속도가" << "5 증가 했습니다." << endl;
	}
	else if (selectedStat == PlayerStat::NONE)
	{
		cout << "적용된 스텟이 없습니다." << endl;
	}
}

void Runner::SetMin(int value)
{
	if (maxSpeed < value)
	{
		value = maxSpeed;	// 최고속도 10을 넘지 않게 max를 10으로 설정

	}
	minSpeed += value;	// 누적해서 증가하게 했다.
}

void Runner::SetMax(int value)
{
	if (10 < value)
	{
		value = 10;		// 최대 속도 10 제한
	}
	maxSpeed += value;	// 누적해서 증가하게 했다.
}

void Runner::Initialize()
{
	run = 0;	// 모든 주자가 0에서 시작한다. (이동거리 초기화)
	isEnd = false;	// 우승한게 아니다. (도착 상태 초기화)

}

void Runner::Run()
{
	// maxSpeed를 제어해주는 함수 
	SetMaxSpeed();			// 변경해도 되는 함수 (virtual 사용)
	DrawMoveDistance();		// 변경되면 안되는 함수
	SetShape();				// 변경해도 되는 함수 (virtual 사용)

}

// 맵 길이 끝에 도달했는지 확인하는 함수
bool Runner::CheckEndLine(int length)
{
	if (run >= length)
	{
		isEnd = true;	// 도달했다면 승리
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
	run += RandomUtil::GetRandomInt(ApplyMaxSpeed);

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

//  유저 정보를 보여주는 함수
void Player::ShowPlayerGameInfo()
{
	//ConsoleUtil::GotoXY(80, 5);
	cout << "유저 정보" << endl;
	//ConsoleUtil::GotoXY(80, 6);
	cout << "최소 속도 : " << minSpeed << endl;
	cout << "최고 속도 : " << maxSpeed << endl;
	//ConsoleUtil::GotoXY(80, 8);
	cout << "보유 금액 : " << money << endl;
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
