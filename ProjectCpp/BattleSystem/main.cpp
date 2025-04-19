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
	Enemy Slime(100, 10, 5, 0,"����", SlimeMove, IDLE);		// ���� ��ü ����
	Player Player(200, 10, 10, 20, "�ΰ�", PlayerIdle, IDLE);		// �÷��̾� ��ü ����

	GameManager Game(Slime, Player);
		
	Game.GameLoop();
}