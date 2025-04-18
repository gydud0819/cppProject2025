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
	Enemy Slime(100, 10, 1, "라임", SlimeMove, IDLE);		// 몬스터 객체 생성
	Player Player(200, 10, 1, 20, "인간", PlayerIdle, IDLE);		// 플레이어 객체 생성

	/*int slimeX = 60;
	int slimeY = 10;*/

	GameManager Game(Slime, Player);
	
	/*int playerX = 10;
	int playerY = 10;*/

	//Player.ShowPlayerImage(playerX, playerY);

	//_getch();	// 키보드의 아무 버튼이나 눌러야 종료되게 한다. 

	/*
	* 슬라임이 어떤 조건일 때 SlimeIdle이어야 할까?
	* 적이 어떤 조건일 때 Move일까?
	* 적이 어떤 조건일 때 Battle일까?
	*/

	
	 Game.GameLoop();
	

	/*while (true)
	{
		Game.currentEnemy.SetBattleImage(SlimeIdle);
		Game.player.SetPlayerBattleImage(PlayerIdle);
		Sleep(500);
		system("cls");
		
		Game.currentEnemy.SetBattleImage(SlimeMove);
		Game.player.SetPlayerBattleImage(PlayerMove);
		Sleep(500);
		system("cls");

	}*/
}