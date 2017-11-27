#pragma once
#include <Vector2.h>

class Wall
{
private:
	Vector2* mPosition;

public:
	Wall();
	void SetPosition(int x, int y);
	Vector2 GetPosition();
	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
};