#include "Common.h"
#include "Cookie.h"
#include "CookieManager.h"

int main()
{
	Cookie WAC(90, "바람", Natual, LEGENDARY);
	WAC.ShowCookieInfo();
	WAC.UseSkill();

	/*Cookie* wptr = &WAC;
	wptr->ShowCookieInfo();*/

	//Wind_Archer_Cookie WAC(90, "바람궁수 쿠키", Natual, LEGENDARY);
	//GingerBrave GB(1, "용감한 쿠키", Independent, COMMON);

	//Cookie& cookie = WAC;	// Cookie를 참조하여 자식 클래스 객체를 가리키고 다형성을 구현했다.


	//cookie.ShowCookieInfo();
	//cookie.UseSkill();

	//cout << "=======================" << endl;
	//Cookie& cookie2 = GB;
	//cookie2.ShowCookieInfo();
	//cookie2.UseSkill();

	/*Cookie* Wptr = &WAC;
	Wptr->ShowCookieInfo();
	
	CookieManager cookieManager;
	cookieManager.CookieUpgrade(&WAC);*/
	
}