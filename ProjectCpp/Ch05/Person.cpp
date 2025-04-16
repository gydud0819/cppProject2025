#include "Person.h"

/*
* 얕은 복사 : 데이터의 값을 그대로 다른 변수에 가져오는 것. 크기가 작을 때 사용한다. 
* 깊은 복사 : 주소를 새로 할당해서 값을 복사하여 저장하는 것. 새 메모리 공간이 할당된다. 
*/

string Person::ReturnGendertypeName() const	// char* name도 같이써서 코드가 약간 꼬인거 같음 const 안써도 되는데 여기선 부득이하게 사용함.
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
	// 얕은 복사라고 한다. -> 깊은 복사로 변경해줘야 한다. 
	age = other.age;
	//name = other.name;
	//name = new char[strlen(other.name) + 1];	// 새로운 메모리 공간을 생성한다. (깊은 복사)
	//strcpy(name, other.name);
	gender = other.gender;
}

void Person::Show() const
{
	cout << "나이: " << age << endl;
	cout << "이름: " << sName << endl;
	cout << "성별: " << ReturnGendertypeName() << endl;
}
