#include "Enemy.h"

Enemy::Enemy()
{
	mPosition = new Vector2;
}

Enemy::Enemy(float x, float y)
{
	Vector2 position(x, y);
	mPosition->mX = x;
	mPosition->mY = y;
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
	mPosition->mX = mPosition->mX + other.mX;
	mPosition->mY = mPosition->mY + other.mY;
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