/*
* 작성일	: 2025-04-17, 18
* 작성자	: 박효영
* 주제	: 배틀시스템 구현하기 (game manager 구현하기)
* Common.h 헤더 파일 만들기
* GotoXY();
*
* 필요한 객체
* Player, Enemy, Monster, Slime
*
* Game, Stage, Monster Manager
*/

/*
* 전투 == Battle
*
* 전투 대상 : Player, Enemy
* 체력, 공격력, 방어력 등
*
* 사망하다. (체력이 0보다 작거나 같을 때)
* 공격을 받았을 때 체력을 조작하는 기능(함수)
* 공격을 받았다. 포션을 먹는다.
*/

#include "GameManager.h"

int main()
{
	Enemy Slime(100, 10, 5, 0,"라임", SlimeMove, IDLE);		// 몬스터 객체 생성
	Player Player(200, 10, 10, 20, "인간", PlayerIdle, IDLE);		// 플레이어 객체 생성

	GameManager Game(Slime, Player);
		
	Game.GameLoop();
}