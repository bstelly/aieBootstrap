#include "Item.h"

Item::Item()
{
	mPosition = new Vector2;
}

Item::Item(float x, float y)
{
	Vector2 position(x, y);
	*mPosition = position;
}

Vector2 Item::GetPosition()
{
	return *mPosition;
}

float Item::GetX()
{
	return mPosition->mX;
}

float Item::GetY()
{
	return mPosition->mY;
}