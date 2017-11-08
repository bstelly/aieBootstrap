#pragma once
#include "Application2D.h"

class PacGuy
{
private:
	float mPx;
	float mPy;
	int mLives;
	int mProjectiles;
public:
	PacGuy(float xPos, float yPos);
	int CheckLives();
	int CheckProjectiles();
	float GetX();
	float GetY();
	void ChangeX(float newX);
	void ChangeY();
	float GetPos();
};