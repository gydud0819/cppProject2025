#include "CookieManager.h"

void CookieManager::AddCookie(Cookie* cookie)
{
	if (windCount < 7)
	{
		windCookies[windCount++] = cookie;
	}
}

void CookieManager::ShowAllCookies()
{
	cout << "[바람 속성 쿠키 목록]" << endl;
	for (int i = 0; i < windCount; i++)
	{
		windCookies[i]->ShowCookieInfo();
	}
}

void CookieManager::ShowCookieByElement(ElementType type)
{
	cout << "[특정 속성(" << type << ") 쿠키 목록]" << endl;
	for (int i = 0; i < windCount; i++) 
	{
		if (windCookies[i]->type == type) {
			windCookies[i]->ShowCookieInfo();
		}
	}
}
