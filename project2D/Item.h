#pragma once
#include <Vector2.h>

class Item
{
private:
	Vector2* mPosition;
	bool mPickedUp;
	bool mUsed;
public:
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	Item();
	
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
	int GetX();
	
	//Prototype : 
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	int GetY();
	
	//Prototype : 
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level :
	bool PickedUpStatus();

	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	bool FiredStatus();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void HasBeenPickedUp();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void HasBeenFired();

};