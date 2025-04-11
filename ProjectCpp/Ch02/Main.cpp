/*
* �ۼ���	: 2025-04-11
* �ۼ���	: ��ȿ��
* ����	: ������
*/

/*
* C�� C++ ������2 : ������ 
*/

#include <iostream>

/*
* ������ ���ظ� ���� Swap�Լ� �����ϱ�
*/

void SwapByValue(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;

	// �� �Լ��� ���ο��� ȣ������ �� num1, num2�� ������ ������ ����Ǵ°�? �ƴϿ�
}

void SwapByRef(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	// num1, num2�� ���޵� ������ ������ ����ȴ�.
}

// �Լ��� �����ε����� ���� �Լ��� �̸��� ���Ƶ� �Ű� ������ Ÿ���� �ٸ��� ������ �� �ִ�. (������ �����Ͽ� �߰��� �� �� ����)
void SwapByRef(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// ���� 1. SwapPointer �����. �ּҸ� �����ڷ� �����ϴ� �Լ� �����
// int type ����ϱ�

// ������ �����ڷ� ���� �� �ִ� �� �ƴ� �ּ�, �迭 ���ҵ� �����ڷ� ���� �� �ִ�. 
// int arr[3] = {1,2,3};
// int& arrRef1 = arr[0];

// int num1 = 10;
// int* num1ptr = &num1;
// int* (&num1Ref) =  num1ptr; num1Ref�� num1ptr�� �����̴�. 

void SwapPointer(int* &num1ptr, int* &num2ptr)
{
	int* temp = num1ptr;
	num1ptr = num2ptr;
	num2ptr = temp;
}

int main()
{
	// namespace st�� ���ǵǾ��ִ� �����ȿ� cout�� �����ͼ� ����ϰڴ�.
	std::cout << "2��_ ������\n" << std::endl;

	// ������ ����� ����� ���еȴ�. (�����ؼ� ����Ѵ�.)
	// �Լ��� ����� ����� ���еȴ�.
	 
	// ������ ����
	int num1 = 1;

	int* numptr1 = &num1;	// num1ptr ������ ������ num1�� �ּҸ� �����Ѵ�. 

	int& num1ref = num1;	// num1�̶�� ������ �����ϴ� num1ref. (num1ref�� num1�� �����ڴ�.) num1 ������ �߰����ְڴ�. num1ref

	num1ref += 1;

	//int num2 = num1;		// num2�� ���� 1�̴�.	
	//num1++;					// num1�� ���� 2�̴�.
	std::cout << "num1�� �� : " << num1 << std::endl;
	std::cout << "num1�� ���� num1ref �����ڷ� ȣ���Ѵ�: " << num1ref << std::endl;

	// �����ڴ� �����̴�. 
	// A, �� (A�� ����)
	// A�� ~ �ض�		// �Ѵ� ���� �ǹ�
	// ���� ~ �ض�		// �Ѵ� ���� �ǹ�

	// �����ڸ� ��� ����ұ�?

	int input = 0;
	// scanf("%d"), &input
	// ������ Ȱ���� ���� : C++ ������ ����ؼ� �Լ��� ����� �� *, & �� ������� �ʰ� ǥ���� �� �ִ�.
	//std::cin >> input;

	// SwapByValue, SwapByRef ����
	std::cout << "Call By Value �� Call By Reference ����\n" << std::endl;
	int value1 = 10, value2 = 20;

	std::cout << "Call By Value ���\n" << std::endl;
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	SwapByValue(value1, value2);
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	
	std::cout << "Call By Reference ���\n" << std::endl;
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	SwapByRef(&value1, &value2);
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;

	std::cout << "Call By Value ���\n" << std::endl;
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;
	SwapByRef(value1, value2);
	std::cout << "value1 : " << value1 << "value2 : " << value2 << std::endl;

	// 
	std::cout << "�������� ����\n" << std::endl;

	int Num1 = 1;
	int Num2 = 100;

	int* Num1ptr = &Num1;
	int* Num2ptr = &Num2;

	std::cout << "Num1ptr�κ��� �� ��� : " << *Num1ptr << std::endl;
	std::cout << "Num2ptr�κ��� �� ��� : " << *Num2ptr << std::endl;

	SwapPointer(Num1ptr, Num2ptr);

	std::cout << "Num1ptr�κ��� �� ��� : " << *Num1ptr << std::endl; 
	std::cout << "Num2ptr�κ��� �� ��� : " << *Num2ptr << std::endl;

	// �����ڸ� ����ϸ� �����Ϳ� ���� ��ȣ�� 1�� �ٿ��� ǥ���� �� �ִ�.
	// int, int ������ �ٲ� ���� �����ڸ� ����Ѵ�.
	// int*, int* ���� �ٲܶ��� int*& int*&�� ����Ѵ�. 

	// ������ ���� ������ ��
	// int& ref;	// ����1. �����ڴ� ������ �� �ݵ�� �ʱ�ȭ�� �ʿ��ϴ�. == �̴ϼȶ������� �ʿ��ϴ�.
	int ref = 10;
	int& refRef = ref;	// ����1. �ذ� ��� 

	// const�� Ȱ���Ͽ� �Լ��� ����ϴ� ������� ���̵带 �ȳ����� �� 
	// void Func(const int* num1); num1�� �����ϴ� ���� �������� ����.
	// void Func(const int& num1); num1 ���� ���� �������� ����.

	// return Ÿ�Կ� �����ڸ� ������ �� �����ؾ� �Ѵ�. 

	// main�Լ������� ����		|		�Լ��� �� ����(int func())		|		�Լ����� ������ ����(int& func())
	// int a = func();			|		a�� ���� ����ȴ�.				|		a�� ���� ����ȴ�. func�ȿ��� ���� ������ return���� ���ƾ� �Ѵ�. 
	// -------------------------|---------------------------------------|---------------------------------------------------------------
	// int& a = func();			|		a�� func���� ���� �������� �Ѵ�.	|		func�ȿ��� ���� ������ return���� �ʾƾ� �Ѵ�.
	//							|		a���� 10�� �������� �Ѵ�.		|
	//							|		a = 9; 10�� 9�� �ض�.			|
	//							|		������ ������ �߻�.				|
	// -------------------------|---------------------------------------|---------------------------------------------------------------
	// const int& a = func();	|		a������ 10�� �������� �ض�.		|		func�ȿ��� ���� ������ return���� �ʾƾ� �Ѵ�.
	//							|		10�� ������ a��� �Ѵ�.			|
	//							|		const int& a = 10;				|
}