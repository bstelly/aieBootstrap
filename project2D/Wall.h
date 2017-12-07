#pragma once
#include <Vector2.h>

class Wall
{
private:
	Vector2* mPosition;

public:
	//Prototype : Wall()
	//Arguments : none
	//Description : creates an instance of the Wall class
	//Precondition : none
	//Postcondition : an instance of the wall class is created
	//Protection Level : public
	Wall();
	
	//Prototype : void SetPosition(int x, int y)
	//Arguments : two intergers
	//Description : Sets the position of a wall object
	//Precondition : there must be an instance of the Wall class
	//Postcondition : a wall has a new position
	//Protection Level : public
	void SetPosition(int x, int y);
	
	//Prototype : Vector2 GetPosition()
	//Arguments : none
	//Description : returns the position of a wall
	//Precondition : there must be an instance of the Wall class
	//Postcondition : a vector2 is returned
	//Protection Level : public
	Vector2 GetPosition();
	
	//Prototype : GetX()
	//Arguments : none
	//Description : returns the x value of a wall
	//Precondition : there must be an instance of the Wall class
	//Postcondition : a float is returned
	//Protection Level : public
	float GetX();
	
	//Prototype : float GetY()
	//Arguments : none
	//Description : returns the y value of a wall
	//Precondition : there must be an instance of the Wall class
	//Postcondition : a float is returned
	//Protection Level : public
	float GetY();
	

};