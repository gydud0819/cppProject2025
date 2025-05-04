#include "Common.h"
#include "Cookie.h"
#include "CookieManager.h"

int main()
{
	//Wind_Cookie WAC(90, "바람궁수 쿠키", Wind, LEGENDARY);
	//Wind_Cookie WAC2(90, "페스츄리맛 쿠키", Wind, EPIC);
	//Wind_Cookie WAC3(90, "민트초코맛 쿠키", Wind, EPIC);
	//Wind_Cookie WAC4(90, "의적맛 쿠키", Wind, EPIC);
	//Wind_Cookie WAC5(90, "구미호맛 쿠키", Wind, EPIC);
	//Wind_Cookie WAC6(90, "그린티무스맛 쿠키", Wind, EPIC);
	//Wind_Cookie WAC7(90, "우무맛 쿠키", Wind, EPIC);
	////GingerBrave GB(1, "용감한 쿠키", Independent, COMMON);

	//WAC.ShowCookieInfo();
	//WAC2.ShowCookieInfo();
	//WAC3.ShowCookieInfo();
	//WAC4.ShowCookieInfo();
	//WAC5.ShowCookieInfo();
	//WAC6.ShowCookieInfo();
	//WAC7.ShowCookieInfo();

	CookieManager manager;
	//cout << "모든 쿠키 정보" << endl;
	////manager.ShowAllCookies();
	//manager.ShowCookieByElement(Wind);

	manager.ShowCookieByElement(Wind);
}