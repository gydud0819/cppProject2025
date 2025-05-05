#pragma once
#include "Common.h"
const int MAX_COOKIES = 100;


namespace ELEMENTTYPE
{
	enum ElementType	// 속성
	{
		Fire, Water, Dark, Ground, Electro, Wind, Ice, Light, Independent
	};

}

//enum ElementType	// 속성
//{
//	Fire, Water, Dark, Ground, Electro, Wind, Ice, Light, Independent
//};


namespace RANK 
{
	enum Rank			// 등급
	{
		ANCIENT, LEGENDARY, SUPER_EPIC, EPIC, RARE, COMMON
	};


}

//enum Rank			// 등급
//{
//	ANCIENT, LEGENDARY, SUPER_EPIC, EPIC, RARE, COMMON
//};

struct CookieType
{
	ELEMENTTYPE::ElementType type;
	RANK::Rank rank;

};

class Cookie
{
protected:
	int index;
	string name, name2, name3, name4;
	ELEMENTTYPE::ElementType type;
	RANK::Rank rank;
public:
	Cookie() {}
	/*Cookie(int index, string name, string name2, string name3, string name4, ELEMENTTYPE::ElementType type, RANK::Rank rank) 
		: index(index), name(name), name2(name2), name3(name3), name4(name4), type(type), rank(rank) {}*/

	Cookie(int index, string fullName, ELEMENTTYPE::ElementType type, RANK::Rank rank)
		: index(index), name(fullName), type(type), rank(rank) {}
	
public:
			// 같은 이름을 가진 함수를 찾아 사용해라라는 뜻
	static ELEMENTTYPE::ElementType StringToElementType(const string& str);
	static RANK::Rank StringToRank(const string& str);

	virtual ~Cookie() = default;
public:
	string GetName() const 
	{
		return name; 
	}
	ELEMENTTYPE::ElementType GetElementType() const { return type; }
	RANK::Rank GetRank() const { return rank; }

	string ReturnElementType() const;
	string ReturnRank() const;
};

class CookieHandler
{
public:
	// filename으로부터 메모장을 열어서 가져온다, Items(메모장의 정보를 저장할 매개체)
	int LoadCookies(const string& filename, Cookie cookies[]);	// 파일로부터 아이템을 가져오겠다라는 의미의 함수, Item을 배열로 가져온다. 
};

