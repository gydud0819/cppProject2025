#include "Cookie.h"

void Cookie::ShowCookieInfo()
{
	cout << "ÄíÅ°ÀÇ ·¹º§: " << Lv << endl;
	cout << "ÄíÅ°ÀÇ ÀÌ¸§: " << name << endl;
	cout << "ÄíÅ°ÀÇ ¼Ó¼º: " << type << endl;
}

void Legendary_Cookie::ShowCookieInfo()
{
	ShowCookieInfo();
	
}
