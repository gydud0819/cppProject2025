#include "ShowCookie.h"

bool ShowCookie::LoadCookies(const string& filename)
{
    count = loader.LoadCookies("Cookie.txt", cookies);

    return count > 0;	// 아이템을 하나라도 가져오면 loaditem이 true, 아니면 false
 
}

void ShowCookie::ShowCookies()
{
    // 쿠키 정보 보여주기
	cout << "쿠키 정보 보여주기" << endl;
	cout << "+--------+-------------------------------+------------------+" << endl;
	cout << "| 속성   |            이름               |       등급       |" << endl;
	cout << "+--------+-------------------------------+------------------+" << endl;

	//for (int i = 0; i < count; i++)
	//{
	//	cout << cookies[i].GetName() << /*"\t" << cookies[i].GetName() << "\t" << cookies[i].GetName() 
	//		 <<*/ "\t" << cookies[i].GetRank() << "\t" << cookies[i].GetElementType() << endl;
	//}

	for (int i = 0; i < count; i++)
	{
		//cout<<"| %4d | %8s |  %8d            |" << i + 1, cookies[i].GetName() << cookies[i].GetRank() << 
		//	cookies[i].GetElementType() << endl;	// 등수, 점수, 이름 순
		//cout << "+------+----------+------------------+" << endl;


	/*	cout << "| " << i + 1 << " | "
			<< cookies[i].GetName() << " | "
			<< cookies[i].GetRank() << " | "
			<< cookies[i].GetElementType() << " |" << endl;*/

 // 헤더 추가 필요

			// 출력 부분
		cout << "| " << setw(8) << cookies[i].ReturnElementType() << " | "
			<< setw(25) << cookies[i].GetName() << " | "
			<< setw(10) << cookies[i].ReturnRank() << " |" << endl;
		cout << "+--------+-------------------------------+------------------+" << endl;

	}
}


//(i + 1)