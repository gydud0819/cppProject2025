/*
* �ۼ���	: 2025-04-17, 18
* �ۼ���	: ��ȿ��
* ����	: ��Ʋ�ý��� �����ϱ� (game manager �����ϱ�)
* Common.h ��� ���� �����
* GotoXY();
*
* �ʿ��� ��ü
* Player, Enemy, Monster, Slime
*
* Game, Stage, Monster Manager
*/

/*
* ���� == Battle
*
* ���� ��� : Player, Enemy
* ü��, ���ݷ�, ���� ��
*
* ����ϴ�. (ü���� 0���� �۰ų� ���� ��)
* ������ �޾��� �� ü���� �����ϴ� ���(�Լ�)
* ������ �޾Ҵ�. ������ �Դ´�.
*/

#include "GameManager.h"

int main()
{
	Enemy Slime(100, 10, 1, "����", SlimeMove, IDLE);		// ���� ��ü ����
	Player Player(200, 10, 1, 20, "�ΰ�", PlayerIdle, IDLE);		// �÷��̾� ��ü ����

	/*int slimeX = 60;
	int slimeY = 10;*/

	GameManager Game(Slime, Player);
	
	/*int playerX = 10;
	int playerY = 10;*/

	//Player.ShowPlayerImage(playerX, playerY);

	//_getch();	// Ű������ �ƹ� ��ư�̳� ������ ����ǰ� �Ѵ�. 

	/*
	* �������� � ������ �� SlimeIdle�̾�� �ұ�?
	* ���� � ������ �� Move�ϱ�?
	* ���� � ������ �� Battle�ϱ�?
	*/

	
	 Game.GameLoop();
	

	/*while (true)
	{
		Game.currentEnemy.SetBattleImage(SlimeIdle);
		Game.player.SetPlayerBattleImage(PlayerIdle);
		Sleep(500);
		system("cls");
		
		Game.currentEnemy.SetBattleImage(SlimeMove);
		Game.player.SetPlayerBattleImage(PlayerMove);
		Sleep(500);
		system("cls");

	}*/
}