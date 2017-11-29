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
public:
	Projectile();
	void SetPosition(int y, int x);
	int GetX();
	int GetY();
	void Move(int direction);
	void HasBeenPickedUp();
	bool IsActive();
	bool IsPickedUp();
	void Activate();
};