/*
* �ۼ���	: 2025-04-17
* �ۼ���	: ��ȿ��
* ����	: ��Ʋ�ý��� �����ϱ�
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

#include "Enemy.h"
#include "Player.h"

int main()
{
	Enemy Slime(100, 10, 1, "����", SlimeBattle);		// ���� ��ü ����

	int slimeX = 60;
	int slimeY = 10;

	Player Player("�ΰ�", PlayerIdle);
	
	int playerX = 10;
	int playerY = 10;

	//Player.ShowPlayerImage(playerX, playerY);

	_getch();	// Ű������ �ƹ� ��ư�̳� ������ ����ǰ� �Ѵ�. 

	/*
	* �������� � ������ �� SlimeIdle�̾�� �ұ�?
	* ���� � ������ �� Move�ϱ�?
	* ���� � ������ �� Battle�ϱ�?
	*/

	while (true)
	{
		Slime.SetBattleImage(SlimeIdle, slimeX, slimeY);
		Player.SetPlayerBattleImage(PlayerIdle, playerX, playerY);
		Sleep(500);
		system("cls");
		

		Slime.SetBattleImage(SlimeMove, slimeX, slimeY);
		Player.SetPlayerBattleImage(PlayerMove, playerX, playerY);
		Sleep(500);
		system("cls");


	}
}