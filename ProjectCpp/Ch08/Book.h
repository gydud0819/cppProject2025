#pragma once
#include "Common.h"

// 책
// Spell Book, Story Book, Quest Book

// 모든 책들이 해야하는 기능이 어떤 것들이 있는지
// 모든 책들을 읽을 수 있는가?

/*
* 상속의 3가지 방법
  public, private, protected 

  1. public 상속을 하면 public 안에 있는 함수나 변수들이 모두 그대로 사용할 수 있다는 것
  보여주고 싶은 것만 public을 사용해서 그대로 보여준다.
  2. private, protected 
*/

class BookMark
{
	int page;
public:
	void ShowPage();
};

// 문제의 여지가 있는 코드
// 책은 반드시 BookMark를 가지고 있는 형태이다. (면접시 나오는 질문)
// 모든 코드를 상속시켜버리면 코드에 필요없는 코드가 추가된다. 

// (B) Is-A		: B는 A이다.
// (B) Has - A	: B는 A를 가지고 있다. 
class Book // 얘가 부모 클래스, 책은 책갈피를 가지고 있다. 
{
private:
	BookMark* bookMark;		// 포인터로 사용한다. BookMark* bookMark = NULL; (bookMark가 아무것도 가리키고 있지 않다라는 뜻)
public:
	void Read();
};

class Spell_Book : public Book	// SpellBook은 Book을 가지고 있다? 
{

};

class Story_Book : public Book
{

};

class Quest_Book : public Book
{

};