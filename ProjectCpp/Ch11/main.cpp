/*
* 작성일	: 2025-04-28
* 작성자	: 박효영
* 주제	: 클래스 정리, 달리기 게임 구현
*/

#include "Base.h"
#include "Runner.h"

void ClassDefaultInfo()
{
	Base* base = new Base();

	delete base;		// pubilc에서 virtual을 선언하는 것이 좋다. 

	Base* dervied = new Derived;
	dervied->Do();

	delete dervied;
}

int main()
{
	ClassDefaultInfo();
	system("cls");
	std::cout << "달리기 게임 코드" << std::endl;

	Runner* runA = new Player();
	Runner* runB = new Runner("B");
	Runner* runC = new Runner("C");
	Runner* runD = new Runner("D");

	string line = "==========================================";

	int endLine = line.length();

	while (true)
	{
		Sleep(1000);
		system("cls");

		cout << line << endl;

		runA->Run();
		runB->Run();
		runC->Run();
		runD->Run();

		cout << line << endl;

		if (runA->CheckEndLine(endLine) || runB->CheckEndLine(endLine)
			|| runC->CheckEndLine(endLine) || runD->CheckEndLine(endLine))
		{
			cout << "경기종료" << endl;
			break;
		}

	}

	if (runA->CheckEndLine(endLine))
	{
		cout << "A가 1등했습니다." << endl;
	}
	if (runB->CheckEndLine(endLine))
	{
		cout << "B가 1등했습니다." << endl;
	}
	if (runC->CheckEndLine(endLine))
	{
		cout << "C가 1등했습니다." << endl;
	}
	if (runD->CheckEndLine(endLine))
	{
		cout << "D가 1등했습니다." << endl;
	}
}