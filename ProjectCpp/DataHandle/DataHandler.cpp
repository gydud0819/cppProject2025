#include "DataHandler.h"



int DataHandler::LoadItems(const string& filename, Item items[])
{
	ifstream file(filename);    // 파일 이름으로 파일을 가져온다. (프로젝트 파일에 있는 data.txt를 불러올 수 있음)

	if (!file.is_open())  // 파일이 열리지 않았다면
	{
		cerr << "파일을 열 수 없습니다" << filename << endl;
		return 0;
	}

	int itemCount = 0;
	string line;	// 메모장에 있는 내용을 한줄 씩 가져온다. 

	// item의 항목을 읽어와야한다.
	while (getline(file, line) && itemCount < MAX_ITEMS)
	{
		istringstream iss(line);
		int index;
		string name;
		int price;
		int typeCount;
		int amount;

		// 데이터를 파싱한다? == 데이터 타입을 바꿔준다?
		if (iss >> index >> name >> price >> typeCount >> amount)
		{
			ItemDataType newType(typeCount, amount);
			items[itemCount++] = Item(index, name, price, newType);	// 생성자로 만든 데이터를 대입한 다음 1을 증가시켜준다는 의미이다. 
		}
		else
		{
			cerr << "유효하지 않은 데이터가 존재합니다" << line << endl;		// 이거 왜뜸???????????
		}
	}

	file.close();	// close까지 해줘야 한다. 

	return itemCount;
}
