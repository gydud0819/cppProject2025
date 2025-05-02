#include "Shop.h"

bool Shop::LoadItems(const string& filename)
{
    count = loader.LoadItems("data.txt", items);

    return count > 0;	// 아이템을 하나라도 가져오면 loaditem이 true, 아니면 false
}

void Shop::ShowItems()
{
	// items 정보를 보여주기
	cout << "판매중인 아이템" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << items[i].index << "\t" << items[i].name << "\t" << items[i].price << "gold" << 
			"\t타입: " << items[i].dataType.type << "\t수치: " << items[i].dataType.amount << endl;
	}
}
