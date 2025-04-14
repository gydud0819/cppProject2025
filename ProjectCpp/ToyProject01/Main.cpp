/*
* ��¥	: 2025-04-10 1���� 
* ��ǥ	: cpp ���� ȭ�� �����ϱ�
* ����	: Windows.h, GotoXY �籸���ϱ�
* �����	: cpp ������� ������ϱ�
* �̷�	: namespace �����ϱ�
*/

/*
* �̸� ������ ����� ���� ����
* 1. �ٸ� 2���� ������Ʈ�� copy paste ��ĥ �� �߻��ϴ� ������ �ּ�ȭ �� �� �ִ�.
* 2. �̸� ������ ������ �̸��� ���ؼ� �ڵ带 �з��� �� �ִ�.
*/

/*
* 2025-04-11 2����
* �÷��̾��� �̵��� �����ڸ� �̿��Ͽ� �Լ�ȭ �غ���
*/

/*
* 2025-04-14 3���� 
* ����ü�� �����ڸ� Ȱ���Ͽ� ������ �Լ� �����
*/

#include <iostream>
#include <Windows.h>	// Ŀ���� ��ġ�� �ű�� �Լ� 
#include <conio.h>		// �Է� ��� �Լ�, _getch() ��밡��
#include <string>		// ���ڿ��� ����� �����ϰ� �ִ� ���̺귯��
#include <iomanip>		// input output manipulate 

using namespace std;	// ���� ������ ���� 

typedef struct NAME
{
	char* name[20];
}name;

