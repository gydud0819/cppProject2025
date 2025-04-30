/*
* 작성일	: 2025-04-28, 29
* 작성자	: 박효영
* 주제	: 클래스 정리, 달리기 게임 구현 
		  (bgm 파일 넣기 및 유틸 클래스 구현)
		  상속 관계... ㅖ? 
*/

#include "Base.h"
#include "GameManager.h"

void ClassDefaultInfo()
{
	Base* base = new Base();

	delete base;		// pubilc에서 virtual을 선언하는 것이 좋다. 

	Base* dervied = new Derived;
	dervied->Do();

	delete dervied;
}

int main()
{
	GameManager Game;
	Game.Play();

	//ClassDefaultInfo();
	
}