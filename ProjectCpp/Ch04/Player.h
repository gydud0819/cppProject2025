#pragma once
#include "GameUtil.h"

struct Player
{
	// 플레이어 좌표 데이터 정의하기
	COORD playerPos;
	string name;
	// 좌표를 기능적으로 함수로 구현하기
	void PlayerPos();

	Player(COORD playerPos, string name)
		:playerPos(playerPos), name(name)
	{ }
};