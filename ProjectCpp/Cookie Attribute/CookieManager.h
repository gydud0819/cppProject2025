#pragma once
#include "Cookie.h"

class CookieManager
{
private:
	Cookie* windCookies[7];		// 바람 속성 쿠키 7개
	int windCount;				// 저장된 쿠키 수
public:
	CookieManager() : windCount(0) {}

	void AddCookie(Cookie* cookie);
	
	void ShowAllCookies();
	void ShowCookieByElement(ElementType type);
};

