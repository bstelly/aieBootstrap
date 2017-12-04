#pragma once
#include <Vector2.h>

class Item
{
private:
	Vector2* mPosition;
	bool mPickedUp;
	bool mUsed;
public:
	Item();
	void SetPosition(int x, int y);
	Vector2 GetPosition();
	int GetX();
	int GetY();
	bool PickedUpStatus();
	bool FiredStatus();
	void HasBeenPickedUp();
	void HasBeenFired();

};