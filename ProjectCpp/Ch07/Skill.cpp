#include "Skill.h"
void Mana::Use()
{
	cout << "마나를 사용합니다" << endl;
}

void Stat::Use()
{
	cout << "스탯을 사용합니다" << endl;
}

void Effect::Use()
{
	cout << "이펙트를 사용합니다" << endl;
}

/*
* 캡슐화 : 특정 기능을 구현할 때 외부에서 사용자가 몰라도 되는 내용을 하나의 기능으로 표현하는 것
  
  코드가 실행되어야 하는 순서가 존재한다. (순서가 잘못되면 코드가 꼬인다.)

  스킬 사용하려면?
  1. 마나 사용 (마나가 없으면 스킬을 사용할 수 없다.) - 전제 조건
  2. 스탯으로 부터 데이터를 받아온다. - 데이터 설정
  3. 결과가 출력된다. 
*/

void Skill::Use() 
{
	mana.Use();
	stat.Use();
	effect.Use();
}