#pragma once
#include "Common.h"
#include "Util.h"

class Runner
{
private:
	bool isEnd;

protected:
	int run;
	int minSpeed;		// Player 클래스에서 protect로 사용할 예정(?)
	int maxSpeed;
	string nickName;
	
	virtual void SetMaxSpeed();		// 플레이어마다 속도가 다르게 설정해주는
	void DrawMoveDistance();
	virtual void SetShape();		// 플레이어 형태

public:
	Runner() : run(0), isEnd(false), minSpeed(1), maxSpeed(5), nickName("P") {}
	Runner(string nickName) : run(0), isEnd(false), minSpeed(1), maxSpeed(5), nickName(nickName) {}
	void Run();

	bool CheckEndLine(int lengh);	// 맵 길이에 도달하면 종료가 되도록 bool 함수를 사용했다.
};

class Player : public Runner
{
protected:
	void SetMaxSpeed() override;
	void SetShape() override;
	
public:
	Player() : Runner() 
	{
		nickName = "옷";
	}
	Player(string nickName) : Runner(nickName) {}
public:
	
	void UpGrade();

};

class EnemyRunner
{
private:
	bool isEnemyEnd;
protected:
	int run;
	int MinSpeed;
	int MaxSpeed;
	string EnemyShape;

public:
	EnemyRunner() : isEnemyEnd(false), run(0), MinSpeed(1), MaxSpeed(2), EnemyShape("▲") {}
	EnemyRunner(string EnemyShape) : isEnemyEnd(false), run(0), MinSpeed(1), MaxSpeed(2), EnemyShape(EnemyShape) {}

	virtual void EnemySetMaxSpeed();
	virtual void EnemySetShape();
};

class Enemy : public EnemyRunner
{
private:

public:
	Enemy() : EnemyRunner()
	{
		EnemyShape = "E";
	}
	Enemy(string EnemyShape) : EnemyRunner(EnemyShape) {}

protected:
	void EnemySetMaxSpeed() override;
	void EnemySetShape() override;
};