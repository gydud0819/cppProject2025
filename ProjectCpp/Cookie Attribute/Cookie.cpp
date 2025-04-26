#include "Cookie.h"

void Cookie::ShowCookieInfo()
{
	cout << "쿠키의 레벨: " << Lv << endl;
	cout << "쿠키의 이름: " << name << endl;
	cout << "쿠키의 속성: " << ReturnElementType() << endl;
	cout << "쿠키의 등급: " << ReturnRank() << endl;
}

string Cookie::ReturnElementType()
{
	switch (type)
	{
	case Fire:

		return "Fire";
	case Water:
		return "Water";
	case Dark:
		return "Dark";
	case Ground:
		return "Ground";
	case Electro:
		return "Electro";
	case Natual:
		return "Natual";
	case Independent:
		return "Independent";
	default:
		break;
	}
}

string Cookie::ReturnRank()
{
	switch (rank)
	{
	case ANCIENT:
		return "ANCIENT";
	case LEGENDARY:
		return "LEGENDARY";
	case EPIC:
		return "EPIC";
	case COMMON:
		return "COMMON";
	default:
		break;
	}
}

void Cookie::UseSkill()
{
	cout << "기본 스킬 발동!" << endl;
}

// 밑에 주석처리한 내용은 부모클래스의 함수와 똑같은 내용이기에 오버라이딩이 필요없다 판단하여 전부 주석처리를 했다.

//void Wind_Archer_Cookie::ShowCookieInfo()
//{
//	Cookie::ShowCookieInfo();			// 부모 클래스에서 파생한 것이기 때문에 부모 클래스에서 선언한 함수를 호출해야한다. (중요) 
// //즉, 동일한 동작을 반복 하지 않게 하기위해 부모 클래스의 함수를 호출한다.
//}
//
//string Wind_Archer_Cookie::ReturnElementType()
//{
//	return Cookie::ReturnElementType();		// 부모 함수를 오버라이드하기 때문에 반드시 리턴을 해줘야한다.
//}
//
//string Wind_Archer_Cookie::ReturnRank()
//{
//	return Cookie::ReturnRank();			// 부모 함수를 오버라이드하기 때문에 반드시 리턴을 해줘야한다.
//}
//
//void GingerBrave::ShowCookieInfo()
//{
//	Cookie::ShowCookieInfo();
//}
//
//string GingerBrave::ReturnElementType()
//{
//	return Cookie::ReturnElementType();
//}
//
//string GingerBrave::ReturnRank()
//{
//	return Cookie::ReturnRank();
//}

// 오버라이딩을 사용하는 것은 특별한 무언가를 출력하거나 선언하고 싶을때 사용하면 좋기에 스킬을 출력하기 위해 밑의 코드에서 오버라이드를 선언했다. 
void Wind_Archer_Cookie::UseSkill()
{
	//Cookie::ShowCookieInfo();
	cout << "스킬 : 최후의 바람" << endl;
}

void GingerBrave::UseSkill()
{
	//Cookie::ShowCookieInfo();
	cout << "스킬 : 용감한 돌격" << endl;
}
