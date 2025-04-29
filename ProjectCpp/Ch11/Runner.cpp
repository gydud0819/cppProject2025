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

void Runner::Run()
{
	// maxSpeed를 제어해주는 함수 
	SetMaxSpeed();			// 변경해도 되는 함수 (virtual 사용)
	DrawMoveDistance();		// 변경되면 안되는 함수
	SetShape();				// 변경해도 되는 함수 (virtual 사용)

}

bool Runner::CheckEndLine(int lengh)
{
	if (run >= lengh)
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

void EnemyRunner::EnemySetMaxSpeed()
{

}

void EnemyRunner::EnemySetShape()
{

}
