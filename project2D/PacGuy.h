#pragma once
#include <Vector2.h>
#include "Item.h"

class PacGuy
{
private:
	Vector2* mPosition;
	int mLives;
	int mProjectiles;
	int mPellets;
	int mFacing; //1 is right, 2 is left, 3 is up, 4 is down
public:
	PacGuy();
	bool CheckLives();
	bool CheckProjectiles();
	int NumLives();
	int NumProjectiles();
	float GetX();
	float GetY();
	void ChangeX(int x);
	void ChangeY(int y);
	void ChangePos(Vector2 &other);
	Vector2 GetPos();
	void AddProjectile();
	void SubtractProjectile();
	void LoseALife();
	void PickUpPellet();
	int NumPellets();
	int Facing();
	void ChangeDirection(int dir);
};