#include "Item.h"
//#include "GameUtil.h"

/*
 반환형 객체 이름 : 함수이름()		// 객체에 들어있는 함수를 정의하는 방법
*/

void Item::ShowItemInfo()			// 반환타입이 먼저 나오고 함수 이름이 나와야한다. 
{
	{
		cout << "아이템 이름: " << name << ", 가격: " << price << ", 아이템 소지 개수: " << itemCount << ", 아이템 타입: " << ReturnByTypeName() << endl;
	}
}

string Item::ReturnByTypeName()
{
	switch (type)
	{
	case ARMOR:
		return "ARMOR";

	case WEAPON:
		return "WEAPON";

	case SHOTGUN:
		return "SHOTGUN";

	default:
		break;
	}
	
}

void nameSpaceExample()
{
	cout << "hi" << endl;

	int number = 0;
	cin >> number;
	cout << "number의 값: " << number << endl;
}
