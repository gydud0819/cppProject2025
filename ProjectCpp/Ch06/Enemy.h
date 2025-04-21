#pragma once
#include <iostream>

using namespace std;

class Enmey : public HP
{
public:
	int HP;
	int MaxHP;
	bool isDeath;
private:
	void AttackedBy(int damage);
	void Recovery(int heal);
};


