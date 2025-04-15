#pragma once
#include "GameUtil.h"

// std::cout, std::cin, std::endl;
// standard : ǥ�� ���̺귯�� std

//using namespace std;	// �ش� �ҽ����� ������ ��� �ڵ带 namespace std�ȿ� �ִ� ������ �Ǵ��϶�� ���̴�. 

/*
* �����ؾ��� ����
* 1. std�ȿ� �ִ� �̸��� ���� Ÿ���� �����͸� ����� ��ȣ�ϴٴ� ������ �߻��Ѵ�.
*/

void nameSpaceExample();

enum ItemType
{
	ARMOR,
	WEAPON,
	SHOTGUN,
};

// �����͸� �����Ѵ�.
// �Լ��� �����Ѵ�. 

// ����ü �ȿ� �Լ��� �־� �����ϰԲ� �Ѵ�. 

struct Item		// ����ü �ȿ� �Լ� ������ �����ϴ�.
{
	std::string name;
	int price;
	int itemCount;
	ItemType type;

	// ������ - ����ü�� �̸��� �����ؾ� �Ѵ�. + ()                    ������ ���ƾ߸� �� �� �ֳ�?
	// ��� �̴ϼȶ�����(member initialize)
	Item(string name, int price, int itemCount, ItemType type)
		: name(name), price(price), itemCount(itemCount), type(type)
	{ }

	void ShowItemInfo();
	
	string ReturnByTypeName();
	
};


