/*
* 작성일	: 2025-04-11
* 작성자	: 박효영
* 주제	: 참조자
*/

/*
* C와 C++ 차이점2 : 참조자 
*/

#include <iostream>

/*
* 참조자 이해를 위한 Swap함수 구현하기
*/

void SwapByValue(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;

	// 위 함수를 메인에서 호출했을 때 num1, num2에 전달한 변수가 변경되는가? 아니오
}

void SwapByRef(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	// num1, num2에 전달된 변수가 실제로 변경된다.
}

// 함수의 오버로딩으로 인해 함수의 이름이 같아도 매개 변수의 타입이 다르면 구분할 수 있다. (다음주 월요일에 추가로 더 할 예정)
void SwapByRef(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// 문제 1. SwapPointer 만들기. 주소를 참조자로 변경하는 함수 만들기
// int type 사용하기

// 변수만 참조자로 만들 수 있는 게 아닌 주소, 배열 원소도 참조자로 만들 수 있다. 
// int arr[3] = {1,2,3};
// int& arrRef1 = arr[0];

// int num1 = 10;
// int* num1ptr = &num1;
// int* (&num1Ref) =  num1ptr; num1Ref는 num1ptr의 별명이다. 

void SwapPointer(int* &num1ptr, int* &num2ptr)
{
	int* temp = num1ptr;
	num1ptr = num2ptr;
	num2ptr = temp;
}

int main()
{
	// namespace st로 정의되어있는 공간안에 cout을 가져와서 사용하겠다.
	std::cout << "2강_ 참조자\n" << std::endl;

	// 참조자 선언과 사용이 구분된다. (구분해서 사용한다.)
	// 함수도 선언과 사용이 구분된다.
	 
	// 참조자 선언
	int num1 = 1;

	int* numptr1 = &num1;	// num1ptr 포인터 변수에 num1의 주소를 저장한다. 

	int& num1ref = num1;	// num1이라는 변수를 참조하는 num1ref. (num1ref는 num1의 참조자다.) num1 별명을 추가해주겠다. num1ref

	num1ref += 1;

	//int num2 = num1;		// num2의 값은 1이다.	
	//num1++;					// num1의 값은 2이다.
	std::cout << "num1의 값 : " << num1 << std::endl;
	std::cout << "num1의 값을 num1ref 참조자로 호출한다: " << num1ref << std::endl;

	// 참조자는 별명이다. 
	// A, 개 (A의 별명)
	// A야 ~ 해라		// 둘다 같은 의미
	// 개야 ~ 해라		// 둘다 같은 의미

	// 참조자를 어디에 사용할까?

	int input = 0;
	// scanf("%d"), &input
	// 참조자 활용의 장점 : C++ 참조를 사용해서 함수를 사용할 때 *, & 를 사용하지 않고 표현할 수 있다.
	//std::cin >> input;

	// SwapByValue, SwapByRef 예제
	std::cout << "Call By Value 와 Call By Reference 예제\n" << std::endl;
	int value1 = 10, value2 = 20;

	std::cout << "Call By Value 결과\n" << std::endl;
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	SwapByValue(value1, value2);
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	
	std::cout << "Call By Reference 결과\n" << std::endl;
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	SwapByRef(&value1, &value2);
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;

	std::cout << "Call By Value 결과\n" << std::endl;
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	SwapByRef(value1, value2);
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;

	// 
	std::cout << "참조자의 응용\n" << std::endl;

	int Num1 = 1;
	int Num2 = 100;

	int* Num1ptr = &Num1;
	int* Num2ptr = &Num2;

	std::cout << "Num1ptr로부터 값 출력 : " << *Num1ptr << std::endl;
	std::cout << "Num2ptr로부터 값 출력 : " << *Num2ptr << std::endl;

	SwapPointer(Num1ptr, Num2ptr);

	std::cout << "Num1ptr로부터 값 출력 : " << *Num1ptr << std::endl; 
	std::cout << "Num2ptr로부터 값 출력 : " << *Num2ptr << std::endl;

	// 참조자를 사용하면 포인터에 사용된 기호를 1개 줄여서 표현할 수 있다.
	// int, int 끼리의 바꿀 때는 참조자를 사용한다.
	// int*, int* 끼리 바꿀때는 int*& int*&를 사용한다. 

	// 참조자 사용시 주의할 점
	// int& ref;	// 에러1. 참조자는 선언할 때 반드시 초기화가 필요하다. == 이니셜라이저가 필요하다.
	int ref = 10;
	int& refRef = ref;	// 에러1. 해결 결과 

	// const를 활용하여 함수를 사용하는 사람에게 가이드를 안내해줄 것 
	// void Func(const int* num1); num1을 참조하는 값을 변경하지 마라.
	// void Func(const int& num1); num1 참조 값을 변경하지 마라.

	// return 타입에 참조자를 선언할 때 주의해야 한다. 

	// main함수에서의 선언		|		함수의 값 리턴(int func())		|		함수에서 참조자 리턴(int& func())
	// int a = func();			|		a의 값이 복사된다.				|		a에 값이 복사된다. func안에서 지역 변수를 return하지 말아야 한다. 
	// -------------------------|---------------------------------------|---------------------------------------------------------------
	// int& a = func();			|		a는 func리턴 값을 별명으로 한다.	|		func안에서 지역 변수를 return하지 않아야 한다.
	//							|		a별명에 10을 별명으로 한다.		|
	//							|		a = 9; 10을 9로 해라.			|
	//							|		컴파일 에러가 발생.				|
	// -------------------------|---------------------------------------|---------------------------------------------------------------
	// const int& a = func();	|		a별명을 10의 별명으로 해라.		|		func안에서 지역 변수를 return하지 않아야 한다.
	//							|		10의 별명을 a라고 한다.			|
	//							|		const int& a = 10;				|
}