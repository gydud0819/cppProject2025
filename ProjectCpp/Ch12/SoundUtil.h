#pragma once
#include <iostream>
#include <Windows.h>
#include <tchar.h>		// 텍스트로 변환해주는 헤더파일

// Winmm.lib : Window Multi Media Library
using namespace std;
class SoundUtil
{
public:
	static void PlayTitlesound(LPCWSTR fileName);
	static void PlayBGM(LPCWSTR fileName);
};

