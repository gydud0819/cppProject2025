/*
* 작성일	: 2025-04-25
* 작성자	: 박효영
* 주제	: ?????
* 목표	: 클래스 간에 관계 정의 후 어떻게 코딩을 할 것인가
* 상속을 이용한 객체로 시스템을 구현한다. 
*/

/*
* 강화 시스템을 상속과 함께 구현한다. 
* lv + (baseATK*Wieght) = 최종 공격력
*/
#include "Common.h"
#include "Weapon.h"
#include "UpgradeSystem.h"
#include "RandomUtil.h"

int main()
{
	/*Weapon weapon("abc", 1, 3, 5);
	weapon.ShowInfo();
	weapon.Attack();

	Weapon weapon2("def", 2, 4, 6);
	weapon2.ShowInfo();
	weapon2.Attack();*/

	/*Spear spear("삼지창", 1, 3, 5, 3);
	spear.ShowInfo();
	spear.Attack();

	Sword sword("마검", 2, 3, 4, 5);
	sword.ShowInfo();
	sword.Attack();

	Arrow arrow("활", 5, 6, 7, 4);
	arrow.ShowInfo();
	arrow.Attack();*/



	// 다형성
	// 같은 모습인데 다르게 표현할 수 있다. 
	

	// 포인터
	// 특정 타입의 공간을 가리킨다.
	// Weapon이 Spear을 가리키면 어떤 결과가 나올까?
	
	
	/*Weapon* wptr = &spear;
	Weapon* sptr = &sword;
	Weapon* aptr = &arrow;
	wptr->Attack();
	sptr->Attack();
	aptr->Attack();

	UpgradeSystem upgaradeSystem;
	upgaradeSystem.Upgrade(&spear);
	upgaradeSystem.Upgrade(&sword);
	upgaradeSystem.Upgrade(&arrow);*/

	int random = RandomUtil::GetRandomInt(100);

	if (random > 70)
	{
		cout << "성공" << endl;
	}
	else
	{
		cout << "실패" << endl;
	}

	int rand = RandomUtil::GetRandomInt(5);

	//string name = "ddd";
	//int Lv = 1;			// 레벨
	//int baseATK = 5;	// 기본 공격력
	//int Weight = 3;		// 가중치

	//int FinalATK = Lv + (baseATK * Weight);
	//cout << name << "최종공격력" << FinalATK << endl;

	//string name2 = "aaa";
	//int Lv2 = 2;			// 레벨
	//int baseATK2 = 7;	// 기본 공격력
	//int Weight2 = 5;		// 가중치

	//int FinalATK2 = Lv2 + (baseATK2 * Weight2);
	//cout << name2 <<  "최종공격력" << FinalATK2 << endl;
}