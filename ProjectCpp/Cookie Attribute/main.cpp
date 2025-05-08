
#include "Cookie.h"
#include "CookieManager.h"

int main()
{
	CookieManager manager;
	int Choice;

	int elementInput = 0;

	while (true)
	{
		cout << "쿠키런 킹덤 쿠키 관리 프로그램" << endl;
		cout << "1. 쿠키 추가하기" << endl;
		cout << "2. 쿠키 정보 열람하기" << endl;
		cout << "3. 종료하기." << endl;
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			manager.AddCookies();	// 쿠키 정보 추가하기
		case 2:
			manager.ShowAllCookies();	// 모든 쿠키 정보 보기
		case 3:
			manager.ShowCookieByElement(static_cast<ElementType>(elementInput));
		case 0:
			cout << "프로그램을 종료 합니다.";
			break;
		default:
			cout << "잘못된 선택입니다. 다시 입력하세요." << endl;
			break;
		}

		cout << endl;
	}
	//manager.ShowCookieByElement(Fire);




}