#pragma once
#include "Cookie.h"

// 쿠키를 활용하여 쿠키정보프로그램 만들기 
class CookieManager
{
private:
	int windCookieIndex;
	int fireCookieIndex;
private:
	static const int Cookie_Count = 20;		// static: 클래스의 모든 객체에서 동일 값을 공유한다, const : 값이 초기화 된 후에도 변하지 않도록 사용했다.
	Wind_Cookie* windcookies[Cookie_Count];		// 바람 속성 쿠키 7개	
	Fire_Cookie* firecookies[Cookie_Count];// 저장된 쿠키 수			
public:
	
	CookieManager();
	
	void ShowAllCookies();
	void ShowCookieByElement(ElementType type);
	void ShowCookieByRank(Rank rank);
	void AddCookies(/*string name, int elementInput, int rankInput*/);
	
};

