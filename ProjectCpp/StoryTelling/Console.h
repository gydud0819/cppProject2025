#pragma once
#include <Windows.h>

class Console
{
public:
	static void GotoXY(int x, int y);	// 2번째 GotoXY 적용이 안됨

	static void CursorVisible(bool show);	// 콘솔 커서를 보여주려면 true 아니면 false
	
};

