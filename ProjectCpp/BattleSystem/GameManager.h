#pragma once
#include "Enemy.h"
#include "Player.h"
// Player�� Enmey ��ü�� �ʿ��ϴ�.

struct GameManager
{
	Enemy currentEnemy;		// enemy�� �����ؼ� ����� Enemy�� ����Ѵ�. 
	TurnSystem currentTurnState;
	Player player;

	GameManager(Enemy enemy, Player player)
		: currentEnemy(enemy), player(player)
	{
		currentTurnState = PLAYERTURN;
	}

	// ���� �������� �ٸ� ���� �������� ������ ���
	void GameLoop();

	void Battle();

	void Animation();

	void GameUI();

	// �Լ� ��ɵ�
	
	// �÷��̾� �ൿ ���
	void PlayerTurn();

	// ���� �ൿ ���
	void EnemyTurn();
};
