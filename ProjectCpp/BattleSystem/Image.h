#pragma once
#include "Common.h"

#define IMAGEHEIGHT 10	// 세로
#define IMAGEWIDTH 10	// 가로

extern char SlimeIdle[IMAGEHEIGHT][IMAGEWIDTH + 1];		//image.cpp에서 char SlimeIdle[IMAGEHEIGHT][IMAGEWIDTH + 1]를 사용했기에 여기선 extern을 붙여 써야한다.
extern char SlimeBattle[IMAGEHEIGHT][IMAGEWIDTH + 1];
extern char SlimeMove[IMAGEHEIGHT][IMAGEWIDTH + 1];

extern char PlayerIdle[IMAGEHEIGHT][IMAGEWIDTH + 1];
extern char PlayerBattle[IMAGEHEIGHT][IMAGEWIDTH + 1];
extern char PlayerMove[IMAGEHEIGHT][IMAGEWIDTH + 1];