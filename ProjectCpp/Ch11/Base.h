#pragma once
#include "Common.h"

/*
* 클래스 정리

  1. 접근 지정자 레이블 선언
* private: 자신 클래스(부모 클래스) 본인만 사용가능
  public: 자식 클래스에서도 사용 가능
* protected: 모든 범위에서 사용 가능
* 
  2. 생성자 소멸자
  생성자 : 멤버 변수를 클래스 생성과 동시에 초기화 하는 방법만 사용가능
  소멸자 : 클래스가 소멸될 때 자동으로 호출되는 함수
  
  3. 메모리 누수, 동적할당 무엇이 문제가 될까?
* 프로그램, 앱 오랜 기간 접속, 플레이 중에 문제가 종종 발생한다. (화면이 버벅거리거나 강제 종료 등) == 메모리 누수
* 동적할당 주소, 사용하지 않을 때 메모리 해제
  소멸자, 스마트 포인터
*/

class Base
{
private:
	int count;

public:		 
	Base() : count(0) {}
	Base(int count) : count(count)
	{
		cout << "생성자 호출" << endl;
	}
	virtual ~Base()		// 가상 소멸자 
	{
		cout << "Base의 클래스가 소멸되었습니다." << endl;
	}
	virtual void Do();
protected:
	
};

class Derived : public Base
{
public:
	void Do() override;

	~Derived() override
	{
		cout << "Derived 클래스가 소멸되었습니다." << endl;
	}
};
