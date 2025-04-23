#include "Monster.h"

void Attacker::Attack()
{
	cout << "공격한다." << endl;
}

Attacker* Unit::ReturnAttacker()
{

	return attacker;
}

void Unit::Attack()
{
	cout << "유닛이 공격한다." << endl;
}

void Unit::UseSkill()
{
	cout << "스킬을 사용한다.\n" << endl;
}

void Probe::Attack()
{
	cout << "소형 타입의 공격을 공격한다." << endl;
}

void Probe::UseSkill()
{
	cout << "자원 수집을 한다.\n" << endl;
}

void Zealot::Attack()
{
	cout << "소형 타입의 공격을 공격한다." << endl;
	cout << "연속해서 두번 공격한다.\n" << endl;
}

void Zealot::UseSkill()
{
	cout << "근접 공격을 한다." << endl;
}

void Dragoon::Attack()
{
	cout << "중형 타입의 공격을 한다." << endl;
	cout << "일정 확률로 공격이 빗나간다.\n" << endl;
}

void Dragoon::UseSkill()
{
	cout << "광전사 군단에게 화포 지원을 한다." << endl;
}
