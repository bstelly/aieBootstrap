#pragma once
#include "PacGuy.h"

class Projectile
{
private:
	Vector2* mPosition;
	Vector2* mVelocity;
	int mSpeed;
	bool mActive;
	bool mPickedUp;
	int mFacing;
	bool mIsDirectionSet;
	public:
	Projectile();
	void SetPosition(int y, int x);
	int GetX();
	int GetY();
	void Move();
	void HasBeenPickedUp();
	bool IsActive();
	bool IsPickedUp();
	void Activate();
	bool DirectionStatus();
	void SetDirectionFacing(int dir);
	void ChangeDirectionStatus();
	void Deactivate();
};