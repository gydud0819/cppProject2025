/*
* 주제	: virtual, override
*/
#pragma once
#include "Common.h"

// 몬스터, 몬스터 관리 

// 몬스터는 공격을 한다. 

/*
* 몬스터의 공격 규칙
  최종 공격력
*/

/*
* 오버라이드 (override) = 부모 클래스의 함수를 재정의해서 사용하겠다
  Monster::Attack();
  Slime::Attack();
  Slime 입장에서는 Monster Attack과 Slime Attack 둘다 가지고 있다. 어떤 Attack을 사용해야 할까?
  부모의 함수를 대체한다.

  자식 클래스에서 오버라이딩하지 않으면 부모 클래스의 가상 함수가 자동으로 호출된다.

  특별한 동작이 필요할 때만 오버라이딩하고 그렇지 않으면 부모 함수 그대로 사용한다.

 */

/*
* virtual, override
  
  virtual : 코드가 실제(존재)하지 않는다. 즉, 다른 곳에서 이 함수를 찾아 사용하라는 의미이다. 자식 클래스에서 재정의(오버라이딩)할 때 쓰는 키워드
  override : 같은 이름의 함수를 자식에서 선언하면 부모의 코드가 숨겨진다. 

  슬라임, 오크, 고블린

  Monster::Attack();
  Slime::Attack();
  Orc::Attack();
  Goblin::Attack();

  확장성 문제 : 슬라임, 오크, 고블린 등 새로 추가할 몬스터의 개성을 추가할 수 없다. (모두 공통된 코드만 출력된다.)

  override : 사람이 하는 실수를 보완해주는 키워드
  함수의 이름이 무조건 같아야 한다. 

*/


class ElementType
{
	
};

class Monster // 몬스터가 is 속성? x 몬스터가 has 속성? -> 몬스터가 속성을 가지고 있는가?
{
protected:
	int Lv;
	int defalutATK;
	int finalATK;
	ElementType elementType;	// 
public:
	Monster() {}
	Monster(int Lv, int defalutATK) : Lv(Lv), defalutATK(defalutATK) {}		// Monster 생성자

public:
	virtual void Attack();	

	void CalculateFinalATK();	// 최종공격력
};

class Slime : public Monster
{
public:
	Slime() {}
	Slime(int Lv, int defalutATK) : Monster(Lv, defalutATK) {}
public:
	void Attack() override;		// override뒤에 붙어야한다? 
};

class Orc : public Monster
{
public:
	Orc() {}
	Orc(int Lv, int defalutATK) : Monster(Lv, defalutATK) {}
public:
	void Attack() override;	
};

