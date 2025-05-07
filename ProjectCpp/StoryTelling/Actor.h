#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// teller : ~~대사 치는 걸 표현해준다.
class Actor
{
public:
	void Tell(const string& teller, const string& story);

	bool Selection(const string& teller, const string& story1, const string& story2);

	
};