namespace ConsoleUtil	// �ֱܼ�� ������
{
	void GotoXY(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void inputPlayerKey(int& x, int& y)
	{
		if (_kbhit())
		{
			if (GetAsyncKeyState(VK_LEFT))
			{
				x -= 2;
				if (x < 0)
				{
					x = 0;
				}
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				x += 2;
				if (x > 30)
				{
					x = 30;
				}
			}
			else if (GetAsyncKeyState(VK_UP))
			{
				y--;
				if (y < 0)
				{
					y = 0;
				}
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				y++;
				if (y > 30)
				{
					y = 30;
				}
			}
		}
	}

	/*void tempFunc(name* &nameptr)
	{
		nameptr.name = 'aaa';
	}*/
}

struct Item
{
	//char name[20];	// std::string => �̸��� ũ�⸦ �ڵ����� �Ҵ����ش�. 
	std::string name;	// Ŭ������ ���� �� �� �ִ�. (���߿� ��� ����)
	int price;
};

// Item ����ü�� �����ڸ� �޾ƿͼ� �̸��� ������ ���ϴ� �̸��� �������� �����ϴ� �Լ� �����

// const, ������, ������ ����ü ����ϱ� 

// SetItem(item1, "Sword", 100)
void MySetItem(Item& item)
{
	std::string name = "SS";

	//int price = 0;
	//item.price = price; // 
}

void SetItem(Item& item, const std::string Cname, int price)
{
	item.name = Cname;		// �ܺο��� ������ item�� Cname����  �������ش�. 
	item.price = price;
}

void SetItem(Item& SetItem, const Item& copyItem)	// ShopItem
{
	SetItem.name = copyItem.name;
	SetItem.price = copyItem.price;
}

// default �Ű� ���� ���� : �Լ� ȣ��� �Ű� ������ �����ϰ� �Է��ϸ� �ڵ����� ������ �����Ѵ�. 
// ShowShop(Shop, 3, 10, 10);
// ������ ��
// shop�� length�� default�� �ƴϱ� ������ �պκп� �ۼ��ؾ� �Ѵ�. 
void ShowShop(Item shop[], int length, int x = 10, int y = 10)	// �迭�� ����Ѵ�. 
{
	ConsoleUtil::GotoXY(x, y);
	// #include <iomanip> std::left, right (����, ������ ������ �����ϴ� ���̺귯��)
	// std::setw(20); ���ڿ��� ũ�Ⱑ 20�� ������ �����. ���ڿ��� ������� ���鹮�ڷ� ����Ѵ�. 
	std::cout << std::left << std::setw(20) << "������ �̸� " << "|"
		<< std::setw(10) << "������ ���� " << std::endl;
	for (int i = 0; i < length; i++)
	{
		ConsoleUtil::GotoXY(x, y+1+i);
		//std::cout << "�̸� : " << shop[i].name << ", ���� : " << shop[i].price << std::endl;
		std::cout << std::left << std::setw(20) << shop[i].name << "|" << 
		std::setw(10) << shop[i].price <<  "|" << std::endl;
	}
}

// Shop�迭, ������ �ε���, Item�迭(������ �κ��丮)
// copyItem
// ����(Item �迭)�� �ִ� �����͸� �����ؼ�, ������ ������ �迭�� �����´�. �迭�� �����͸� �����Ѵ�. 

Item& GetItem(Item shop[], int length, int index)
{
	if (index > length)
	{
		std::cout << "��ϵ��� ���� �������� �����Ͽ� 0��° �������� ��ȯ�˴ϴ�." << std::endl;
		return shop[0];
	}
	return shop[index];	// �����ȿ� �ִ� index�� ��ȯ�Ѵ�. 
}

void AddInventory(Item inventory[], int length, int index, const Item& buyItem)	// �� �������� ������ �Ǹ� �ȵǱ� ������ const�� ����Ѵ�. 
{
	inventory[index].name = buyItem.name;
	inventory[index].price = buyItem.price;
}

int main()
{
	std::cout << "������ ����" << std::endl;
	// ������ ����ü�� ����ؼ� �̸����� �����Ѵ�. 
	Item ItemA;
	Item ItemB;
	Item ItemC;

	SetItem(ItemA, "Ice Americano", 2000);
	SetItem(ItemB, "Banila Latte", 3000);
	SetItem(ItemC, "Cafe Latte", 2500);
	Item Shop[3] = { ItemA, ItemB, ItemC };

	ShowShop(Shop, 3, 0, 0);
	Item Inventory[3];
	std::cout << "�����ϰ���� ������ ��ȣ�� �Է��ϼ���." << std::endl;
	int input;
	std::cin >> input;

	AddInventory(Inventory, 3, 0, GetItem(Shop, 3, input - 1));

	/*
	* AddInventory �Լ� ���� ����
	* �������κ��� �κ��丮�� �������� �߰��ϴ� ��
	* ���� �����Ͱ� �������� �ִµ� ���� ��Ʋ �߿� ������ ���͸� �����Ѵ�. 
	* ���� �����͸� �ҷ����� ��
	* stage ������ �ְ� Ư�� ���������� ȣ���� ���� �ִ�. 
	*/

	std::cout << "�κ��丮 ������ Ȯ�� " << std::endl;
	std::cout << Inventory[0].name << "," << Inventory[0].price << std::endl;


	ShowShop(Shop, 3, 0, 0);
	//std::cout << "�̸� : " << ItemA.name << ", ���� : " << ItemA.price << std::endl;
	//std::cout << "�̸� : " << ItemB.name << ", ���� : " << ItemB.price << std::endl;
	_getch();

	// ���� 1. 10,10 ��ǥ�� �÷��̾��� ���� �ؽ�Ʈ�� ����غ���
	ConsoleUtil::GotoXY(10, 10);
	std::cout << "�÷��̾��� ����" << std::endl;

	// ���� 2. �÷��̾��� �̸��� �Է¹޾Ƽ� �÷��̾��� ���� �ؽ�Ʈ ���� �Ʒ��� ����غ��� 
	// �Է� ���� ������ �޾Ƽ�, 1�� ������ �÷��̾� �̸� �߰��ϱ�
	// 2�� ������ ȭ�鿡 �÷��̾� ������ ����ϱ�

	char name[20];
	char Job[20];

	while (true)
	{
		int inputNumber = 0;

		//ConsoleUtil::GotoXY(10, 1);
		std::cout << "1_ ������� �̸��� ������ �� �ֽ��ϴ�. 2_ �÷��̾��� ������ ȭ�鿡 ����մϴ�. 3_�����մϴ�." << std::endl;
		std::cin >> inputNumber;	// cpp������ �ּ� �����ڸ� ������� �ʰ� �ٷ� �� �� �ִ�? 
		if (inputNumber == 1)
		{
			std::cout << "�̸��� �Է����ּ���." << std::endl;
			std::cin >> name;
			/*std::cout << "������ �Է����ּ���." << std::endl;
			std::cin >> Job;*/
		}
		else if (inputNumber == 2)
		{
			ConsoleUtil::GotoXY(10, 10);
			std::cout << "�÷��̾��� ����";
			ConsoleUtil::GotoXY(10, 11);
			std::cout << "�÷��̾��� �̸� :" << name;
			/*ConsoleUtil::GotoXY(10, 12);
			std::cout << "�÷��̾��� ���� :" << Job;*/
			_getch();
		}
		/*else if (inputNumber == 3)
		{
			break;
		}*/
		else
		{
			break;
		}
		system("cls");
	}

	int x = 0, y = 0;

	while (true)
	{
		system("cls");
		ConsoleUtil::inputPlayerKey(x, y);
		std::cout << "�÷��̾��� ��ǥ : " << "{" << x << "," << y << "}" << std::endl;
		ConsoleUtil::GotoXY(x, y);
		std::cout << "��";
		Sleep(50);
	}



}