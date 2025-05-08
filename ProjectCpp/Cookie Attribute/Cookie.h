#pragma once
#include "Common.h"

const int MAX_COOKIE = 100;

enum ElementType	// 속성
{
	Fire, Water, Dark, Ground, Electro, Wind, Ice, Light, Poison, Steel, Independent
};

enum Rank			// 등급
{
	ANCIENT, BEAST, LEGENDARY, DRAGON, SUPER_EPIC, EPIC, RARE, COMMON
};

class Cookie		// 부모 클래스
{
protected:
	string name;
	ElementType type;
	Rank rank;
public:
	Cookie() {}
	Cookie(string name, ElementType type, Rank rank) : name(name), type(type), rank(rank) {}
	ElementType GetElementType() const;
	Rank GetRank() const;
public:
	virtual void ShowCookieInfo();		// 같은 이름을 가진 함수를 찾아 사용해라라는 뜻
	virtual string ReturnElementType();
	virtual string ReturnRank();
	//virtual void UseSkill();

	virtual ~Cookie() = default;
};

class Wind_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Wind_Cookie() {}
	Wind_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자
	
public:
	void ShowCookieInfo() override;		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType() override;	
	string ReturnRank() override;
	//void UseSkill() override;
};

class Fire_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Fire_Cookie() {}
	Fire_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType() override;
	string ReturnRank() override;
	//void UseSkill() override;
};

class Water_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Water_Cookie() {}
	Water_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType() override;
	string ReturnRank() override;
	//void UseSkill() override;
};

class Dark_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Dark_Cookie() {}
	Dark_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class Ground_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Ground_Cookie() {}
	Ground_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	// UseSkill() override;
};

class Electro_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Electro_Cookie() {}
	Electro_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class Ice_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Ice_Cookie() {}
	Ice_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class Light_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Light_Cookie() {}
	Light_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class Poison_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Poison_Cookie() {}
	Poison_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class Steel_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Steel_Cookie() {}
	Steel_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class Independent_Cookie : public Cookie	// 자식 클래스, 바람궁수
{
public:
	Independent_Cookie() {}
	Independent_Cookie(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {} // 자식 클래스의 생성자

public:
	void ShowCookieInfo();		// virtual 키워드를 사용한 함수를 찾아 부모 함수로 그대로 덮어쓰라는(재정의) 의미이다.
	string ReturnElementType();
	string ReturnRank();
	//void UseSkill() override;
};

class GingerBrave :public Cookie		// 자식 클래스, 용감한쿠키
{
public:
	GingerBrave() {}
	GingerBrave(string name, ElementType type, Rank rank) : Cookie(name, type, rank) {}
public:
	void ShowCookieInfo();
	string ReturnElementType();	// 부모 함수를 재정의(덮어쓰기)를 하여 다시 사용한다는 뜻이다.
	string ReturnRank();
	//void UseSkill() override;
};

