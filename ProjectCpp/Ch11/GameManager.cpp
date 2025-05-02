#include "GameManager.h"

void GameManager::ShowTitle()
{
	// 타이틀을 먼저 보여주는 코드 실행
	//ConsoleUtil::GotoXY(40, 10);
	cout << "타이틀 실행" << endl;
	SoundUtility::PlayBGM2(_T("sound.wav"));	// 사운드 출력이 끝날때 까지 다음 코드로 넘어가지 않는다.
}

void GameManager::ShopPhase()
{
	// 플레이어의 강화 시스템
	system("cls");
	//ConsoleUtil::GotoXY(40, 15);
	cout << "상점에 진입한다." << endl;

	int input = 0;
	cout << "1_maxSpeed가 증가합니다." << endl;
	cout << "2_minSpeed가 증가합니다." << endl;
	cout << "3_게임 시작" << endl;

	cin >> input;
	if (input == 1)
	{
		player->UpGrade(PlayerStat::MAXSPEED, 1);
	}
	else if (input == 2)
	{
		player->UpGrade(PlayerStat::MINSPEED, 1);
	}
	else if (input == 3)
	{
		cout << "게임을 시작합니다." << endl;
	}
	

}

void GameManager::GamePhase()
{
	// 사운드를 출력하는 코드 추가하기 
	//SoundUtility::PlayBGM2(_T("sound.wav"));

	//Player* runA = new Player();
	Runner* runB = new Runner("봇");
	Runner* runC = new Runner("못");
	Runner* runD = new Runner("홋");

	string line = "=========================================================";

	int endLine = line.length();

	player->Initialize();
	runB->Initialize();
	runC->Initialize();
	runD->Initialize();

	Sleep(1000);

	//EnemyRunner* eRunA = new Enemy();


	while (true)
	{
		Sleep(1000);
		system("cls");

		cout << line << endl;
		player->Run();
		runB->Run();
		runC->Run();
		runD->Run();
		//eRunA->EnemyRun();
		cout << line << endl;

		player->ShowPlayerGameInfo();

		if (player->CheckEndLine(endLine) || runB->CheckEndLine(endLine)
			|| runC->CheckEndLine(endLine) || runD->CheckEndLine(endLine)/* ||/*eRunA->CheckEndLine(endLine)*/)
		{
			cout << "경기종료" << endl;
			break;
		}

	}

	if (player->CheckEndLine(endLine))
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
	/*if (eRunA->CheckEndLine(endLine))
	{
		cout << "속도 핵 유저 1등" << endl;
	}*/

	cout << "상점으로 돌아가기 위해서 아무키나 눌러주세요." << endl;
	_getch();
}

void GameManager::Play()
{
	ShowTitle();

	while (true)
	{
		ShopPhase();
		GamePhase();
	}
}
