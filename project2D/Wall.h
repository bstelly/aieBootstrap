#pragma once
#include <Vector2.h>

class Wall
{
private:
	Vector2* mPosition;

public:
	Wall();
	void SetPosition(float x, float y);
	Vector2 GetPosition();
	float GetX();
	float GetY();
};