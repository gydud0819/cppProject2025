#pragma once
#include "Common.h"

class Weapon
{
private:		// 멤버 변수
	string name;
	int Lv;
	int baseATK;
	int Weight;
protected:
	int DoUpgrade();	// 
	int FinalATK;
public:			// 생성자를 구현한 퍼블릭
	Weapon(string name, int baseATK, int Weight)
		: name(name), Lv(1), baseATK(baseATK), Weight(Weight)	//  Lv(1)에 숫자를 넣어주면 중괄호안에 굳이 안써도됨
	{ }
	Weapon(string name, int Lv, int baseATK, int Weight) 
		: name(name), Lv(Lv), baseATK(baseATK), Weight(Weight) {}
public:			// 멤버 함수를 구현한 퍼블릭
	void ShowInfo();
	virtual void Attack();
	virtual void Upgrade();
};

class Spear : public Weapon
{
private:
	int specialATK;
public:
	Spear(string name, int Lv, int baseATK, int Weight, int specialATK) 
		: Weapon (name, Lv, baseATK, Weight), specialATK(specialATK) {}
public:
	void Attack();
	void Upgrade() override;
};

class Sword : public Weapon
{
private:
	int specialATK;
public:
	Sword(string name, int Lv, int baseATK, int Weight, int specialATK)
		: Weapon(name, Lv, baseATK, Weight), specialATK(specialATK) 
	{
	}
public:
	void Attack();
	void Upgrade() override;

};

class Arrow: public Weapon
{
private:
	int specialATK;
public:
	Arrow(string name, int Lv, int baseATK, int Weight, int specialATK)
		: Weapon(name, Lv, baseATK, Weight), specialATK(specialATK) 
	{
	}
public:
	void Attack();
	void Upgrade() override;
};