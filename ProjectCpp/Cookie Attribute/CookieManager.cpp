#include "CookieManager.h"

CookieManager::CookieManager()
{
	windCookieIndex = 0;
	fireCookieIndex = 0;

	for (int i = 0; i < Cookie_Count; i++)	// ∏µÁ ƒ≠¿ª nullptr∑Œ √ ±‚»≠«—¥Ÿ.
	{
		windcookies[i] = nullptr;
	}
	string windNames[] = { "πŸ∂˜±√ºˆ ƒÌ≈∞", "∆‰Ω∫√Ú∏Æ∏¿ ƒÌ≈∞", "πŒ∆Æ√ ƒ⁄∏¿ ƒÌ≈∞", "¿«¿˚∏¿ ƒÌ≈∞", "±∏πÃ»£∏¿ ƒÌ≈∞",
						   "±◊∏∞∆ºπ´Ω∫∏¿ ƒÌ≈∞", "øÏπ´∏¿ ƒÌ≈∞" };
	Rank windRanks[] = { LEGENDARY, EPIC, EPIC, EPIC, EPIC, EPIC,EPIC };

	int windCount = sizeof(windNames) / sizeof(string); // πËø≠ ø‰º“ ∞≥ºˆ ∞ËªÍ

	for (int i = 0; i < 7; i++)
	{
		windcookies[i] = new Wind_Cookie(windNames[i], Wind, windRanks[i]);
	}
	for (int i = 7; i < Cookie_Count; i++)
	{
		windcookies[i] = nullptr;
	}

	//------------------------------------------------------------------------------------------

	for (int i = 0; i < Cookie_Count; i++)	// ∏µÁ ƒ≠¿ª nullptr∑Œ √ ±‚»≠«—¥Ÿ.
	{
		firecookies[i] = nullptr;
	}

	string fireNames[] = { "πˆ¥◊Ω∫∆ƒ¿ÃΩ∫ ƒÌ≈∞", "∫“≤…¡§∑… ƒÌ≈∞", "øÎ∞˙µÂ∑°∞Ô ƒÌ≈∞", "ƒ∏ªÁ¿ÃΩ≈∏¿ ƒÌ≈∞", "ƒ•∏Æ∏¿ ƒÌ≈∞","≈©∏≤¿Ø¥œƒ‹ ƒÌ≈∞", 
						   "º∫∞‘∏¿ ƒÌ≈∞", "»£π–∏¿ ƒÌ≈∞", "∏∂∂Û∏¿ ƒÌ≈∞", "≈∏∏£∆Æ≈∏≈¡∏¿ ƒÌ≈∞", "ø√∏Æ∫Í∏¿ ƒÌ≈∞", "≥”∏∆≈∏¿Ã∞≈∏¿ ƒÌ≈∞", "øÏπ´∏¿ ƒÌ≈∞" };
	Rank fireRanks[] = { BEAST, LEGENDARY, DRAGON, SUPER_EPIC, EPIC, EPIC, EPIC, EPIC, EPIC, EPIC, EPIC, EPIC, EPIC };

	int fireCount = sizeof(fireNames) / sizeof(string); // πËø≠ ø‰º“ ∞≥ºˆ ∞ËªÍ

	for (int i = 0; i < 13; i++)
	{
		firecookies[i] = new Fire_Cookie(fireNames[i], Fire, fireRanks[i]);
	}
	for (int i = 13; i < Cookie_Count; i++)
	{
		firecookies[i] = nullptr;
	}

}

void CookieManager::ShowAllCookies()
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		if (windcookies[i] != nullptr)
		{
			windcookies[i]->ShowCookieInfo();

		}
		if (firecookies[i] != nullptr)
		{

			firecookies[i]->ShowCookieInfo();
		}
	}
}

void CookieManager::ShowCookieByElement(ElementType type)	// º”º∫∫∞∑Œ »£√‚«œ±‚ ¿ß«ÿ º±æ«ﬂ¥Ÿ.
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		if (windcookies[i] != nullptr && windcookies[i]->GetElementType() == type)
		{
			windcookies[i]->ShowCookieInfo();
		}
		if (firecookies[i] != nullptr && firecookies[i]->GetElementType() == type)
		{
			firecookies[i]->ShowCookieInfo();
		}
	}
}

void CookieManager::ShowCookieByRank(Rank rank)
{
	for (int i = 0; i < Cookie_Count; i++)
	{
		if (windcookies[i] != nullptr && windcookies[i]->GetRank() == rank)
		{
			windcookies[i]->ShowCookieInfo();
		}
		if (firecookies[i] != nullptr && firecookies[i]->GetRank() == rank)
		{
			firecookies[i]->ShowCookieInfo();
		}
	}
}

void CookieManager::AddCookies(/*string name, int elementInput, int rankInput*/)
{
	string name;
	int elementInput;
	int rankInput;

	cout << "ƒÌ≈∞ ¡§∫∏∏¶ ¿‘∑¬«œººø‰." << endl;
	cin.ignore();
	getline(cin, name);

	cout << "º”º∫¿ª ¿‘∑¬«œººø‰" << endl;
	cout << "0: ∫“ 1: πŸ∂˜" << endl;
	cin >> elementInput;

	cout << "µÓ±ﬁ¿ª ¿‘∑¬«œººø‰" << endl;
	cout << "0. ACIENT 1. BEAST 2. LEGENDARY 3. DRAGON" << endl;
	cin >> rankInput;

	ElementType element = static_cast<ElementType>(elementInput);
	Rank rank = static_cast<Rank>(rankInput);

	if (element == Wind) 
	{
		if (windCookieIndex >= Cookie_Count) 
		{
			cout << "[∞Ê∞Ì] ¥ı ¿ÃªÛ πŸ∂˜ º”º∫ ƒÌ≈∞∏¶ √ﬂ∞°«“ ºˆ æ¯Ω¿¥œ¥Ÿ!" << endl;
			return;
		}
		windcookies[windCookieIndex++] = new Wind_Cookie(name, Wind, rank);
		cout << "[øœ∑·] πŸ∂˜ º”º∫ ƒÌ≈∞ √ﬂ∞°µ !" << endl;
	}
	else if (element == Fire) 
	{
		if (fireCookieIndex >= Cookie_Count) 
		{
			cout << "[∞Ê∞Ì] ¥ı ¿ÃªÛ ∫“ º”º∫ ƒÌ≈∞∏¶ √ﬂ∞°«“ ºˆ æ¯Ω¿¥œ¥Ÿ!" << endl;
			return;
		}
		firecookies[fireCookieIndex++] = new Fire_Cookie(name, Fire, rank);
		cout << "[øœ∑·] ∫“ º”º∫ ƒÌ≈∞ √ﬂ∞°µ !" << endl;
	}
	else {
		cout << "[ø¿∑˘] ¿ﬂ∏¯µ» º”º∫¿‘¥œ¥Ÿ!" << endl;
	}
}





