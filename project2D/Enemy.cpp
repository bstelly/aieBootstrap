#include "Enemy.h"

Enemy::Enemy()
{
	mPosition = new Vector2();
	mVelocity = new Vector2();
	mSpeed = 0;
	mIsDead = false;
}

void Enemy::SetPosition(int x, int y, Vector2 velo, int speed)
{
	mPosition->mX = x;
	mPosition->mY = y;
	mVelocity = new Vector2(velo.mX, velo.mY);
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
	*mPosition = *mPosition + (*mVelocity * mSpeed);
}

void Enemy::ChangeVelocity(Vector2 velo)
{
	*mVelocity = velo;
}

Vector2 Enemy::GetVelocity()
{
	return *mVelocity;
}

bool Enemy::Status()
{
	return mIsDead;
}

void Enemy::EnemyHasDied()
{
	mIsDead = true;
}
