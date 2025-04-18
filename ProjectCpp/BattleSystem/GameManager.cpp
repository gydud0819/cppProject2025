#include "GameManager.h"

void GameManager::GameLoop()
{
	while (true)
	{
		Animation();
		Battle();

		
	}
}

void GameManager::Battle()
{
	// 전투 UI 출력
	GameUI();


	// 플레이어의 조작 기능

	// 플레이어가 선공 -> 몬스터가 후공
	if (currentTurnState == PLAYERTURN)
	{
		PlayerTurn();
	}
	else if (currentTurnState == ENEMYTURN)
	{
		EnemyTurn();
	}
	else if (currentTurnState == GAMECLEAR)
	{
		// 게임 클리어 조건일 때 실행
	}
	else if (currentTurnState == GAMEEND)
	{
		// 플레이어가 죽거나 몬스터가 죽을 때 실행 
	}
}

void GameManager::Animation()
{
	system("cls");
	currentEnemy.SetBattleImage(SlimeIdle);
	player.SetPlayerBattleImage(PlayerIdle);
	Sleep(500);
	system("cls");

	currentEnemy.SetBattleImage(SlimeMove);
	player.SetPlayerBattleImage(PlayerMove);
	Sleep(500);
}

void GameManager::GameUI()
{
	GoToXY(60, 0);
	cout << "플레이어의 정보";
	GoToXY(60, 1);
	cout << "플레이어의 체력" << player.HP;
	GoToXY(60, 2);
	cout << "플레이어의 공격력" << player.AP;
	GoToXY(60, 3);
	cout << "플레이어의 방어력" << player.DEF;

	GoToXY(80, 0);
	cout << "몬스터의 정보";
	GoToXY(80, 1);
	cout << "몬스터의 체력" << currentEnemy.HP;
	GoToXY(80, 2);
	cout << "몬스터의 공격력" << currentEnemy.AP;
	GoToXY(80, 3);
	cout << "몬스터의 방어력" << currentEnemy.DEF;
}

void GameManager::PlayerTurn()
{
	GoToXY(0, 30);
	cout << "현재 플레이어의 턴입니다." << endl;
	cout << "1_공격한다. 2_방어한다. 3_스킬을 사용한다." << endl;

	int input = 0;
	cin >> input;
	switch (input)
	{
	case 1: currentEnemy.Attacked(player.AP); break;
	case 2: player.Defence(); break;
	case 3: player.Skill(player.skill); break;
	default:
		break;
	}
	currentTurnState = ENEMYTURN;
}

void GameManager::EnemyTurn()
{
	GoToXY(0, 32);
	cout << "현재 몬스터의 턴입니다." << endl;
	player.Attacked(currentEnemy.AP);

	cout << "키를 입력하면 플레이어의 턴이 진행됩니다." << endl;
	_getch();

	currentTurnState = PLAYERTURN;
}
