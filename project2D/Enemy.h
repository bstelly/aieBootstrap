#pragma once
#include <Vector2.h>

class Enemy
{
private:
	Vector2* mPosition;
	Vector2* mVelocity; //Direction enemy is moving
	int mSpeed;
	bool mIsDead;

public:
	//Prototype : Enemy()
	//Arguments : none
	//Description : Creates a default instance of the enemy class
	//Precondition : none
	//Postcondition : An instance of the enemy class is created
	//Protection Level : public
	Enemy();

	//Prototype : void SetPosition(int x, int y, Vector2 velo, int speed);
	//Arguments : three intetergers and a Vector2
	//Description : Sets the position of an enemy object
	//Precondition : There must be an instance of the enemy class
	//Postcondition : An object of type enemy has a set position
	//Protection Level : public
	void SetPosition(int x, int y, Vector2 velo, int speed);

	//Prototype : float GetX()
	//Arguments : none
	//Description : returns the 'x' value of an object of type enemy
	//Precondition : there must be an instance of the enemy class
	//Postcondition : an object of type enemy's x value is returned
	//Protection Level : public
	float GetX();

	//Prototype : float GetY()
	//Arguments : none
	//Description : returns the 'y' value of an object of type enemy
	//Precondition : there must be an instance of the enemy class
	//Postcondition : an object of type enemy's y value is returned
	//Protection Level : public
	float GetY();

	//Prototype : void ChangePos(Vector2 &other)
	//Arguments : A Vector2
	//Description : Changes the position of an enemy object
	//Precondition : there must be an instance of the enemy class
	//Postcondition : An object of type enemy has a changed position
	//Protection Level : public
	void ChangePos(Vector2 &other);
	
	//Prototype : void ChangeVelocity(Vector2 velo)
	//Arguments : a Vector2
	//Description : Changes the velocity of an object of type enemy
	//Precondition : there must be an instance of the enemy class
	//Postcondition : An object of type enemy has a new velocity
	//Protection Level : 
	void ChangeVelocity(Vector2 velo);
	
	//Prototype : void Move()
	//Arguments : none
	//Description : moves an object of type enemy to a new position
	//Precondition : there must be an instance of the enemy class
	//Postcondition : an object of type enemy has a new position
	//Protection Level : public
	void Move();
	
	//Prototype : Vector2 GetVelocity();
	//Arguments : none
	//Description : Returns a Vector2
	//Precondition : there must be an instance of the enemy class
	//Postcondition : A Vector2 is returned
	//Protection Level : public
	Vector2 GetVelocity();
	
	//Prototype : bool Status();
	//Arguments : none
	//Description : returns a boolean
	//Precondition : there must be an instance of the enemy class
	//Postcondition : true or false is returned
	//Protection Level : public
	bool Status();
	
	//Prototype : void EnemyHasDied();
	//Arguments : none
	//Description : changes the the value of mIsDead for an enemy object
	//Precondition : there must be an instance of the enemy class
	//Postcondition : an enemy object's mIsDead member variable is now true
	//Protection Level : public
	void EnemyHasDied();
};