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
	int mFacing;
	bool mIsDirectionSet;
	
public:
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	Projectile();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SetPosition(int y, int x);
	
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
	void Move();
	
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
	bool IsActive();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	bool IsPickedUp();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void Activate();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	bool DirectionStatus();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SetDirectionFacing(int dir);
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void ChangeDirectionStatus();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void Deactivate();
};