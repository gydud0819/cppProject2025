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

	int slimeX = 30;
	int slimeY = 10;

	Player player("�ΰ�", PlayerIdle);
	
	int playerX = 10;
	int playerY = 5;

	player.ShowPlayerImage(playerX, playerY);

	_getch();	// Ű������ �ƹ� ��ư�̳� ������ ����ǰ� �Ѵ�. 

	/*
	* �������� � ������ �� SlimeIdle�̾�� �ұ�?
	* ���� � ������ �� Move�ϱ�?
	* ���� � ������ �� Battle�ϱ�?
	*/

	while (true)
	{
	/*	Slime.SetBattleImage(SlimeIdle, slimeX, slimeY);
		Sleep(500);
		system("cls");
		Slime.SetBattleImage(SlimeMove, slimeX, slimeY);
		Sleep(500);
		system("cls");*/


	}
}