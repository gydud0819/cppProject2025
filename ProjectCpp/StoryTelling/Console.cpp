#include "Console.h"

void Console::GotoXY(int x, int y)
{
	COORD pos = { static_cast<short>(x), static_cast<short>(y) };	//  static_cast<short>(x), static_cast<short>(y) 자료구조때 문법 배울예정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console::CursorVisible(bool show)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorinfo;
	GetConsoleCursorInfo(hConsole, &cursorinfo);
	cursorinfo.bVisible = show;
	SetConsoleCursorInfo(hConsole, &cursorinfo);
}
