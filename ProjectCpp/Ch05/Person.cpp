#include "Person.h"

/*
* ���� ���� : �������� ���� �״�� �ٸ� ������ �������� ��. ũ�Ⱑ ���� �� ����Ѵ�. 
* ���� ���� : �ּҸ� ���� �Ҵ��ؼ� ���� �����Ͽ� �����ϴ� ��. �� �޸� ������ �Ҵ�ȴ�. 
*/

string Person::ReturnGendertypeName() const	// char* name�� ���̽Ἥ �ڵ尡 �ణ ���ΰ� ���� const �Ƚᵵ �Ǵµ� ���⼱ �ε����ϰ� �����.
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
	//name = new char[strlen(other.name) + 1];	// ���ο� �޸� ������ �����Ѵ�. (���� ����)
	//strcpy(name, other.name);
	gender = other.gender;
}

void Person::Show() const
{
	cout << "����: " << age << endl;
	cout << "�̸�: " << sName << endl;
	cout << "����: " << ReturnGendertypeName() << endl;
}
