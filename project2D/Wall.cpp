#include "Wall.h"

Wall::Wall()
{
	mPosition = new Vector2();
}

void Wall::SetPosition(int x, int y)
{
	Vector2 position(x, y);
	*mPosition = position;
}

Vector2 Wall::GetPosition()
{
	return *mPosition;
}

float Wall::GetX()
{
	return mPosition->mX;
}

float Wall::GetY()
{
	return mPosition->mY;
}

void Wall::SetX(float x)
{
	mPosition->mX = x;
}

void Wall::SetY(float y)
{
	mPosition->mY = y;
}