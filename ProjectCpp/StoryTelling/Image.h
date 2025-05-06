#pragma once
#include <iostream>
#include <string>
#include "Console.h"

// 1차원 데이터를 2차원 배열로 변환 후 보여주는 객체
class Image
{
private:
	char art[50][100];		// 이미지 크기에 맞게 설정을 해줘야한다. 
	int height;		// 10보다 작아야함

public:
	Image(const char* model, int height)
	{
		this->height = height;

		const char* lineStart = model;
		for (int i = 0; i < height; i++)
		{
			const char* lineEnd = strchr(lineStart, '\n');	// i번째 줄에서 개행문자를 찾아라
			if (lineEnd == nullptr)
			{
				lineEnd = model + strlen(model);	// 마지막 줄을 표현한다. 
			}
			int length = lineEnd - lineStart;
			strncpy_s(this->art[i], lineStart, length);
			lineStart = lineEnd + 1;
		}
	}

	void Show(int x, int y) const
	{
		for (int i = 0; i < height; i++)
		{
			Console::GotoXY(x, y + i);
			std::cout << art[i];
		}
	}

	void move(int x, int y, int moveDistance, int delay)		// 
	{
		for (int i = 0; i < moveDistance; i++)
		{

			for (int j = 0; j < height; j++)
			{
				Console::GotoXY(x + i, y + j);
				std::cout << art[j];

			}
			Sleep(delay);
			system("cls");
		}
	}

	void moveReverse(int x, int y, int moveDistance, int delay)
	{
		for (int i = 0; i < moveDistance; i++)
		{
			int currentX = x - i;
			if (currentX < 0)		// 콘솔에서 x가 0보다 작으면 에러가 발생한다.
			{
				currentX = 0;
			}

			for (int j = 0; j < height; j++)
			{
				Console::GotoXY(currentX, y + j);
				std::cout << art[j];

			}
			Sleep(delay);
			system("cls");
		}
	}
};

