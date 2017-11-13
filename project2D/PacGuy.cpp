#include "PacGuy.h"

PacGuy::PacGuy()
{	
	mPosition = new Vector2(15, 360);
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
	return mPosition->mX;
}

float PacGuy::GetY()
{
	return mPosition->mY;
}

void PacGuy::ChangeX(float x)
{
	mPosition->mX = x;
}

void PacGuy::ChangeY(float y)
{
	mPosition->mY = y;
}

void PacGuy::ChangePos(Vector2 &other)
{
	mPosition->mX = mPosition->mX + other.mX;
	mPosition->mY = mPosition->mY + other.mY;
}

Vector2 PacGuy::GetPos()
{	
	Vector2* temp = new Vector2;
	temp->mX = mPosition->mX;
	temp->mY = mPosition->mY;
	return *temp;
}

