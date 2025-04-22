#include "Character.h"

void Character::UseSkill(Skill& skill)
{
	skill.Use();
}

void Character::UseHP()
{
	HP -= 10;
}
