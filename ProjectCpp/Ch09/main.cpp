/*
* 클래스
* 캡슐화
* 상속	: 공통된 코드를 하나로 묶는 것
* 상속을 언제 해야하는가? Is - A, Has - A (Is-A일때 묶어준다, Has-A를생각하면서 하면 상속을 이해하기 쉽다.)
* 
* 상속 사용시 장점
* 
*/
#include "Common.h"
#include "Monster.h"
#include "MonsterHandler.h"

/*
* std::cout << "땅 속성 타입의 쿠키가 2명이상 이면 땅 속성의 시너지가 활성화됩니다."
* 게임 시너지
* 시너지(공통)
*/

int main()
{
	MonsterHandler monsterHandler;
	Monster slime2(1, 5);
	Slime slime(1, 2);
	Orc orc(1, 9);

	monsterHandler.BattleWithPlayer(slime);
	monsterHandler.BattleWithPlayer(slime2);
	monsterHandler.BattleWithPlayer(orc);
	
	//slime2.Attack();

	//slime.Attack();
}