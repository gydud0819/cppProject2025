#include "Monster.h"

void Monster::Attack()
{
	CalculateFinalATK();
	cout << "최종 공격력 : " << finalATK << endl;
}

void Monster::CalculateFinalATK()	// 최종공격력
{
	// 레벨 + 기본 공격력
	finalATK = Lv * defalutATK;
}

void Slime::Attack()	// Monster Attack이 없고 새로 정의하겠다.
{
	// 그러나 Monster에서 사용한 로직을 그대로 사용하고 싶을 때
	Monster::Attack();
	cout << "추가기능을 실행합니다 : " << endl;
}

void Orc::Attack()
{
	Monster::Attack();
	cout << "orc의 기능을 실행합니다." << endl;
}
