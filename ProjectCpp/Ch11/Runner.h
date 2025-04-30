#pragma once
#include "Common.h"
#include "Util.h"

enum PlayerStat
{
	MINSPEED, MAXSPEED, NONE
};

class Runner
{
private:
	bool isEnd;

protected:
	PlayerStat stat;
	int run;
	int minSpeed;		// Player 클래스에서 protect로 사용할 예정(?)
	int maxSpeed;

	int money;

	string nickName;
	
	virtual void SetMaxSpeed();		// 플레이어마다 속도가 다르게 설정해주는
	void DrawMoveDistance();
	virtual void SetShape();		// 플레이어 형태


public:
	Runner() : run(0), isEnd(false), minSpeed(1), maxSpeed(5), nickName("P"), stat(PlayerStat::NONE), money(1000) {}
	Runner(string nickName) : run(0), isEnd(false), minSpeed(1), maxSpeed(5), nickName(nickName), stat(PlayerStat::NONE), money(1000) {}
	void Run();

	bool CheckEndLine(int length);	// 맵 길이에 도달하면 종료가 되도록 bool 함수를 사용했다.
	
	virtual void ShowPlayerGameInfo();

	void UpGrade(PlayerStat selectedStat);
	void UpGrade(PlayerStat selectedStat, int amount);

	void SetMin(int value);
	void SetMax(int value);

	void Initialize();
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

	void ShowPlayerGameInfo() override;
public:
	
	void UpGrade(PlayerStat selectedStat);
	void UpGrade(PlayerStat selectedStat, int amount);

	void SetMin(int value);
	void SetMax(int value);

};





class EnemyRunner : public Runner
{
private:
	bool isEnemyEnd;
protected:
	int run;
	int MinSpeed;
	int MaxSpeed;
	string EnemyShape;

	void DrawMoveDistance();

	virtual void EnemySetMaxSpeed();
	virtual void EnemySetShape();
public:
	EnemyRunner() : isEnemyEnd(false), run(0), MinSpeed(1), MaxSpeed(2), EnemyShape("▲") {}
	EnemyRunner(string EnemyShape) : isEnemyEnd(false), run(0), MinSpeed(1), MaxSpeed(2), EnemyShape(EnemyShape) {}
	void EnemyRun();

	bool CheckEndLine(int length);
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