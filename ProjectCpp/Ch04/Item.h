#pragma once
#include "GameUtil.h"

// std::cout, std::cin, std::endl;
// standard : 표준 라이브러리 std

//using namespace std;	// 해당 소스파일 내부의 모든 코드를 namespace std안에 있는 것으로 판단하라는 뜻이다. 

/*
* 주의해야할 사항
* 1. std안에 있던 이름과 같은 타입의 데이터를 만들면 모호하다는 에러가 발생한다.
*/

void nameSpaceExample();

enum ItemType
{
	ARMOR,
	WEAPON,
	SHOTGUN,
};

// 데이터를 선언한다.
// 함수를 선언한다. 

// 구조체 안에 함수를 넣어 실행하게끔 한다. 

struct Item		// 구조체 안에 함수 선언이 가능하다.
{
	std::string name;
	int price;
	int itemCount;
	ItemType type;

	// 생성자 - 구조체의 이름과 동일해야 한다. + ()                    무조건 같아야만 쓸 수 있나?
	// 멤버 이니셜라이즈(member initialize)
	Item(string name, int price, int itemCount, ItemType type)
		: name(name), price(price), itemCount(itemCount), type(type)
	{ }

	void ShowItemInfo();
	
	string ReturnByTypeName();
	
};


