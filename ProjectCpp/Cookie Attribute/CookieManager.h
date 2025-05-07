#pragma once
#include "Cookie.h"

// 쿠키를 활용하여 쿠키정보프로그램 만들기 
class CookieManager
{
private:
	static const int Cookie_Count = 10;
	Wind_Cookie cookies[Cookie_Count];		// 바람 속성 쿠키 7개			// 저장된 쿠키 수			
public:
	
	CookieManager();
	
	void ShowAllCookies();
	void ShowCookieByElement(ElementType type);
	int LoadCookie(const string& filename, Cookie cookies[]);	// 메모장으로부터 쿠키 정보를 읽어오는 함수
	void LoadCookieInfo(const string& filename);
};

