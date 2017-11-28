#pragma once
#include <Vector2.h>

class PacGuy
{
private:
	Vector2* mPosition;
	int mLives;
	int mProjectiles;
public:
	PacGuy();
	bool CheckLives();
	bool CheckProjectiles();
	float GetX();
	float GetY();
	void ChangeX(int x);
	void ChangeY(int y);
	void ChangePos(Vector2 &other);
	Vector2 GetPos();
	void AddProjectile();
	void LoseALife();
};