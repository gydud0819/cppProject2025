/*
* 작성일	: 2025-04-15
* 작성자	: 박효영
* 주제	: 1. namespace 사용법 및 주의사항
*		  2. cpp 구조체의 변경 사항 (객체를 표현하는 문법이 추가되었다.)
*		  3. class 키워드
*/

#include "Item.h"
#include "GameUtil.h"
#include "Player.h"

int main()
{
	//nameSpaceExample();

	// 18~22번째 줄 코드는 객체 지향 코드를 작성할 때 많이 쓰일테니 자주 사용해보는 것이 좋다. 
	Item item1 = { "Butter", 100, 1, ARMOR };
	item1.ShowItemInfo();

	Item item2("Potion", 500, 1, WEAPON);
	item2.ShowItemInfo();
	
	// 타입 item1 이름 = {이름, 가격, 수, 타입};

	/*Player playerPos = { 10,10 };
	playerPos.PlayerPos();*/

	COORD playerPos = { 10,10 };

	Player player1 (playerPos, "Apple");
	player1.PlayerPos();
}
