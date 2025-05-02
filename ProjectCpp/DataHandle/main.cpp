/*
* 작성일	: 2025-05-02
* 작성자	: 박효영
* 주제	: 메모장에 있는 게임 데이터를 코드로 읽는 방법 구현
*/

#include "GameManager.h"

int main()
{
	Shop shop;
	shop.ShowItems();

	Player player;
	
	player.UpGrade(shop.GetITems(3));
	//DataHandler loader;
	//Item items[MAX_ITEMS];	

	//int count = loader.LoadItems("data.txt", items);

	//// items 정보를 보여주기
	//cout << "판매중인 아이템" << endl;
	//for (int i = 0; i < count; i++)
	//{
	//	cout << items[i].index << "\t" << items[i].name << "\t" << items[i].price << "gold" << endl;
	//}
}