#pragma once

// 객체지향 프로그래밍 OOP(Object Oriented Programming)
#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 예제1. 좌표를 표현하는 구조체 Pos, 정보 은닉
// 목표. 콘솔 화면 창에 사각형을 그리는 객체 만들기 

// 목표 : 사각형, 점, 콘솔
// 정보 은닉 : 접근 제어 지시자

// struct	: 기본 설계가 public으로 되어있다.
// class	: 기본 설계까 private로 되어있다. 

class Point
{
private:
	int x;
	int y;
public:
	Point() {}

	Point(int x, int y)
		: x(x), y(y)
	{ }
};

// 접근 제어 지시자
// private, public, protected
// 
// private	: 객체 내부에서만 허용되는 접근 방식
// public	: 객체 외부에서도 허용되는 접근 방식
// protected:
// 
// class 키워드 : 기본적으로  private 구현된다.

// 정보 은닉 : 외부에서 사용하지 못하게 막는 것
// 왜 외부에서 사용하면 안되는가?
// 안전하게 구현된 코드에서만 외부로 노출되도록 만든다. 

class cPoint
{
private:
	// class를 사용하고 아무것도 쓰지 않으면 private:가 선언된다. 
	int x;
	int y;
public:
	// 생성자 : 자동으로 만들어주는 기능
	// 직접 생성자를 선언하면 디폴트 생성자가 자동으로 만들어지지 않는다. 

	cPoint() {}	// 얘가 디폴트 생성자 

	cPoint(int outx, int outy)
	{ 
		if (outx < 0 || outy < 0)
		{
			cout << "유효하지 않은 범위가 지정되었습니다." << endl;
			// 예외 처리
			// 코드가 실행되면 코드가 멈추고 다음 내용을 출력한다.
			throw std::invalid_argument("유효하지 않은 범위가 지정되었습니다.");
		}
		x = outx;	// 외부에서 가져온 변수를 넣으라는 것
		y = outy;
	}

	int GetX() const;
	int GetY() const;

	void SetX(int amout);
	void SetY(int amout);
};

class Rectangle
{
private:
	cPoint leftUpPoint;		// x가 작고 y가 크다.
	cPoint rightLowPoint;	// y가 작고 x가 크다.

public:
	Rectangle() {}

	Rectangle(cPoint p1, cPoint p2)		// p1과 p2의 좌표가 le, ri 형식이 아닌 경우에는 문제가 생길 수 있다. 
	{
		if (p1.GetX() < p2.GetX() && p1.GetY() < p2.GetY())
		{
			leftUpPoint = p1;
			rightLowPoint = p2;
		}
		else
		{
			leftUpPoint = p2;
			rightLowPoint = p1;
		}
		// p1 x좌표 p2 x좌표 비교
		// p1 y좌표 p2 y좌표 비교
	}
	Rectangle(int x1, int x2, int y1, int y2)
	{
		cPoint newLeftUp;
		cPoint newRightDown;
		if (x1 < x2)
		{
			newLeftUp.SetX(x1);
			newRightDown.SetX(x2);
		}
		else if (x1 > x2)
		{
			newLeftUp.SetX(x2);
			newRightDown.SetX(x1);
		}
		else
		{
			cout << "x, y의 좌표가 같을 수 없습니다." << endl;
		}
		if (y1 < y2)
		{
			newLeftUp.SetY(y2);
			newRightDown.SetY(y1);
		}
		else if (y1 > y2)
		{
			newLeftUp.SetY(y1);
			newRightDown.SetY(y2);
		}
		else
		{
			cout << "y의 좌표가 같을 수 없습니다." << endl;
		}


		leftUpPoint = newLeftUp;
		rightLowPoint = newRightDown;
	}
		
	void Draw();
};

void example1();
void example2();
void example3();
