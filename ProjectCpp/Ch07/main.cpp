#include "Skill.h"
#include "Money.h"
#include "Character.h"
#include "Enemy.h"

// A. player
// 
class Player : public Entity
{
private:
	Skill skill;
	Money money;
};

class BattleManager
{
private:
	Player player;
	Enemy enemy;

	bool isEnd;

	void EnemyTurn()
	{
		enemy.Action();
	}
	void PlayerTurn()
	{
		player.GetATK();
	}
public:
	void Battle()
	{
		while (true)
		{
			PlayerTurn();
			EnemyTurn();

			if (isEnd)
			{
				break;
			}
		}
	}
};

int main()
{
	/*Skill skill;
	Money money;

	skill.Use();

	Character player1;
	player1.*/

	BattleManager battle;
}