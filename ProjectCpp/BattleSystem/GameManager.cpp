#include "GameManager.h"

void GameManager::GameLoop()
{
	while (true)
	{
		Animation();
		Battle();

		if (currentTurnState == GAMECLEAR)
		{
			GameClear();
			break;
		}
		else if (currentTurnState == GAMEEND)
		{
			GameEnd();
			break;
		}
	}
}

void GameManager::Battle()
{
	// 전투 UI 출력
	while (true)
	{
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
		else if (currentEnemy.isDeath)
		{
			currentTurnState = GAMECLEAR;
			break;
		}
		else if (player.isDeath)
		{
			currentTurnState = GAMEEND;
			break;
		}
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
	GoToXY(60, 4);
	cout << "스킬 사용시 데미지" << player.skill;

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
	system("cls");
	GameUI();

	GoToXY(0, 30);
	cout << "현재 플레이어의 턴입니다." << endl;
	cout << "1_공격한다. 2_방어한다. 3_스킬을 사용한다." << endl;

	int input = 0;
	cin >> input;
	switch (input)
	{
	case 1: currentEnemy.Attacked(player.AP); break;
	case 2: player.Defence(); break;
	case 3: player.Skill(&currentEnemy, player.skill); break;
	default:
		break;
	}
	if (currentEnemy.isDeath) 
	{
		currentTurnState = GAMECLEAR;
		return;  // 턴 상태 변경 막기
	}
	currentTurnState = ENEMYTURN;
}

void GameManager::EnemyTurn()
{
	system("cls");	// ui오류 및 글자 겹치는 것 방지를 위해 사용한다. 
	GameUI();

	GoToXY(0, 32);
	cout << "현재 몬스터의 턴입니다." << endl;
	player.Attacked(currentEnemy.AP);

	cout << "키를 입력하면 플레이어의 턴이 진행됩니다." << endl;
	_getch();

	currentTurnState = PLAYERTURN;
}

void GameManager::GameClear()
{
	system("cls");
	cout << "몬스터를 처치했습니다!";
	//_getch();
}

void GameManager::GameEnd()
{
	
	system("cls");
	cout << "게임 오버...";
	//_getch();
}
