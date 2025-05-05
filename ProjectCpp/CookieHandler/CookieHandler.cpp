#include "CookieHandler.h"

ELEMENTTYPE::ElementType Cookie::StringToElementType(const string& str)
{
	if (str == "Wind")
		return ELEMENTTYPE::Wind;
	else if (str == "Fire")
		return ELEMENTTYPE::Fire;
	else if (str == "Ice")
		return ELEMENTTYPE::Ice;
	else if (str == "Dark")
		return ELEMENTTYPE::Dark;
	else if (str == "Water")
		return ELEMENTTYPE::Water;
	else if (str == "Ground")
		return ELEMENTTYPE::Ground;
	else if (str == "Electro")
		return ELEMENTTYPE::Electro;
	else if (str == "Light")
		return ELEMENTTYPE::Light;
	else if (str == "Independent")
		return ELEMENTTYPE::Independent;
	else 
	{
		/*cerr << "일치하는 속성 없음: '" << str << "'" << endl;*/
		return ELEMENTTYPE::Wind; // 원하는 기본값
	}


}

RANK::Rank Cookie::StringToRank(const string& str)
{
	if (str == "LEGENDARY")
		return RANK::LEGENDARY;
	else if (str == "ANCIENT")
		return RANK::ANCIENT;
	else if (str == "SUPER_EPIC")
		return RANK::SUPER_EPIC;
	else if (str == "EPIC")
		return RANK::EPIC;
	else if (str == "RARE")
		return RANK::RARE;
	else if (str == "COMMON")
		return RANK::COMMON;
	else 
	{
		/*cerr << "일치하는 등급 없음: '" << str << "'" << endl;*/
		return RANK::LEGENDARY; // 명시적 기본값
	}


}

string Cookie::ReturnElementType() const
{
	switch (type) 
	{
	case ELEMENTTYPE::Fire: return "Fire";
	case ELEMENTTYPE::Water: return "Water";
	case ELEMENTTYPE::Dark: return "Dark";
	case ELEMENTTYPE::Ground: return "Ground";
	case ELEMENTTYPE::Electro: return "Electro";
	case ELEMENTTYPE::Wind: return "Wind";
	case ELEMENTTYPE::Ice: return "Ice";
	case ELEMENTTYPE::Light: return "Light";
	case ELEMENTTYPE::Independent: return "Independent";
	default: return "Unknown";
	}

}

string Cookie::ReturnRank() const
{
	switch (rank)
	{
	case RANK::ANCIENT: return "ANCIENT";
		
	case RANK::LEGENDARY: return "LEGENDARY";
		
	case RANK::SUPER_EPIC: return "SUPER_EPIC";
		
	case RANK::EPIC: return "EPIC";
		
	case RANK::RARE: return "RARE";
		
	case RANK::COMMON: return "COMMON";
		
	default:
		break;
	}
	
}


int CookieHandler::LoadCookies(const string& filename, Cookie cookies[])
{
	ifstream file(filename);    // 파일 이름으로 파일을 가져온다. (프로젝트 파일에 있는 data.txt를 불러올 수 있음)

	if (!file.is_open())  // 파일이 열리지 않았다면
	{
		cerr << "파일을 열 수 없습니다" << filename << endl;
		return 0;
	}

	int cookieCount = 0;
	string line;	// 메모장에 있는 내용을 한줄 씩 가져온다. 

	// item의 항목을 읽어와야한다.
	//while (getline(file, line) && cookieCount < MAX_COOKIES)
	//{
	//	istringstream iss(line);
	//	int index;
	//	string name, name2, name3, name4, typestr, rankstr;

	//	// 데이터를 파싱한다 == 데이터를 각 변수에 맞게 저장되도록 변환하는 것
	//	if (iss >> index >> name >> name2 >> name3 >> name4 >> typestr >> rankstr)
	//	{
	//		ELEMENTTYPE::ElementType type = Cookie::StringToElementType(typestr);
	//		RANK::Rank rank = Cookie::StringToRank(rankstr);
	//		//ItemDataType newType(typeCount, amount);
	//		cookies[cookieCount++] = Cookie(index, name, name2, name3, name4, type, rank);	// 생성자로 만든 데이터를 대입한 다음 1을 증가시켜준다는 의미이다. 
	//	}
	//	else
	//	{
	//		cerr << "유효하지 않은 데이터가 존재합니다" << line << endl;		// 이거 왜뜸???????????
	//	}
	//}

	while (getline(file, line) && cookieCount < MAX_COOKIES)
	{
    // 빈 줄 건너뛰기
    if (line.empty() || line[0] == '#')
        continue;
        
    // 문자열 전체를 저장
    string cookieFullText = line;
    
    // 마지막 두 단어 (속성과 등급) 찾기
    string typeStr, rankStr;
    size_t lastSpace = cookieFullText.find_last_of(" ");
    if (lastSpace != string::npos) 
	{
        typeStr = cookieFullText.substr(lastSpace + 1);
        cookieFullText = cookieFullText.substr(0, lastSpace);
    }
    
    lastSpace = cookieFullText.find_last_of(" ");

    if (lastSpace != string::npos) 
	{
        rankStr = cookieFullText.substr(lastSpace + 1);
        cookieFullText = cookieFullText.substr(0, lastSpace);
    }
    
    // 이제 cookieFullText는 순수 쿠키 이름만 포함
    
    try 
	{
        ELEMENTTYPE::ElementType type = Cookie::StringToElementType(typeStr);
        RANK::Rank rank = Cookie::StringToRank(rankStr);
        cookies[cookieCount++] = Cookie(cookieCount, cookieFullText, type, rank);
    } 
	catch (...) 
	{
        cerr << "변환 오류: " << line << endl;
    }
}


	file.close();	// close까지 해줘야 한다. 

	return cookieCount;
}

//ELEMENTTYPE::ElementType Cookie::StringToElementType(const string& str) {
//	cerr << "입력된 속성 문자열: '" << str << "'" << endl; // 디버깅 출력 추가
//
//	if (str == "Fire") return ELEMENTTYPE::Fire;
//	else if (str == "Wind") return ELEMENTTYPE::Wind;
//	// ...
//	else {
//		cerr << "일치하는 속성 없음: '" << str << "'" << endl; // 어떤 조건도 충족하지 않는 경우
//		return ELEMENTTYPE::Fire; // 기본값
//	}
//}


