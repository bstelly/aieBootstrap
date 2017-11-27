#include "PacGuy.h"

PacGuy::PacGuy()
{	
	mPosition = new Vector2(0, 0);
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
	if (mProjectiles > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PacGuy::AddProjectile()
{
	mProjectiles = mProjectiles + 1;
}

float PacGuy::GetX()
{
	return mPosition->mX;
}

float PacGuy::GetY()
{
	return mPosition->mY;
}

void PacGuy::ChangeX(int x)
{
	mPosition->mX = x;
}

void PacGuy::ChangeY(int y)
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

