#pragma once
#include "CUtil.h"

/*
* C와 C++의 차이점
* 
* C
* 메모리 동적 할당 malloc(memory allocate) : malloc(크기 sizeof(char)* 10)
* free(변수 이름);
* 
* C++
* new		: cpp에서 동적할당하는 키워드 
* delete	: 메모리를 해제하는 키워드
* 
*/

/*
* 생성자	: 객체가 데이터를 생성할 때 초기화를 해주는 방법 
* 소멸자	: 객체가 소멸할 때 자동으로 호출되는 기능 
*/

/*
* 이니셜라이즈
* age, name : age = 20; name = "모험가"
* age = 외부에서 가져온 숫자를 넣으라는 의미 age(age)
* 주소 = 주소; <=를 사용할 때 발생하는 문제점 
*/

enum GENDER
{
	Male,
	FeMale,
};

struct Person
{
	int age;
	char* name;			// 길이가 얼마인지 모른다. 메모리가 배정되어 있지 않다. 
	string sName;
	GENDER gender;

	// 디폴트 생성자
	Person() {}		

	// 가장 간단한 문자열 초기화 방식을 생성자로 표현한다.			42번부터 시작하는 코드보단 39번 코드로 쓰는 것이 더 좋다. 
	Person(int age, const string& sName, GENDER gender) : age(age), sName(sName), gender(gender) {}

	//Person(int age)		// age(age)를 중괄호 안에 쓸 수 있긴하다. 
	//{
	//	this->age = age;	// 39번째 코드와 같은 의미이지만 처리속도가 39번째 코드가 더 빠르고 보기에 간결하다. 
	//}
	
	// 생성자 오버로딩 
	Person(int age, const char* str) : age(age)
	{
		// 메모리 공간에 직접 생성해줘야 한다.
		name = new char[strlen(str) + 1];		                                                                                                                          // this? strlen?                 string name 쓰면 쟤네 둘 안써도 되는건가 
		// 새로 생성한 공간에 외부에 있는 데이터를 복사해서 옮겨와야 한다. 
		strcpy(name, str);
	}

	string ReturnGendertypeName();

	// 소멸자 : 객체가 소멸될 때 자동으로 호출된다. 
	~Person()
	{
		cout << "Person의 소멸자가 호출 되었습니다." << endl;
		delete[] name;
	}



	void Clone(const Person& other);	// 51번 코드의 const는 밖에서 가져온 수를 변경하지 않겠다라는 의미
	

	void Show() const;	// 함수에 const를 붙이는 건 객체 안 데이터를 변경없이 사용하겠다라는 것을 사용자에게 알려주는 의미.
};
 