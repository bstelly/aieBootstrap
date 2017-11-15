#pragma once
#include <Vector2.h>

class Item
{
private:
	Vector2* mPosition;
	
public:
	Item();
	Item(float x, float y);
	Vector2 GetPosition();
	float GetX();
	float GetY();
};