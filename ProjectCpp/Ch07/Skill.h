#pragma once

/*
* 작성일	: 2025-04-22
  작성자	: 박효영 
  주제	: 클래스 (캡슐화, 상속)
*/

/*
* A, B 개발자
  A(상급자) - B(신입)
  A. 캐릭터 B. 스킬
*/

/*
* 스킬을 만들어야 한다.
  객체 : 마나, 스탯, 이펙트
  스킬.Use함수, Skill.Use();

  A개발자 - 
*/

/*
* 정보 은닉 - 외부에서 모르는 정보는 숨겨라
캡슐화 : 기능을 구현할 때 세부 내용을 공개할 필요 없이 사용할 함수만 공개하는 것

*/

#include <iostream>
using namespace std;

class Mana
{
public:
	void Use();
};


class Stat
{
public:
	void Use();
};

class Effect
{
public:
	void Use();
};

class Skill
{
private:		// private에 선언한 타입들은 외부에서 사용할 때 직접 사용하지 말라는 의미이다. 
	Mana mana;
	Stat stat;
	Effect effect;
public:
	/// <summary> 주석인 ///를 3번 입력하면 자동으로 나온다.
	/// 마나를 사용하고 스탯사용 후 이펙트가 출력된다. 
	/// </summary>
	void Use();
};
