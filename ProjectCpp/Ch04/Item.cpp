#include "Item.h"
//#include "GameUtil.h"

/*
 ��ȯ�� ��ü �̸� : �Լ��̸�()		// ��ü�� ����ִ� �Լ��� �����ϴ� ���
*/

void Item::ShowItemInfo()			// ��ȯŸ���� ���� ������ �Լ� �̸��� ���;��Ѵ�. 
{
	{
		cout << "������ �̸�: " << name << ", ����: " << price << ", ������ ���� ����: " << itemCount << ", ������ Ÿ��: " << ReturnByTypeName() << endl;
	}
}

string Item::ReturnByTypeName()
{
	switch (type)
	{
	case ARMOR:
		return "ARMOR";

	case WEAPON:
		return "WEAPON";

	case SHOTGUN:
		return "SHOTGUN";

	default:
		break;
	}
	
}

void nameSpaceExample()
{
	cout << "hi" << endl;

	int number = 0;
	cin >> number;
	cout << "number�� ��: " << number << endl;
}
