#pragma once
#include <Vector2.h>

class Wall
{
private:
	Vector2* mPosition;

public:
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	Wall();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SetPosition(int x, int y);
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	Vector2 GetPosition();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	float GetX();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	float GetY();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SetX(float x);
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SetY(float y);
};