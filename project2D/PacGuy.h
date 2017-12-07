#pragma once
#include <Vector2.h>

class PacGuy
{
private:
	Vector2* mPosition;
	int mLives;
	int mProjectiles;
	int mPellets;
	int mFacing; //1 is right, 2 is left, 3 is up, 4 is down
public:
	//Prototype : PacGuy()
	//Arguments : none 
	//Description : creates an instace of the PacGuy class
	//Precondition : none
	//Postcondition : an instance of the PacGuy class is created
	//Protection Level : public
	PacGuy();
	
	//Prototype : bool CheckLives()
	//Arguments : none
	//Description : returns a boolean value
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : a boolean is returned
	//Protection Level : public
	bool CheckLives();
	
	//Prototype : bool CheckProjectiles()
	//Arguments : none
	//Description : returns a boolean value
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : a boolean value is returned
	//Protection Level : public
	bool CheckProjectiles();
	
	//Prototype : int NumLives()
	//Arguments : none
	//Description : returns the number of lives
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the number of lives is returned
	//Protection Level : public 
	int NumLives();
	
	//Prototype : int NumProjectiles()
	//Arguments : none
	//Description : returns the number of projectiles
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the number of projectiles is returned
	//Protection Level : public
	int NumProjectiles();
	
	//Prototype : float GetX()
	//Arguments : none
	//Description : returns a float
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the x value is retuned
	//Protection Level : public 
	float GetX();
	
	//Prototype : float GetY()
	//Arguments : none
	//Description : returns a float
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the y value is returned
	//Protection Level : public
	float GetY();
	
	//Prototype : void ChangeX(int x)
	//Arguments : an interger
	//Description : changes the x value
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the x value is changed
	//Protection Level : public
	void ChangeX(int x);
	
	//Prototype : void ChangeY(int y)
	//Arguments : an interger
	//Description : Changes the y value
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the y value is changed
	//Protection Level : public
	void ChangeY(int y);
	
	//Prototype : void ChangePos(Vector2 &other)
	//Arguments : a Vector2
	//Description : changes the position for a PacGuy object
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : a PacGuy object's position is changed
	//Protection Level : public
	void ChangePos(Vector2 &other);
	
	//Prototype : Vector2 GetPos()
	//Arguments : a Vector2
	//Description : returns a Vector2
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : a Vector2 is returned
	//Protection Level : public
	Vector2 GetPos();
	
	//Prototype : void AddProjectile()
	//Arguments : none
	//Description : Adds 1 to the number of mProjectiles
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : there is +1 to the total of mProjectiles
	//Protection Level : public
	void AddProjectile();
	
	//Prototype : void SubtractProjectile()
	//Arguments : none
	//Description : Subtracts 1 from the total number of mProjectiles
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : mProjectiles now has one less
	//Protection Level : public
	void SubtractProjectile();
	
	//Prototype : void LoseALife()
	//Arguments : none
	//Description : subtracts 1 from mLives
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : mLives is one less
	//Protection Level : public
	void LoseALife();
	
	//Prototype : void PickUpPellet()
	//Arguments : none
	//Description : adds 1 to the number of mPellets
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : mPellets now has 1 more
	//Protection Level : public 
	void PickUpPellet();
	
	//Prototype : int NumPellets()
	//Arguments : none
	//Description : returns the number of mPellets
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : the number of mPellets is returned
	//Protection Level : public
	int NumPellets();
	
	//Prototype : int Facing()
	//Arguments : none
	//Description : returns an interger that corresponds with a direction
	//Precondition : there must be an instance of the PacGuy class
	//Postcondition : an interger is returned
	//Protection Level : public
	int Facing();
	
	//Prototype : void ChangeDirection(int dir)
	//Arguments : an interger
	//Description : changes the value of mFacing
	//Precondition :there must be an instance of the PacGuy class 
	//Postcondition : mFacing is now assigned a new interger
	//Protection Level : public
	void ChangeDirection(int dir);
};