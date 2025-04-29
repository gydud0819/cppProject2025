/*
* 작성일	: 2025-04-28, 29
* 작성자	: 박효영
* 주제	: 클래스 정리, 달리기 게임 구현 
		  (bgm 파일 넣기 및 유틸 클래스 구현)
		  상속 관계... ㅖ? 
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

	// 사운드를 출력하는 코드 추가하기 
	SoundUtility::PlayBGM2(_T("sound.wav"));
	

	Runner* runA = new Player();
	Runner* runB = new Runner("봇");
	Runner* runC = new Runner("못");
	Runner* runD = new Runner("홋");

	EnemyRunner* eRunA = new Enemy();

	string line = "======================================================";

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

		eRunA->EnemyRun();

		cout << line << endl;

		if (runA->CheckEndLine(endLine) || runB->CheckEndLine(endLine)
			|| runC->CheckEndLine(endLine) || runD->CheckEndLine(endLine)||eRunA->CheckEndLine(endLine))
		{
			cout << "경기종료" << endl;
			break;
		}

	}

	if (runA->CheckEndLine(endLine))
	{
		cout << "옷 1등 ♥" << endl;
	}
	if (runB->CheckEndLine(endLine))
	{
		cout << "봇 1등 ♥" << endl;
	}
	if (runC->CheckEndLine(endLine))
	{
		cout << "못 1등 ♥" << endl;
	}
	if (runD->CheckEndLine(endLine))
	{
		cout << "홋 1등 ♥" << endl;
	}
	if (eRunA->CheckEndLine(endLine))
	{
		cout << "속도 핵 유저 1등" << endl;
	}
}