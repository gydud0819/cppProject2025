/*
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
* 2025-04-11
* �÷��̾��� �̵��� �����ڸ� �̿��Ͽ� �Լ�ȭ �غ���
*/

#include <iostream>
#include <Windows.h>	// Ŀ���� ��ġ�� �ű�� �Լ� 
#include <conio.h>

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

int main()
{
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
		std::cout << "�÷��̾��� ��ǥ : " << "{" <<  x << "," << y << "}" << std::endl;
		ConsoleUtil::GotoXY(x, y);
		std::cout << "��";
		Sleep(50);
	}



}





