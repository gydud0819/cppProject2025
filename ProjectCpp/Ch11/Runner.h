#pragma once
#include "Common.h"
#include "Util.h"

class Runner
{
private:
	int run;
	bool isEnd;

protected:
	int minSpeed;		// Player 클래스에서 protect로 사용할 예정(?)
	int maxSpeed;
	string nickName;

public:
	Runner() : run(0), isEnd(false), minSpeed(1), maxSpeed(5), nickName("P") {}
	//Runner(int run): run(run) {}
	Runner(string nickName) : run(0), isEnd(false), minSpeed(1), maxSpeed(5), nickName(nickName) {}
	virtual void Run();

	bool CheckEndLine(int lengh);
};

class Player : public Runner
{
private:

public:
	Player() : Runner() 
	{
		nickName = "P";
	}
	Player(string nickName) : Runner(nickName) {}
public:
	void Run() override;
	void UpGrade();

};

class Enemy : public Runner
{
private:

public:

protected:
};