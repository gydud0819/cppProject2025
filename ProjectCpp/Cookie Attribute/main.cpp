#include "Common.h"
#include "Cookie.h"
#include "CookieManager.h"

int main()
{
	Cookie cookie(90, "바람궁수 쿠키", Natual, LEGENDARY);
	cookie.UseSkill();
	//Wind_Archer_Cookie WAC(90, "바람궁수 쿠키", Natual, LEGENDARY);
	//GingerBrave GB(1, "용감한 쿠키", Independent, COMMON);

	//Cookie& cookie = WAC;	// Cookie를 참조하여 자식 클래스 객체를 가리키고 다형성을 구현했다.
	//Cookie& cookie2 = GB;

	//CookieManager cookieManager;
	//cookie.ShowCookieInfo();
	//cookieManager.CookieUpgrade(&WAC);

	//cout << "=======================" << endl;

	//cookie2.ShowCookieInfo();
	//cookieManager.CookieUpgrade(&GB);
}