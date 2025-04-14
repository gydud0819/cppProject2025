/*
* �ۼ���	: 2025-04-14
* �ۼ���	: ��ȿ��
* ����	: ����ü�� ������
*/

#include <iostream>

/*
* 2���� ���� ����
* x,y�� ������ �·Ḧ �Լ��� �Ű������� �޾Ƽ� �ܺο��� ���� ����ǵ��� �ϴ�
* �Լ� playerInputkey(int& x, int& y);
* ��ȯ�� ���� �Լ�. 
* �̸��� PlayerInput(int& a, int& b) �Լ��� ȣ���� �� �ִ�.
* Ÿ�� �ؼ� : ������ ������, ������ �����͸� ������ �� �ִ�. 
*/

/*
* ��ȯŸ�� �Լ��̸�(Ÿ�� �̸�, ...);{ ����κ� �ۼ� }
* 
* 1. ��ȯŸ�� - �����ڷ� ���Ǵ� ���, �ƴ� ���
* 2. �Ű����� - �����ڷ� ���Ǵ� ���, �ƴ� ��� 
*/

/*
* �Լ� �����ε�(OverLoading)
* �÷��̾��� x,y ��ǥ�� �Է¹޾� ��ǥ�� �����Ű�� �Լ�
* �÷��̾��� ��ǥ ����ü�� �Է¹޾� ��ǥ�� �����Ű�� �Լ�
* ���� �̸��� Ÿ�Ը� �ٸ��� ������ �����Ϸ��� ������ �� �ִ�. 
*/

// C++���� typedef ������ ��� struct �̸����� Ÿ�԰� ����ü�� ���ÿ� ����� �� �ִ�.
struct Pos
{
	int PosX;
	int PosY;
};

/*
* �Լ� �����ε� ����
* C++ �Լ��� ȣ���ϴ� ����� �˷��ش�. �̸�(Ÿ�� �̸� ),
* �Լ� �����ε��� �Լ��� �̸��� �Լ��� �Ű� ������ Ÿ�԰� ������ �����Ѵ�. ��
* �Ű��������� �����ڸ� ����ϸ� �� �� ���ϰ� ����� �� �ִ�. 
* 
* ������ ��
* - ��ȯ���� �޶� ���� �Լ��� �Ǵ��Ѵ�. (void PlayerInput (), int PlayerInput() �� �����ε� �� �� ����.)
* - �Ű������� �̸��� �޶� Ÿ���� ������ ������ �����ε� �� �� ����. 
* void PlayerInput(int x, int y);
* void PlayerInput(int a, int b);
* 
* (�׷� �̸� �ٸ��� Ÿ���� ������ �ٸ��� �����ε� �� ���� �� �ճ�?)
* void PlayerInput(int x, int y);
* void PlayerInput(int a, int b, int c;);
* 
*/

/*
* �����ڸ� ��ȯ���� ����ϴ� ���
*/

int& ReturnRef()		// int& num1 = ReturnRef();	
					// num ������ 20�� �ְ� 5�� �����ش�. num�� ������ num1�� �ϰڴ�. 
					// num ���� ���� �Լ��� ����Ǹ� �Ҹ��Ѵ�. 
					// ��۸� ���۷���. 
{
	int num = 20;
	num += 5;
	return num;
}

// ����ü �迭
// ������, ����, �κ��丮
// ���ؿ�� : ������
// ������ 3���� : ū ������, ���� ������, �߰� ������
// �����ڸ�  �� ���信 �����غ���. 

void PlayerInput()	// �̸� PlayerInput, �Ű� ���� 0��
{
	std::cout << "PlayerInput �Լ� ����" << std::endl;
}

void PlayerInput(Pos& playerPos)	// �̸� PlayerInput, �Ű� ���� 1�� Pos& 
{
	playerPos.PosX += 1;
	playerPos.PosY += 1;
}

void PlayerInput(int& a, int& b) // �̸� PlayerInput, �Ű� ���� 2��
{
	a += 1;
	b += 1;
}

int main()
{
	std::cout << "ch03" << std::endl;

	int playerX = 0;
	int playerY = 0;

	PlayerInput(playerX, playerY);
	std::cout << "playerInput ��� ���" << std::endl;
	std::cout << "x�� �� : " << playerX << "," << "y�� �� : " << playerY << std::endl;

	Pos playerPos = { playerX, playerY };
	PlayerInput(playerPos);
	std::cout << "playerInput ��� ���" << std::endl;
	std::cout << "x�� �� : " << playerPos.PosX << "," << "y�� �� : " << playerPos.PosY << std::endl;

	PlayerInput();
}