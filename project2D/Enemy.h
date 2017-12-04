#pragma once
#include <Vector2.h>

class Enemy
{
private:
	Vector2* mPosition;
	Vector2* mVelocity; //Direction enemy is moving
	int mSpeed;
	bool mIsDead;

public:
	Enemy();
	void SetPosition(int x, int y, Vector2 velo, int speed);
	float GetX();
	float GetY();
	void ChangePos(Vector2 &other);
	void SetX(float x);
	void SetY(float Y);
	void ChangeX(int x);
	void ChangeY(int y);
	Vector2 GetPos();
	void ChangeVelocity(Vector2 velo);
	void Move();
	Vector2 GetVelocity();
	bool Status();
	void EnemyHasDied();
};