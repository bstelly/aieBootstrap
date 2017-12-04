#include "Item.h"

Item::Item()
{
	mPosition = new Vector2();
	mPickedUp = false;
}

void Item::SetPosition(int x, int y)
{
	Vector2 position(x, y);
	*mPosition = position;
	mPickedUp = false;
	mUsed = false;
}

Vector2 Item::GetPosition()
{
	return *mPosition;
}

int Item::GetX()
{
	return mPosition->mX;
}

int Item::GetY()
{
	return mPosition->mY;
}

void Item::HasBeenPickedUp()
{
	mPickedUp = true;
}

void Item::HasBeenFired()
{
	mUsed = true;
}

bool Item::PickedUpStatus()
{
	return mPickedUp;
}

bool Item::FiredStatus()
{
	return mUsed;
}
