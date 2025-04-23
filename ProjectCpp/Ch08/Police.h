#pragma once
#include "Common.h"

class Gun
{

};

class Human
{

};

class Police : public Human // 경찰은 사람이다.
{
private:
	Gun* gun;	// 경찰은 총을 가지고 있다.
};

class Student : public Human
{

};



