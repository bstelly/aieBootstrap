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
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	PacGuy();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	bool CheckLives();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	bool CheckProjectiles();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	int NumLives();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	int NumProjectiles();
	
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
	void ChangeX(int x);
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void ChangeY(int y);
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void ChangePos(Vector2 &other);
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	Vector2 GetPos();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void AddProjectile();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SubtractProjectile();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void LoseALife();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void PickUpPellet();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	int NumPellets();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	int Facing();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void ChangeDirection(int dir);
};