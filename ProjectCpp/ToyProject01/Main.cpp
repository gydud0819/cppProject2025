/*
* 날짜	: 2025-04-10 1일차 
* 목표	: cpp 게임 화면 구성하기
* 복습	: Windows.h, GotoXY 재구현하기
* 입출력	: cpp 방식으로 입출력하기
* 이론	: namespace 응용하기
*/

/*
* 이름 공간을 사용할 때의 장점
* 1. 다른 2개의 프로젝트를 copy paste 합칠 때 발생하는 문제를 최소화 할 수 있다.
* 2. 이름 공간에 쓰여진 이름을 통해서 코드를 분류할 수 있다.
*/

/*
* 2025-04-11 2일차
* 플레이어의 이동을 참조자를 이용하여 함수화 해보기
*/

/*
* 2025-04-14 3일차 
* 구조체와 참조자를 활용하여 아이템 함수 만들기
*/

#include <iostream>
#include <Windows.h>	// 커서의 위치를 옮기는 함수 
#include <conio.h>		// 입력 대기 함수, _getch() 사용가능
#include <string>		// 문자열의 기능을 포함하고 있는 라이브러리
#include <iomanip>		// input output manipulate 

using namespace std;	// 내일 수업할 예정 

typedef struct NAME
{
	char* name[20];
}name;

namespace ConsoleUtil	// 콘솔기능 모음집
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
	//char name[20];	// std::string => 이름의 크기를 자동으로 할당해준다. 
	std::string name;	// 클래스를 통해 알 수 있다. (나중에 배울 예정)
	int price;
};

// Item 구조체의 참조자를 받아와서 이름과 가격을 원하는 이름과 가격으로 설정하는 함수 만들기

// const, 참조자, 아이템 구조체 사용하기 

// SetItem(item1, "Sword", 100)
void MySetItem(Item& item)
{
	std::string name = "SS";

	//int price = 0;
	//item.price = price; // 
}

void SetItem(Item& item, const std::string Cname, int price)
{
	item.name = Cname;		// 외부에서 가져온 item을 Cname으로  설정해준다. 
	item.price = price;
}

void SetItem(Item& SetItem, const Item& copyItem)	// ShopItem
{
	SetItem.name = copyItem.name;
	SetItem.price = copyItem.price;
}

// default 매개 인자 문법 : 함수 호출시 매개 변수를 부족하게 입력하면 자동으로 변수에 대입한다. 
// ShowShop(Shop, 3, 10, 10);
// 주의할 점
// shop과 length는 default가 아니기 때문에 앞부분에 작성해야 한다. 
void ShowShop(Item shop[], int length, int x = 10, int y = 10)	// 배열로 사용한다. 
{
	ConsoleUtil::GotoXY(x, y);
	// #include <iomanip> std::left, right (왼쪽, 오른쪽 정렬을 포함하는 라이브러리)
	// std::setw(20); 문자열의 크기가 20인 공간을 만든다. 문자열의 빈공간은 공백문자로 출력한다. 
	std::cout << std::left << std::setw(20) << "아이템 이름 " << "|"
		<< std::setw(10) << "아이템 가격 " << std::endl;
	for (int i = 0; i < length; i++)
	{
		ConsoleUtil::GotoXY(x, y+1+i);
		//std::cout << "이름 : " << shop[i].name << ", 가격 : " << shop[i].price << std::endl;
		std::cout << std::left << std::setw(20) << shop[i].name << "|" << 
		std::setw(10) << shop[i].price <<  "|" << std::endl;
	}
}

// Shop배열, 선택할 인덱스, Item배열(유저의 인벤토리)
// copyItem
// 상점(Item 배열)에 있는 데이터를 복사해서, 유저의 아이템 배열에 가져온다. 배열의 데이터를 변경한다. 

