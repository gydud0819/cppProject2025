/*
* �ۼ���	: 2025-04-15
* �ۼ���	: ��ȿ��
* ����	: 1. namespace ���� �� ���ǻ���
*		  2. cpp ����ü�� ���� ���� (��ü�� ǥ���ϴ� ������ �߰��Ǿ���.)
*		  3. class Ű����
*/

#include "Item.h"
#include "GameUtil.h"
#include "Player.h"

int main()
{
	//nameSpaceExample();

	// 18~22��° �� �ڵ�� ��ü ���� �ڵ带 �ۼ��� �� ���� �����״� ���� ����غ��� ���� ����. 
	Item item1 = { "Butter", 100, 1, ARMOR };
	item1.ShowItemInfo();

	Item item2("Potion", 500, 1, WEAPON);
	item2.ShowItemInfo();
	
	// Ÿ�� item1 �̸� = {�̸�, ����, ��, Ÿ��};

	/*Player playerPos = { 10,10 };
	playerPos.PlayerPos();*/

	COORD playerPos = { 10,10 };

	Player player1 (playerPos, "Apple");
	player1.PlayerPos();
}
