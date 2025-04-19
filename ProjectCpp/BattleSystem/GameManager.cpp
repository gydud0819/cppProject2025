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
	// ���� UI ���
	while (true)
	{
		GameUI();


		// �÷��̾��� ���� ���

		// �÷��̾ ���� -> ���Ͱ� �İ�
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
	cout << "�÷��̾��� ����";
	GoToXY(60, 1);
	cout << "�÷��̾��� ü��" << player.HP;
	GoToXY(60, 2);
	cout << "�÷��̾��� ���ݷ�" << player.AP;
	GoToXY(60, 3);
	cout << "�÷��̾��� ����" << player.DEF;
	GoToXY(60, 4);
	cout << "��ų ���� ������" << player.skill;

	GoToXY(80, 0);
	cout << "������ ����";
	GoToXY(80, 1);
	cout << "������ ü��" << currentEnemy.HP;
	GoToXY(80, 2);
	cout << "������ ���ݷ�" << currentEnemy.AP;
	GoToXY(80, 3);
	cout << "������ ����" << currentEnemy.DEF;
}

void GameManager::PlayerTurn()
{
	system("cls");
	GameUI();

	GoToXY(0, 30);
	cout << "���� �÷��̾��� ���Դϴ�." << endl;
	cout << "1_�����Ѵ�. 2_����Ѵ�. 3_��ų�� ����Ѵ�." << endl;

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
		return;  // �� ���� ���� ����
	}
	currentTurnState = ENEMYTURN;
}

void GameManager::EnemyTurn()
{
	system("cls");	// ui���� �� ���� ��ġ�� �� ������ ���� ����Ѵ�. 
	GameUI();

	GoToXY(0, 32);
	cout << "���� ������ ���Դϴ�." << endl;
	player.Attacked(currentEnemy.AP);

	cout << "Ű�� �Է��ϸ� �÷��̾��� ���� ����˴ϴ�." << endl;
	_getch();

	currentTurnState = PLAYERTURN;
}

void GameManager::GameClear()
{
	system("cls");
	cout << "���͸� óġ�߽��ϴ�!";
	//_getch();
}

void GameManager::GameEnd()
{
	
	system("cls");
	cout << "���� ����...";
	//_getch();
}
