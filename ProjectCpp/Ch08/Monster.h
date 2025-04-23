#pragma once
#include "Common.h"

class Monster
{

};

// 프로젝트를 간단하게 시작하는 방법
// 1. 익숙하거나 알고 있는 게임을 가져온다. 
// 2. 하나의 데이터를 선택해서 객체로 표현한다. 

// Has - A

/*
* virtual 키워드를 언제 추가하고, 언제 사용을 안하는가?
  코드를 상속하는 객체의 기능이 추가적인 특징을 갖는다. virtual, 함수 오버라이딩
  모든 유닛은 멈춘다라는 기능이 동일하다. -> virtual를 사용하지 않아도 된다. 
*/
class Attacker
{
public:
	void Attack();
};

class Flyer
{

};

class Unit // 유닛은 공격가능 한가?, 공격을 못할 수도 있다.
{
	Attacker* attacker;
	Flyer* flyer;

	bool isAttackable;	// 공격이 가능한지 

public:
	Unit()
	{

	}
	Unit(bool Attackable)
	{
		isAttackable = Attackable;
		if (isAttackable)
		{
			attacker = new Attacker();

		}
	}
public:
	Attacker* ReturnAttacker();

	virtual void Attack(); // virtual에 대해선 내일 할 예정
	void Stop();
	void Move();
	void Patrol();
	void Hold();
	virtual void UseSkill();
};

class Factory
{

};

class Nexus : public Factory
{

};

class GateWay
{

};

class Probe : public Unit // 프로브는 유닛인가? 
{
public:
	Probe(bool attackable) : Unit(attackable) {}

	void Attack();
	void UseSkill();
};

class Zealot : public Unit
{
public:
	void Attack();
	void UseSkill();
};

class Dragoon : public Unit
{
public:
	void Attack();
	void UseSkill();
};