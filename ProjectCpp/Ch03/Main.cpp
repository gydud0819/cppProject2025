/*
* 작성일	: 2025-04-14
* 작성자	: 박효영
* 주제	: 구조체와 참조자
*/

#include <iostream>

/*
* 2일차 수업 복습
* x,y의 정수형 좌료를 함수의 매개변수로 받아서 외부에서 값이 변경되도록 하는
* 함수 playerInputkey(int& x, int& y);
* 반환값 없는 함수. 
* 이름이 PlayerInput(int& a, int& b) 함수를 호출할 수 있다.
* 타입 해석 : 정수형 데이터, 참조한 데이터를 수정할 수 있다. 
*/

/*
* 반환타입 함수이름(타입 이름, ...);{ 실행부분 작성 }
* 
* 1. 반환타입 - 참조자로 사용되는 경우, 아닌 경우
* 2. 매개변수 - 참조자로 사용되는 경우, 아닌 경우 
*/

/*
* 함수 오버로딩(OverLoading)
* 플레이어의 x,y 좌표를 입력받아 좌표를 변경시키는 함수
* 플레이어의 좌표 구조체를 입력받아 좌표를 변경시키는 함수
* 같은 이름의 타입만 다르게 받으면 컴파일러가 구분할 수 있다. 
*/

// C++부터 typedef 선언이 없어도 struct 이름으로 타입과 구조체를 동시에 사용할 수 있다.
struct Pos
{
	int PosX;
	int PosY;
};

/*
* 함수 오버로딩 정리
* C++ 함수를 호출하는 방법을 알려준다. 이름(타입 이름 ),
* 함수 오버로딩은 함수의 이름과 함수의 매개 변수의 타입과 개수로 구분한다. ★
* 매개변수에서 참조자를 사용하면 좀 더 편하게 사용할 수 있다. 
* 
* 주의할 점
* - 반환형이 달라도 같은 함수로 판단한다. (void PlayerInput (), int PlayerInput() 은 오버로드 할 수 없다.)
* - 매개변수의 이름이 달라도 타입의 갯수가 같으면 오버로드 할 수 없다. 
* void PlayerInput(int x, int y);
* void PlayerInput(int a, int b);
* 
* (그럼 이름 다르고 타입의 갯수가 다르면 오버로드 ㅎ ㅏㄹ 수 잇나?)
* void PlayerInput(int x, int y);
* void PlayerInput(int a, int b, int c;);
* 
*/

/*
* 참조자를 반환형에 사용하는 경우
*/

int& ReturnRef()		// int& num1 = ReturnRef();	
					// num 공간에 20을 넣고 5를 더해준다. num의 별명을 num1로 하겠다. 
					// num 지역 변수 함수가 종료되면 소멸한다. 
					// 댕글링 레퍼런스. 
{
	int num = 20;
	num += 5;
	return num;
}

// 구조체 배열
// 아이템, 상점, 인벤토리
// 방해요소 : 선인장
// 슬라임 3종류 : 큰 슬라임, 작은 슬라임, 중간 슬라임
// 참조자를  이 개념에 대입해본다. 

void PlayerInput()	// 이름 PlayerInput, 매개 변수 0개
{
	std::cout << "PlayerInput 함수 실행" << std::endl;
}

void PlayerInput(Pos& playerPos)	// 이름 PlayerInput, 매개 변수 1개 Pos& 
{
	playerPos.PosX += 1;
	playerPos.PosY += 1;
}

void PlayerInput(int& a, int& b) // 이름 PlayerInput, 매개 변수 2개
{
	a += 1;
	b += 1;
}

int main()
{
	std::cout << "ch03" << std::endl;

	int playerX = 0;
	int playerY = 0;

	PlayerInput(playerX, playerY);
	std::cout << "playerInput 출력 결과" << std::endl;
	std::cout << "x의 값 : " << playerX << "," << "y의 값 : " << playerY << std::endl;

	Pos playerPos = { playerX, playerY };
	PlayerInput(playerPos);
	std::cout << "playerInput 출력 결과" << std::endl;
	std::cout << "x의 값 : " << playerPos.PosX << "," << "y의 값 : " << playerPos.PosY << std::endl;

	PlayerInput();
}