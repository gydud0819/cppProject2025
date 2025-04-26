#pragma once
#include "Common.h"


enum ElementType	// 속성
{
	Fire, Water, Dark, Ground, Electro, Natual, Independent
};

enum Rank			// 등급
{
	ANCIENT, LEGENDARY, EPIC, COMMON
};

class Cookie		// 부모 클래스
{
protected:
	int Lv;
	string name;
	ElementType type;
	Rank rank;
public:
	Cookie() {}
	Cookie(int Lv, string name, ElementType type, Rank rank) : Lv(Lv), name(name), type(type), rank(rank) {}
public:
	void ShowCookieInfo();		// 같은 이름을 가진 함수를 찾아 사용해라라는 뜻
	string ReturnElementType();
	string ReturnRank();
	virtual void UseSkill();
};

class Wind_Archer_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Wind_Archer_Cookie() {}
	Wind_Archer_Cookie(int Lv, string name, ElementType type, Rank rank) : Cookie(Lv, name, type, rank) {} // 자식 클래스의 생성자
	
public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();	
	string ReturnRank();
	void UseSkill() override;
};

class GingerBrave :public Cookie		// 자식 클래스, 용감한쿠키
{
public:
	GingerBrave() {}
	GingerBrave(int Lv, string name, ElementType type, Rank rank) : Cookie(Lv, name, type, rank) {}
public:
	void ShowCookieInfo();
	string ReturnElementType();	// 부모 함수를 재정의(덮어쓰기)를 하여 다시 사용한다는 뜻이다.
	string ReturnRank();
	void UseSkill() override;
};

