/*
* 작성일	: 2025-04-16
* 작성자	: 박효영
* 주제	: 데이터 복사(얕은 복사와 깊은 복사에 대한 이해)
*/

#include "CUtil.h"
#include "Person.h"

/*
* 예제 문제
* person.h에서 성별 추가하기
* enum GENDER
* {
*	Male
*	FeMale
* }
*/

void example()	// 데이터 복사에 대한 개념 
{
	std::cout << "ch05: 데이터 복사" << std::endl;

	// 정수를 저장하는 데이터 타입(int) 변수를 2개 선언하기.
	int numA = 10;
	// numB, numA에 저장되어 있는 값을 B에 옮기고 싶다.
	int numB = numA;

	int* numAptr = &numA;
	int* numBptr = numAptr;

	// numBptr에 들어간 주소와 numAptr에 들어간 주소, numA의 주소가 모두 같은가? 모두 같다. 

	cout << "numA의 주소" << &numA << endl;
	cout << "numAptr의 주소" << numAptr << endl;
	cout << "numBptr의 주소" << numBptr << endl;

	// 변수끼리 대입연산자를 사용한 경우
	// numA와 numB는 각각 다른 공간에 존재한다. 
	// 주소끼리 대입연산자를 사용한 경우
	// numAptr과 numBptr은 주소가 가리키는 값이 같다. 

	// numA, numAptr, numBptr 주소의 값이 모두 동일하다.
	// 해당 주소를 하나의 변수에서 제거하면 다른 변수에서 접근을 할 수 없게된다. 
}

int main()
{
	//example();

	//Person human1 = {20};	// human1이라는 공간에 데이털르 복사해서 넣어줘야 한다. 
	Person human1(20, "법사", Male);
	Person human1Clone;
	Person human2(30, "칠리", FeMale);
	human1Clone.Clone(human1);
	human1.Show();
	human1Clone.Show();
	human2.Show();
}