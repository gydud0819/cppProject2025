#pragma once
#include "GameUtil.h"

struct Player
{
	// �÷��̾� ��ǥ ������ �����ϱ�
	COORD playerPos;
	string name;
	// ��ǥ�� ��������� �Լ��� �����ϱ�
	void PlayerPos();

	Player(COORD playerPos, string name)
		:playerPos(playerPos), name(name)
	{ }
};