#include "Enemy.h"
#include <time.h>

Enemy::Enemy()
{
	mPosition = new Vector2;
	mDirection;
}

int Enemy::GetDirection()
{
	return mDirection;
}

void Enemy::SetPosition(int x, int y, int dir)
{
	mPosition->mX = x;
	mPosition->mY = y;
	mDirection = dir;		//0 is left, 1 is right, 2 is up, 3 is down
}

void Enemy::ChangeDirection(int dir)
{
	srand(time(NULL));
	int randNum = rand() % 3;
	while (randNum == dir)
	{
		randNum = rand() % 3;
	}
	mDirection = randNum;
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

