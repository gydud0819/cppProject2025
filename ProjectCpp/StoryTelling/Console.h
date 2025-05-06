#pragma once
#include <Windows.h>

class Console
{
public:
	static void GotoXY(int x, int y)	// 2번째 GotoXY 적용이 안됨
	{
		COORD pos = { static_cast<short>(x), static_cast<short>(y) };	//  static_cast<short>(x), static_cast<short>(y) 자료구조때 문법 배울예정
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	static void CursorVisible(bool show)	// 콘솔 커서를 보여주려면 true 아니면 false
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorinfo;
		GetConsoleCursorInfo(hConsole, &cursorinfo);
		cursorinfo.bVisible = show;
		SetConsoleCursorInfo(hConsole, &cursorinfo);
	}
};

