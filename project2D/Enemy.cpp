#include "Enemy.h"
#include <time.h>

Enemy::Enemy()
{
	mPosition = new Vector2;
	mDirection;
	mSpeed;
}

int Enemy::GetDirection()
{
	return mDirection;
}

void Enemy::SetPosition(int x, int y, int direction, int speed)
{
	mPosition->mX = x;
	mPosition->mY = y;
	mDirection = direction;		//1 is left, 2 is right, 3 is up, 4 is down
	mSpeed = speed;
}

float Enemy::GetX()
{
	return mPosition->mX;
}

float Enemy::GetY()
{
	return mPosition->mY;
}

void Enemy::ChangePos(Vector2 &other)
{
	mPosition->mX += (mPosition->mX + other.mX);
	mPosition->mY += (mPosition->mY + other.mY);
}

void Enemy::SetX(float x)
{
	mPosition->mX = x;
}

void Enemy::SetY(float y)
{
	mPosition->mY = y;
}

Vector2 Enemy::GetPos()
{
	return *mPosition;
}

void Enemy::ChangeX(int x)
{
	mPosition->mX = x;
}

void Enemy::ChangeY(int y)
{
	mPosition->mY = y;
}

void Enemy::Move()
{
	Vector2 moveLeft(-(mSpeed), 0);
	Vector2 moveRight(mSpeed, 0);
	Vector2 moveUp(0, mSpeed);
	Vector2 moveDown(0, -(mSpeed));

	if (mDirection == 1)
	{
		*mPosition = *mPosition + moveLeft;
	}
	if (mDirection == 2)
	{
		*mPosition = *mPosition + moveRight;
	}
	if (mDirection == 3)
	{
		*mPosition = *mPosition + moveUp;
	}
	if (mDirection == 4)
	{
		*mPosition = *mPosition + moveDown;
	}
}

void Enemy::ChangeDirection(int num)
{
	mDirection = num;
}

