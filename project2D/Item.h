#pragma once
#include <Vector2.h>

class Item
{
private:
	Vector2* mPosition;
	bool mPickedUp;
public:
	Item();
	void SetPosition(int x, int y);
	Vector2 GetPosition();
	int GetX();
	int GetY();
	bool Status();
	void HasBeenPickedUp();

};