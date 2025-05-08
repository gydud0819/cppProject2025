#include "Cookie.h"

ElementType Cookie::GetElementType() const
{
	return type;
}

Rank Cookie::GetRank() const
{
	return rank;
}

void Cookie::ShowCookieInfo()
{
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
	case Wind:
		return "Wind";
	case Ice:
		return "Ice";
	case Light:
		return "Light";
	case Poison:
		return "Poison";
	case Steel:
		return "Steel";
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
	case BEAST:
		return "BEAST";
	case LEGENDARY:
		return "LEGENDARY";
	case DRAGON:
		return "DRAGON";
	case SUPER_EPIC:
		return"SUPER_EPIC";
	case EPIC:
		return "EPIC";
	case RARE:
		return"RARE";
	case COMMON:
		return "COMMON";
	default:
		break;
	}
}

// 밑에 주석처리한 내용은 부모클래스의 함수와 똑같은 내용이기에 오버라이딩이 필요없다 판단하여 전부 주석처리를 했다.

void Wind_Cookie::ShowCookieInfo()
{
	cout << "바람 속성 쿠키" << endl;
	Cookie::ShowCookieInfo();			// 부모 클래스에서 파생한 것이기 때문에 부모 클래스에서 선언한 함수를 호출해야한다. (중요) 
 //즉, 동일한 동작을 반복 하지 않게 하기위해 부모 클래스의 함수를 호출한다.
}

string Wind_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();		// 부모 함수를 오버라이드하기 때문에 반드시 리턴을 해줘야한다.
}

string Wind_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();			// 부모 함수를 오버라이드하기 때문에 반드시 리턴을 해줘야한다.
}

//void GingerBrave::ShowCookieInfo()
//{
//	Cookie::ShowCookieInfo();
//}

string GingerBrave::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string GingerBrave::ReturnRank()
{
	return Cookie::ReturnRank();
}


void Fire_Cookie::ShowCookieInfo()
{
	Cookie::ShowCookieInfo();
}

string Fire_Cookie::ReturnElementType()
{
	return Cookie::ReturnElementType();
}

string Fire_Cookie::ReturnRank()
{
	return Cookie::ReturnRank();
}
