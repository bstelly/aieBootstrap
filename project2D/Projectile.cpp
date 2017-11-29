#include "Projectile.h"
#include "PacGuy.h"

Projectile::Projectile()
{
	mPosition = new Vector2();
	mVelocity = new Vector2();
	mSpeed = 10;
	mActive = false;
	mPickedUp = false;
}

void Projectile::SetPosition(int x, int y)
{
	mPosition->mX = x;
	mPosition->mY = y;
}

int Projectile::GetX()
{
	return mPosition->mX;
}

int Projectile::GetY()
{
	return mPosition->mY;
}

void Projectile::Move(int direction)
{
	if (direction == 1)
	{
		*mPosition = *mPosition + (Vector2(1, 0) * mSpeed);
	}
	else if(direction == 2)
	{
		*mPosition = *mPosition + (Vector2(-1, 0) * mSpeed);
	}
	else if (direction == 3)
	{
		*mPosition = *mPosition + (Vector2(0, 1) * mSpeed);
	}
	else if (direction == 4)
	{
		*mPosition = *mPosition + (Vector2(0, -1) * mSpeed);
	}
}

void Projectile::HasBeenPickedUp()
{
	mPickedUp = true;
}

bool Projectile::IsActive()
{
	return mActive;
}

bool Projectile::IsPickedUp()
{
	return mPickedUp;
}

void Projectile::Activate()
{
	mActive = true;
}


