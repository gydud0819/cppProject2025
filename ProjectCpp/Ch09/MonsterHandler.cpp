#include "MonsterHandler.h"

void MonsterHandler::BattleWithPlayer(Monster& monster)	// 공통으로 받아온다.
{
	// 몬스터들은 슬라임인지, 오크인지 모를 때
	if (dynamic_cast<Slime*>(&monster))		// 몬스터를 슬라임으로? 슬라임을 몬스터로? 
	{
		cout << "슬라임의 전투가 실행됩니다." << endl;
	}

	if (dynamic_cast<Orc*>(&monster))
	{
		cout << "오크의 전투가 실행됩니다." << endl;
	}

	// 플레이어의 값을 설정한다.
	// 플레이어에게 공격을 한다. 
	monster.Attack();
}
