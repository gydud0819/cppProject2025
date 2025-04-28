#include "Base.h"

void Base::Do()
{
	cout << "base do" << endl;
}

void Derived::Do()
{
	Base::Do();
	cout << "Derived do" << endl;
}

//Derived::~Derived()
//{
//	Base::Do();
//	//cout << "Derived 클래스가 소멸되었습니다." << endl;
//}
