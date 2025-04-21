#include "OOP.h"

void example1()
{
	Point p1 = { 2,8 };
	Point p2 = { -7,19 };

	Point point(4, 6);
	cPoint cp1(-3, 5);	

	Rectangle rect = { p1, p2 };
	//cp1.SetX(-9);
}

void example2()
{

}

void example3()
{

}

int cPoint::GetX() const
{
	return x;
}

int cPoint::GetY() const
{
	return y;
}

void cPoint::SetX(int amout)
{
	if (amout < 0)
	{
		cout << "잘못된 값으로 x을 변경했습니다." << endl;
		return;
	}
	x = amout;
}

void cPoint::SetY(int amout)
{
	if (amout < 0)
	{
		cout << "잘못된 값으로 x을 변경했습니다." << endl;
		return;
	}
	y = amout;
}



