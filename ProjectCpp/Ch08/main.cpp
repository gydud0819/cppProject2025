/*
* 작성일	: 2025-04-23
* 작성자	: 박효영
* 주제	: 클래스 - 상속
*/
#include "Common.h"
#include "Book.h"
#include "Monster.h"

/*
* 상속 복습
* 1. 공통된 내용을 하나로 묶는 방법
* 2. 언제 상속을 해야하는가? (주의해서 이해할 것)
* 
*/

/*
* 최종 목표
* Unit의 행동 시스템 구현
* 
* 유닛이 공격한다.
* Unit.Attack();
* 
* 단점 : 문제가 발생한다. -> 똑같은 유닛 코드를 실행한다. 
* 해결 방법 : virtual 키워드를 사용하면 실제 코드가 실행된다. 
*/

/*
* Unit 코드를 이용해서 Attack, Stop, Hold 등 함수르 만들었다.
* 상속을 시켜서 특별한 공격을 하도록 한다. 
* 같은 타입의 코드이지만 다른 기능을 실행시킬 수 있다. 
*/

/*
* Monster.Attack();
* Slime. 분열한다.
* Goblin 독화살을 쏜다. 
*/

int main()
{
	//cout << "ch07" << endl;
	Book book;
	Spell_Book spBook;
	Story_Book stBook;
	Quest_Book QBook;

	book.Read();
	spBook.Read();
	stBook.Read();
	QBook.Read();

	Probe probe1(true);
	//probe1.ReturnAttacker()->Attack();	// 코드가 복잡하다

	Attacker* tempAttacker;
	tempAttacker = probe1.ReturnAttacker();		// probe1.ReturnAttacker(); <- 자체가 주소이다. 
	//tempAttacker->Attack();

	Zealot zealot;
	Dragoon dragoon;

	cout << "유닛의 공격 텍스트 출력\n\n" << endl;

	probe1.Attack();
	zealot.Attack();
	dragoon.Attack();

	cout << "Unit으로 표현하기\n" << endl;

	Unit& selectUnit = probe1;		// 공통 타입으로 똑같은 형태로 표현해보기
	Unit& selectUnit2 = zealot;		// 공통 타입으로 똑같은 형태로 표현해보기
	Unit& selectUnit3 = dragoon;		// 공통 타입으로 똑같은 형태로 표현해보기
	
	selectUnit.Attack();
	selectUnit.UseSkill();
	selectUnit2.Attack();
	selectUnit2.UseSkill();
	selectUnit3.Attack();
	selectUnit3.UseSkill();
}