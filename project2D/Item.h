#pragma once
#include <Vector2.h>

class Item
{
private:
	Vector2* mPosition;
	bool mPickedUp;
	bool mUsed;
public:
	//Prototype : Item()
	//Arguments : none
	//Description : Creates an instance of the Item class
	//Precondition : none
	//Postcondition : an instance of the Item class is created
	//Protection Level : public
	Item();
	
	//Prototype : void SetPosition(int x, int y)
	//Arguments : two intergers
	//Description : Sets the position of an object of type item
	//Precondition : there must be an instance of the item class
	//Postcondition : an instance of the item class has a set position
	//Protection Level : public
	void SetPosition(int x, int y);
	
	//Prototype : Vector2 GetPosition()
	//Arguments :  none
	//Description : Returns a Vector2
	//Precondition : there must be an instance of the item class
	//Postcondition : a Vector2 is returned
	//Protection Level : public
	Vector2 GetPosition();
	
	//Prototype : int GetX()
	//Arguments : none
	//Description : returns the x value of an object of type item
	//Precondition : there must be an instance of the Item class
	//Postcondition : an interger is returned
	//Protection Level : public 
	int GetX();
	
	//Prototype : int GetY()
	//Arguments : none
	//Description : returns the y value of an object of type item
	//Precondition : there must be an instance of the Item class
	//Postcondition : an interger is returned
	//Protection Level : public
	int GetY();
	
	//Prototype : 	bool PickedUpStatus()
	//Arguments : none
	//Description : returns a boolean value
	//Precondition : there must be an instance of the item class
	//Postcondition : a boolean value is returned
	//Protection Level : public
	bool PickedUpStatus();

	//Prototype : bool FiredStatus()
	//Arguments : none
	//Description : returns a boolean value
	//Precondition : there must be an instance of the item class
	//Postcondition : a boolean value is returned
	//Protection Level : public
	bool FiredStatus();
	
	//Prototype : void HasBeenPickedUp()
	//Arguments : none
	//Description : changes the value of an object of type item's mPickedUp member variable
	//Precondition : there must be an instance of the item class
	//Postcondition : mPickedUp is assigned true
	//Protection Level : public
	void HasBeenPickedUp();
	
	//Prototype : void HasBeenFired()
	//Arguments : none
	//Description : changes the value of an object of type item's mUsed member variable
	//Precondition : there must be an instance of the item class
	//Postcondition : mUsed is assigned true
	//Protection Level : public
	void HasBeenFired();

};