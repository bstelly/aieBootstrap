#pragma once
#include <Vector2.h>

class Enemy
{
private:
	Vector2* mPosition;
	int mDirection;
	
public:
	Enemy();
	void SetPosition(int x, int y, int dir);
	float GetX();
	float GetY();
	void ChangePos(Vector2 &other);
	void SetX(float x);
	void SetY(float Y);
	void ChangeX(int x);
	void ChangeY(int y);
	Vector2 GetPos();
	int GetDirection();
	void ChangeDirection(int direction);
};