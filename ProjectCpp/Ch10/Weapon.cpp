#include "Weapon.h"

int Weapon::DoUpgrade()
{
    return Lv * (baseATK + Weight);
}

void Weapon::ShowInfo()
{
    cout << name << endl; 
    cout<< "최종 공격력" << DoUpgrade() << endl;
}

void Weapon::Attack()
{
    cout << DoUpgrade();
}

void Weapon::Upgrade()
{
    DoUpgrade();
}

void Spear::Attack()
{
    Weapon::Attack();
    cout << "창으로 찌른다." << endl;
}

void Spear::Upgrade()
{
    // 창마다 고유의 공격력 만큼 추가로 공격력이 오른다.
    FinalATK = DoUpgrade() + specialATK;
    cout << FinalATK << "창 업그레이드 방식으로 공격력이 상승했다." << endl;
}

void Sword::Attack()
{
    Weapon::Attack();
    cout << "검으로 벤다." << endl;
}

void Sword::Upgrade()
{
    // 10의 공격력이 추가로 상승한다. 
    FinalATK = DoUpgrade() + 10;
    cout << FinalATK << "검 업그레이드 방식으로 공격력이 상승했다." << endl;
}

void Arrow::Attack()
{
    Weapon::Attack();
    cout << "활을 쏜다." << endl;
}

void Arrow::Upgrade()
{
    FinalATK = DoUpgrade() + 20;
    cout << FinalATK << "활 업그레이드 방식으로 공격력이 상승했다." << endl;
}
