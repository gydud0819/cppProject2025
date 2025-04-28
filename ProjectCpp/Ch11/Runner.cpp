#include "Runner.h"

void Runner::Run()
{
	// maxSpeed를 제어해주는 함수 
	run += RandomUtil::GetRandomInt(maxSpeed);
	// 
	for (int i = 0; i < run; i++)
	{
		cout << " ";
	}
	cout << nickName << endl;
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

void Player::Run()
{
	Runner::Run();
	cout << nickName << endl;
}
