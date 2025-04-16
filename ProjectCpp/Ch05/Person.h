#pragma once
#include "CUtil.h"

/*
* C�� C++�� ������
* 
* C
* �޸� ���� �Ҵ� malloc(memory allocate) : malloc(ũ�� sizeof(char)* 10)
* free(���� �̸�);
* 
* C++
* new		: cpp���� �����Ҵ��ϴ� Ű���� 
* delete	: �޸𸮸� �����ϴ� Ű����
* 
*/

/*
* ������	: ��ü�� �����͸� ������ �� �ʱ�ȭ�� ���ִ� ��� 
* �Ҹ���	: ��ü�� �Ҹ��� �� �ڵ����� ȣ��Ǵ� ��� 
*/

/*
* �̴ϼȶ�����
* age, name : age = 20; name = "���谡"
* age = �ܺο��� ������ ���ڸ� ������� �ǹ� age(age)
* �ּ� = �ּ�; <=�� ����� �� �߻��ϴ� ������ 
*/

enum GENDER
{
	Male,
	FeMale,
};

struct Person
{
	int age;
	char* name;			// ���̰� ������ �𸥴�. �޸𸮰� �����Ǿ� ���� �ʴ�. 
	string sName;
	GENDER gender;

	// ����Ʈ ������
	Person() {}		

	// ���� ������ ���ڿ� �ʱ�ȭ ����� �����ڷ� ǥ���Ѵ�.			42������ �����ϴ� �ڵ庸�� 39�� �ڵ�� ���� ���� �� ����. 
	Person(int age, const string& sName, GENDER gender) : age(age), sName(sName), gender(gender) {}

	//Person(int age)		// age(age)�� �߰�ȣ �ȿ� �� �� �ֱ��ϴ�. 
	//{
	//	this->age = age;	// 39��° �ڵ�� ���� �ǹ������� ó���ӵ��� 39��° �ڵ尡 �� ������ ���⿡ �����ϴ�. 
	//}
	
	// ������ �����ε� 
	Person(int age, const char* str) : age(age)
	{
		// �޸� ������ ���� ��������� �Ѵ�.
		name = new char[strlen(str) + 1];		                                                                                                                          // this? strlen?                 string name ���� ���� �� �Ƚᵵ �Ǵ°ǰ� 
		// ���� ������ ������ �ܺο� �ִ� �����͸� �����ؼ� �Űܿ;� �Ѵ�. 
		strcpy(name, str);
	}

	string ReturnGendertypeName();

	// �Ҹ��� : ��ü�� �Ҹ�� �� �ڵ����� ȣ��ȴ�. 
	~Person()
	{
		cout << "Person�� �Ҹ��ڰ� ȣ�� �Ǿ����ϴ�." << endl;
		delete[] name;
	}



	void Clone(const Person& other);	// 51�� �ڵ��� const�� �ۿ��� ������ ���� �������� �ʰڴٶ�� �ǹ�
	

	void Show() const;	// �Լ��� const�� ���̴� �� ��ü �� �����͸� ������� ����ϰڴٶ�� ���� ����ڿ��� �˷��ִ� �ǹ�.
};
 