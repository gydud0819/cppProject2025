#include <iostream>

/*
* cpp 추가된 문법을 이해한다.
* 1. std:: 분석
* 2. 코드에서  "std::" 지워보기
* 3. 결과 : 식별자 "cout" 이 정의되어 있지 않습니다.
* Q. iostream을 추가했는데 왜 "cout"을 찾을 수 없을까?
* A. "cout" 특별한 공간에 존재하기 때문에 찾을 수 없다.
* Q. 그 특별한 공간을 어떻게 사용해야 할까?
* A. namespace에 대한 이해가 필요하다.
*/

// A회사 ACom, B회사 BCom
// ACom에서 만든 goods BCom에서 만든 goods
// 문제점 : 특정 키워드의 이름들이 같으면 컴퓨터가 구분해서 판별할 수 없다. == 에러가 발생한다. 
// 변수의 이름앞에 이름공간을 추가해준다.
// ACom - goods다
// BCom - goods다

namespace ACom
{
	char goods[10];
	int sum;
}

namespace BCom
{
	char goods[10];
	int sum;
}

int main()
{
	std::cout << "Ch01" << std::endl;
	std::cout << "소주제 : 이름 공간에 대한 이해" << std::endl;

	/*
	* 이름 공간의 첫번째 예제
	* 같은 이름의 변수를 사용하는 문법이 추가되었다.
	* 사용법 : 이름::변수;
	*/

	char inputName[10];
	std::cin >> ACom::goods;
	std::cout << "A회사의 상품 이름 : " << ACom::goods << std::endl;

	std::cin >> BCom::goods;
	std::cout << "B회사의 상품 이름 : " << BCom::goods << std::endl;

	// 문제1. 5개의 숫자를 입력받아서 A회사의 합계를 저장한 다음 5개의 숫자를 입력 받아서 B회사의 합계에도 저장하기
	// 1. std::cin int 값 입력 받기
	// 2. for반복문을 사용하여 5회 더하기
	// 3. 이름 공간의 sum 변수에 저장하고 출력하기 

	int number = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i++ << "상품의 개수를 입력하세요." << std::endl;	// 마지막에 사용하는 std::endl 문장을 끝내는 느낌으로 사용하면 좋다.
		std::cin >> number;
		// 개수를 입력받은 후에 A회사의 총합을 의미하는 변수에 더해줘야 한다. 
		ACom::sum += number;
	}

	std::cout << "A회사의 상품 총합 : " << BCom::sum << std::endl;

	for (int i = 0; i < 5 ;i++)
	{
		std::cout << i++ << "상품의 개수를 입력하세요." << std::endl;	// 마지막에 사용하는 std::endl 문장을 끝내는 느낌으로 사용하면 좋다.
		std::cin >> number;
		// 개수를 입력받은 후에 A회사의 총합을 의미하는 변수에 더해줘야 한다. 
		BCom::sum += number;
	}

	std::cout << "B회사의 상품 총합 : " << BCom::sum << std::endl;

	// ToyProject 프로젝트. c++ 추가된 문법을 게임에 적용하는 시간
	// 겜프1때 만들었던 프로젝트를 cpp버전으로 이식해도된다.
	// c버전 프로젝트 -> c++ 버전 프로젝트 변경
	// readme 오늘 날짜 Change log
}