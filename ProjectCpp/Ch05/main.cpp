/*
* �ۼ���	: 2025-04-16
* �ۼ���	: ��ȿ��
* ����	: ������ ����(���� ����� ���� ���翡 ���� ����)
*/

#include "CUtil.h"
#include "Person.h"

/*
* ���� ����
* person.h���� ���� �߰��ϱ�
* enum GENDER
* {
*	Male
*	FeMale
* }
*/

void example()	// ������ ���翡 ���� ���� 
{
	std::cout << "ch05: ������ ����" << std::endl;

	// ������ �����ϴ� ������ Ÿ��(int) ������ 2�� �����ϱ�.
	int numA = 10;
	// numB, numA�� ����Ǿ� �ִ� ���� B�� �ű�� �ʹ�.
	int numB = numA;

	int* numAptr = &numA;
	int* numBptr = numAptr;

	// numBptr�� �� �ּҿ� numAptr�� �� �ּ�, numA�� �ּҰ� ��� ������? ��� ����. 

	cout << "numA�� �ּ�" << &numA << endl;
	cout << "numAptr�� �ּ�" << numAptr << endl;
	cout << "numBptr�� �ּ�" << numBptr << endl;

	// �������� ���Կ����ڸ� ����� ���
	// numA�� numB�� ���� �ٸ� ������ �����Ѵ�. 
	// �ּҳ��� ���Կ����ڸ� ����� ���
	// numAptr�� numBptr�� �ּҰ� ����Ű�� ���� ����. 

	// numA, numAptr, numBptr �ּ��� ���� ��� �����ϴ�.
	// �ش� �ּҸ� �ϳ��� �������� �����ϸ� �ٸ� �������� ������ �� �� ���Եȴ�. 
}

int main()
{
	//example();

	//Person human1 = {20};	// human1�̶�� ������ �����и� �����ؼ� �־���� �Ѵ�. 
	Person human1(20, "����", Male);
	Person human1Clone;
	Person human2(30, "ĥ��", FeMale);
	human1Clone.Clone(human1);
	human1.Show();
	human1Clone.Show();
	human2.Show();
}