Item& GetItem(Item shop[], int length, int index)
{
	if (index > length)
	{
		std::cout << "등록되지 않은 아이템을 선택하여 0번째 아이템이 반환됩니다." << std::endl;
		return shop[0];
	}
	return shop[index];	// 상점안에 있는 index를 반환한다. 
}

void AddInventory(Item inventory[], int length, int index, const Item& buyItem)	// 산 아이템은 변경이 되면 안되기 때문에 const를 사용한다. 
{
	inventory[index].name = buyItem.name;
	inventory[index].price = buyItem.price;
}

int main()
{
	std::cout << "아이템 예제" << std::endl;
	// 아이템 구조체를 사용해서 이름들을 정의한다. 
	Item ItemA;
	Item ItemB;
	Item ItemC;

	SetItem(ItemA, "Ice Americano", 2000);
	SetItem(ItemB, "Banila Latte", 3000);
	SetItem(ItemC, "Cafe Latte", 2500);
	Item Shop[3] = { ItemA, ItemB, ItemC };

	ShowShop(Shop, 3, 0, 0);
	Item Inventory[3];
	std::cout << "구매하고싶은 아이템 번호를 입력하세요." << std::endl;
	int input;
	std::cin >> input;

	AddInventory(Inventory, 3, 0, GetItem(Shop, 3, input - 1));

	/*
	* AddInventory 함수 내용 정리
	* 상점으로부터 인벤토리에 아이템을 추가하는 것
	* 몬스터 데이터가 여러개가 있는데 현재 배틀 중에 등장할 몬스터를 선택한다. 
	* 몬스터 데이터를 불러오는 것
	* stage 정보가 있고 특정 스테이지를 호출할 수도 있다. 
	*/

	std::cout << "인벤토리 아이템 확인 " << std::endl;
	std::cout << Inventory[0].name << "," << Inventory[0].price << std::endl;


	ShowShop(Shop, 3, 0, 0);
	//std::cout << "이름 : " << ItemA.name << ", 가격 : " << ItemA.price << std::endl;
	//std::cout << "이름 : " << ItemB.name << ", 가격 : " << ItemB.price << std::endl;
	_getch();

	// 예제 1. 10,10 좌표에 플레이어의 정보 텍스트를 출력해보기
	ConsoleUtil::GotoXY(10, 10);
	std::cout << "플레이어의 정보" << std::endl;

	// 예제 2. 플레이어의 이름을 입력받아서 플레이어의 정보 텍스트 한줄 아래에 출력해보기 
	// 입력 값을 정수로 받아서, 1을 받으면 플레이어 이름 추가하기
	// 2를 받으면 화면에 플레이어 정보를 출력하기

	char name[20];
	char Job[20];

	while (true)
	{
		int inputNumber = 0;

		//ConsoleUtil::GotoXY(10, 1);
		std::cout << "1_ 사용자의 이름을 변경할 수 있습니다. 2_ 플레이어의 정보를 화면에 출력합니다. 3_종료합니다." << std::endl;
		std::cin >> inputNumber;	// cpp에서는 주소 연산자를 사용하지 않고 바로 쓸 수 있다? 
		if (inputNumber == 1)
		{
			std::cout << "이름을 입력해주세요." << std::endl;
			std::cin >> name;
			/*std::cout << "직업을 입력해주세요." << std::endl;
			std::cin >> Job;*/
		}
		else if (inputNumber == 2)
		{
			ConsoleUtil::GotoXY(10, 10);
			std::cout << "플레이어의 정보";
			ConsoleUtil::GotoXY(10, 11);
			std::cout << "플레이어의 이름 :" << name;
			/*ConsoleUtil::GotoXY(10, 12);
			std::cout << "플레이어의 직업 :" << Job;*/
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
		std::cout << "플레이어의 좌표 : " << "{" << x << "," << y << "}" << std::endl;
		ConsoleUtil::GotoXY(x, y);
		std::cout << "■";
		Sleep(50);
	}



}