#include "PacGuy.h"

PacGuy::PacGuy()
{	
	mPosition = new Vector2(15, 15);
	mLives = 3;
	mProjectiles = 0;
}

bool PacGuy::CheckLives()
{
	if (mLives > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PacGuy::CheckProjectiles()
{
	if (mProjectiles == 0)
	{
		return true;
	}
	else
	{
		return false;
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

