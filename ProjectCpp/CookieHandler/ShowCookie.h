#pragma once
#include "CookieHandler.h"

class ShowCookie
{
private:
	CookieHandler loader;
	Cookie cookies[MAX_COOKIES];
	int count;

public:
	ShowCookie() : count(0)
	{
		LoadCookies("Cookie.txt");
	}

	bool LoadCookies(const string& filename);

	void ShowCookies();

	Cookie& readCookie(int index)
	{
		return cookies[index];
	}

	
};

//class Shop
//{
//private:
//	DataHandler loader;
//	Item items[MAX_ITEMS];
//	int count;
//public:
//	Shop() : count(0)
//	{
//		LoadItems("data.txt");
//	}
//
//	bool LoadItems(const string& filename);
//
//	void ShowItems();
//
//	Item& GetITems(int index)
//	{
//		return items[index];
//	}
//
//};

