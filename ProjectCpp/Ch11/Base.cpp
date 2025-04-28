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
