#pragma once
#include "Common.h"
#include "Weapon.h"

class UpgradeSystem
{
public:
	void Upgrade(Weapon* weapon);	// 공통으로 사용하기 때문에 주소로 가져오는 것이 좋다.

};

