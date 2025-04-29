#pragma once
#include "Common.h"

class RandomUtil
{
public:
	static int GetRandomInt(int range);

	//uniform_int_distribution
};

class ConsoleUtil
{
public:
	static void GotoXY(int x, int y);
};

class SoundUtility
{
public:
	static void PlayTitleBGM(LPCWSTR sound);
	static void PlayBGM2(LPCWSTR sound);
};

