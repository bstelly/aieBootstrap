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
	//Prototype : Projectile()
	//Arguments : none
	//Description : Creates an instance of the projectile class
	//Precondition : none
	//Postcondition : an instance of the projectile class is created
	//Protection Level : public
	Projectile();
	
	//Prototype : void SetPosition(int y, int x)
	//Arguments : two intergers
	//Description : Sets the position of an object of type projectile
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : 
	//Protection Level : 
	void SetPosition(int y, int x);
	
	//Prototype : int GetX()
	//Arguments : none
	//Description : returns the x value of an object of type Projectile
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : the x value is returned
	//Protection Level : public
	int GetX();
	
	//Prototype : int GetY()
	//Arguments : none
	//Description : returns the y value of an object of type Projectile
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : the y value is returned
	//Protection Level : public
	int GetY();
	
	//Prototype : void Move()
	//Arguments : none
	//Description : Changes the position of an object of tye Projectile
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : The position is changed
	//Protection Level : public
	void Move();
	
	//Prototype : void HasBeenPickedUp()
	//Arguments : none
	//Description : sets the value of mPickedUp to true
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mPicked up is assigned true
	//Protection Level : public
	void HasBeenPickedUp();
	
	//Prototype : bool IsActive()
	//Arguments : none
	//Description : changes the value of mActive
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mActive is assigned the opposite of its current value
	//Protection Level : public
	bool IsActive();
	
	//Prototype : bool IsPickedUp()
	//Arguments : none
	//Description : changes the value of mPickedUp to true
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mPickedUp is assigned true
	//Protection Level : public
	bool IsPickedUp();
	
	//Prototype : void Activate()
	//Arguments : none
	//Description : sets the value of mActive to true
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mActive is assigned true
	//Protection Level : public
	void Activate();
	
	//Prototype : bool DirectionStatus()
	//Arguments : none
	//Description : returns a boolean based on mIsDirectionSet
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : a boolean is returned
	//Protection Level : public
	bool DirectionStatus();
	
	//Prototype : void SetDirectionFacing(int dir)
	//Arguments : an interger
	//Description : changes the value of mFacing
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mFacing is assigned a new interger
	//Protection Level : public
	void SetDirectionFacing(int dir);
	
	//Prototype : void ChangeDirectionStatus()
	//Arguments : none
	//Description : changes mIsDirectionSet to true
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mIsDirectionSet is assigned true
	//Protection Level : public
	void ChangeDirectionStatus();
	
	//Prototype : void Deactivate()
	//Arguments : none
	//Description : Changes mActive to false
	//Precondition : there must be an instace of the Projectile class
	//Postcondition : mActive is assigned false
	//Protection Level : public
	void Deactivate();
};