#pragma once
#include <Vector2.h>

class Enemy
{
private:
	Vector2* mPosition;
	
public:
	Enemy();
	Enemy(float x, float y);
	float GetX();
	float GetY();
	void ChangePos(Vector2 &other);
	void SetX(float x);
	void SetY(float Y);
	Vector2 GetPos();
};