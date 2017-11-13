#pragma once
#include <Vector2.h>
#include "Wall.h"
class PacGuy
{
private:
	Vector2* mPosition;
	int mLives;
	int mProjectiles;
public:
	PacGuy();
	int CheckLives();
	int CheckProjectiles();
	float GetX();
	float GetY();
	void ChangeX(float x);
	void ChangeY(float y);
	void ChangePos(Vector2 &other);
	Vector2 GetPos();
	int CheckForWall();
};