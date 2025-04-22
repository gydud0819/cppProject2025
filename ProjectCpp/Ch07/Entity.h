#pragma once
/*
* Player 기능 구현
  Enemy 기능 구현 
  2가지 객체에서 공통으로 지니는 데이터가 존재한다. 
  상속.
  모든 것을 상속해줘야 할까?
  부모 - 자식 

  Character 클래스가 Entity 클래스를 사용하고 있다.
  Character 클래스가 Entity의 자식 클래스이다.
  Parent	-		Child
  base		-		Derived
*/

/*
* 접근 제어 지시자
  protected : 자식에게는 열려있고 그 이외에는 접근을 못하게 막는 것
  부모가 자식에게 모든 것을 넘겨주고 싶지 않을 수 있다.
  부모가 자기 자신에게만 사용하고 싶은 것은 private으로 선언하고
  자식에서도 변경하고 싶은 것은 protected로 선언한다. 
*/

/*
* Enemy, Player 둘다 체력, 공격력, 방어력을 가지도록 구성해라
  1. 체력을 사용하는 시스템을 Entity 공통으로 구현가능하다면 private로 설계한다. 
*/

class Entity
{
protected:
	int HP;
	int ATK;
	int DEF;


public:

	int GetHP();
	int GetATK();
	int GetDEF();
	void SetHP(int value);
	void SetATK(int value);
	void SetDEF(int value);
	

};

