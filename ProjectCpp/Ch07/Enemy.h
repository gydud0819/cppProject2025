#pragma once
#include "Entity.h"
#include <iostream>
using namespace std;

/*
* A개발자 - B개발자
  Player 기능을 구현했다.
  B개발자님 Player에 있는 전투 데이터를 사용해서 Enemy의 전투 시스템을 만들어주세요

  A개발자님 상속해서 구현해보겠습니다.

  1. 이미 구현되어 있는 코드를 공통된 기능을 추출하는 작업
  2. 상속을 하고 있는 공통 객체. 객체를 만드는 방법 
*/

enum BehaviorPattern
{
	드세다,
	방어한다,
	약하다,
};

class Enemy : public Entity
{
private:						// private를 2가지 이상 선언해도 된다.
	BehaviorPattern currentPattern;
	// ATK, HP, DEF 전투 시스템을 구현한다. 

private:
	void Attacked();
	void Defence();
	void Recovery();
	void BehaviorAI();

public:
	void Action();
};

