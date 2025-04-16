#include "Person.h"

/*
* ���� ���� : �������� ���� �״�� �ٸ� ������ �������� ��. ũ�Ⱑ ���� �� ����Ѵ�. 
* ���� ���� : �ּҸ� ���� �Ҵ��ؼ� ���� �����Ͽ� �����ϴ� ��. �� �޸� ������ �Ҵ�ȴ�. 
*/

string Person::ReturnGendertypeName()
{
	switch (gender)
	{
	case Male:
		return "Male";
		
	case FeMale:
		return "FeMale";
	default:
		break;
	}
}

void Person::Clone(const Person& other)
{
	// ���� ������ �Ѵ�. -> ���� ����� ��������� �Ѵ�. 
	age = other.age;
	//name = other.name;
	name = new char[strlen(other.name) + 1];	// ���ο� �޸� ������ �����Ѵ�. (���� ����)
	strcpy(name, other.name);
}

void Person::Show() const
{
	cout << "����: " << age << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << gender << endl;
}
