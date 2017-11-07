#pragma once
#include "Application2D.h"

class PacGuy
{
private:
	int mLives;
	int mProjectiles;

public:
	PacGuy(float xPos, float yPos, float radius);
	int CheckLives();
	int CheckProjectiles();
};