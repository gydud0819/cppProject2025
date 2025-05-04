#include "CookieManager.h"

CookieManager::CookieManager()
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		cookies[0] = Wind_Cookie(90, "바람궁수 쿠키", Wind, LEGENDARY);
		cookies[1] = Wind_Cookie(90, "페스츄리맛 쿠키", Wind, EPIC);
		cookies[2] = Wind_Cookie(90, "민트초코맛 쿠키", Wind, EPIC);
		cookies[3] = Wind_Cookie(90, "의적맛 쿠키", Wind, EPIC);
		cookies[4] = Wind_Cookie(90, "구미호맛 쿠키", Wind, EPIC);
		cookies[5] = Wind_Cookie(90, "그린티무스맛 쿠키", Wind, EPIC);
		cookies[6] = Wind_Cookie(90, "우무맛 쿠키", Wind, EPIC);
	}
}

void CookieManager::ShowAllCookies()
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		cookies[i].ShowCookieInfo();
	}
}

void CookieManager::ShowCookieByElement(ElementType type)
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		if (cookies[i].GetElementType() == type)
		{
			cookies[i].ShowCookieInfo();
		}
	}
}

int CookieManager::LoadCookie(const string& filename, Cookie cookies[])
{
	ifstream file(filename);
	if (!file.is_open())  // 파일이 열리지 않았다면
	{
		cerr << "파일을 열 수 없습니다" << filename << endl;
		return 0;
	}

	int id = 0;
	string line;

	// item의 항목을 읽어와야한다.
	while (getline(file, line) && id < MAX_COOKIE)
	{
		istringstream iss(line);
		string name1, name2, name3, /*typestr,*/ rankstr;

		// 데이터를 파싱한다 == 데이터를 각 변수에 맞게 저장되도록 변환하는 것
		if (iss >> name1 >> name2 >> name3 >> /*typestr >>*/ rankstr)
		{
			string name = name1 + " " + name2 + " " + name3;
			int Lv = 90;	// 생성자로 만든 데이터를 대입한 다음 1을 증가시켜준다는 의미이다. 
			ElementType type = Wind;
			Rank rank = EPIC;

			cookies[id++] = Cookie(Lv, name, Wind, rank);

			/*if (typestr == "Wind")
				type = Wind;
			else if (typestr == "Fire")
				type = Fire;
			else if (typestr == "Water")
				type = Water;
			else if (typestr == "Dark")
				type = Dark;
			else if (typestr == "Ice")
				type = Ice;
			else if (typestr == "Light")
				type = Light;
			else if (typestr == "Ground")
				type = Ground;
			else if (typestr == "Independent")
				type = Independent;*/

			if (rankstr == "LEGENDARY")
				rank = LEGENDARY;
			else if (rankstr == "SUPER_EPIC")
				rank = SUPER_EPIC;
			else if (rankstr == "EPIC")
				rank = EPIC;
			else if (rankstr == "RARE")
				rank = RARE;
			else if (rankstr == "COMMON")
				rank = COMMON;

		}
		else
		{
			cerr << "유효하지 않은 데이터가 존재합니다" << line << endl;		// 이거 왜뜸???????????
		}
	}

	file.close();	// close까지 해줘야 한다. 

	return id;
}

void CookieManager::LoadCookieInfo(const string& filename)
{
	Cookie cookies[10];
	//LoadCookieInfo("WindCookie.txt");

	int count = LoadCookie(filename, cookies);
	for (int i = 0; i < count; i++)
	{
		cookies[i].ShowCookieInfo();
	}
}


