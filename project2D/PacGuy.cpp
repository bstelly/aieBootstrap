#include "PacGuy.h"

PacGuy::PacGuy(float xPos, float yPos)
{
	mPx = xPos;
	mPy = yPos;
	mLives = 3;
	mProjectiles = 0;
}

int PacGuy::CheckLives()		//return 1 if lives > 0,  return 0 if lives = 0
{
	if (mLives > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int PacGuy::CheckProjectiles()	//return 1 if projectiles > 0, return 0 if projectiles = 0
{
	if (mProjectiles == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

float PacGuy::GetX()
{
	return mPx;
}

float PacGuy::GetY()
{
	return mPy;
}

void PacGuy::ChangeX(float newX)
{
	mPx = newX;
}
