#pragma once
#include "Enemy.h"
#include "Player.h"
// Player와 Enmey 객체가 필요하다.

struct GameManager
{
	Enemy currentEnemy;		// enemy를 복사해서 사용할 Enemy로 사용한다. 
	TurnSystem currentTurnState;
	Player player;

	GameManager(Enemy enemy, Player player)
		: currentEnemy(enemy), player(player)
	{
		currentTurnState = PLAYERTURN;
	}

	// 게임 루프이자 다른 게임 로직들을 통합한 기능
	void GameLoop();

	void Battle();

	void Animation();

	void GameUI();

	// 함수 기능들
	
	// 플레이어 행동 기능
	void PlayerTurn();

	// 몬스터 행동 기능
	void EnemyTurn();
};
