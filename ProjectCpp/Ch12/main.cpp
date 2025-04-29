#include <iostream>
#include <Windows.h>
#include <tchar.h>		// 텍스트로 변환해주는 헤더파일
#include "SoundUtil.h"

// Winmm.lib : Window Multi Media Library
using namespace std;

/*
* visual studio Audio file 출력하는 방법 
* Windows.h 안에 PlayerSound 함수가 들어잇음
* 
* SND_SYNC		: 사운드 파일이 실행되고 난 후에 아래 코드를 실행한다. (동기식 코드)
* SND_ASYNC	: 아래 코드와 별개로 파일이 실행된다. (비동기식 코드)
* 
* L"hello world"; -> 방식으로 써야한다. 
* 
* bool isPlay = PlaySound(_T("sound.wav"), NULL, SND_ASYNC);	// 소리가 출력되고 있다면 true 아니면 false
*/ 		

int main()
{
	cout << "bgm 추가" << endl;

	SoundUtil::PlayBGM(_T("sound.wav"));

	while (true)
	{
		
	}
}
