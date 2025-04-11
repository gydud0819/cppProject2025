/*
* 목표	: cpp 게임 화면 구성하기
* 복습	: Windows.h, GotoXY 재구현하기
* 입출력	: cpp 방식으로 입출력하기
* 이론	: namespace 응용하기
*/

/*
* 이름 공간을 사용할 때의 장점
* 1. 다른 2개의 프로젝트를 copy paste 합칠 때 발생하는 문제를 최소화 할 수 있다.
* 2. 이름 공간에 쓰여진 이름을 통해서 코드를 분류할 수 있다.
*/

/*
* 2025-04-11
* 플레이어의 이동을 참조자를 이용하여 함수화 해보기
*/

#include <iostream>
#include <Windows.h>	// 커서의 위치를 옮기는 함수 
#include <conio.h>

typedef struct NAME
{
	char* name[20];
}name;

namespace ConsoleUtil	// 콘솔기능 모음집
{
	void GotoXY(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void inputPlayerKey(int& x, int& y)
	{
		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_LEFT))
			{
				x -= 2;
				if (x < 0)
				{
					x = 0;
				}
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				x += 2;
				if (x > 30)
				{
					x = 30;
				}
			}
			else if (GetAsyncKeyState(VK_UP))
			{
				y--;
				if (y < 0)
				{
					y = 0;
				}
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				y++;
				if (y > 30)
				{
					y = 30;
				}
			}
		}
	}

	/*void tempFunc(name* &nameptr)
	{
		nameptr.name = 'aaa';
	}*/
}

int main()
{
	// 예제 1. 10,10 좌표에 플레이어의 정보 텍스트를 출력해보기
	ConsoleUtil::GotoXY(10, 10);
	std::cout << "플레이어의 정보" << std::endl;

	// 예제 2. 플레이어의 이름을 입력받아서 플레이어의 정보 텍스트 한줄 아래에 출력해보기 
	// 입력 값을 정수로 받아서, 1을 받으면 플레이어 이름 추가하기
	// 2를 받으면 화면에 플레이어 정보를 출력하기

	char name[20];
	char Job[20];

	while (true)
	{
		int inputNumber = 0;

		//ConsoleUtil::GotoXY(10, 1);
		std::cout << "1_ 사용자의 이름을 변경할 수 있습니다. 2_ 플레이어의 정보를 화면에 출력합니다. 3_종료합니다." << std::endl;
		std::cin >> inputNumber;	// cpp에서는 주소 연산자를 사용하지 않고 바로 쓸 수 있다? 
		if (inputNumber == 1)
		{
			std::cout << "이름을 입력해주세요." << std::endl;
			std::cin >> name;
			/*std::cout << "직업을 입력해주세요." << std::endl;
			std::cin >> Job;*/
		}
		else if (inputNumber == 2)
		{
			ConsoleUtil::GotoXY(10, 10);
			std::cout << "플레이어의 정보";
			ConsoleUtil::GotoXY(10, 11);
			std::cout << "플레이어의 이름 :" << name;
			/*ConsoleUtil::GotoXY(10, 12);
			std::cout << "플레이어의 직업 :" << Job;*/
			_getch();
		}
		/*else if (inputNumber == 3)
		{
			break;
		}*/
		else
		{
			break;
		}
		system("cls");
	}

	int x = 0, y = 0;

	while (true)
	{
		system("cls");
		ConsoleUtil::inputPlayerKey(x, y);
		std::cout << "플레이어의 좌표 : " << "{" <<  x << "," << y << "}" << std::endl;
		ConsoleUtil::GotoXY(x, y);
		std::cout << "■";
		Sleep(50);
	}



}





