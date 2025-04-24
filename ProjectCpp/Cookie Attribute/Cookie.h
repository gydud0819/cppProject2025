#pragma once
#include "Common.h"


enum ElementType
{
	Fire, Water, Dark, Ground, Electro, Natual
};

enum 등급
{
	Legendary,
};

class Cookie
{
protected:
	int Lv;
	string name;
	// 등급 추가하기
	ElementType type;
public:
	Cookie() {}
	Cookie(int Lv, string name, ElementType type) : Lv(Lv), name(name), type(type) {}
public:
	virtual void ShowCookieInfo();
};

class Legendary_Cookie : public Cookie
{
public:
	Legendary_Cookie() {}
	Legendary_Cookie(int Lv, string name, ElementType type) : Cookie(Lv, name, type) {}
	
public:
	void ShowCookieInfo() override;
};




