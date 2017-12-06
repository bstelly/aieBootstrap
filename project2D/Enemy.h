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
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	Enemy();

	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void SetPosition(int x, int y, Vector2 velo, int speed);

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
	void ChangePos(Vector2 &other);

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
	void SetY(float Y);
	
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
	Vector2 GetPos();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void ChangeVelocity(Vector2 velo);
	
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
	Vector2 GetVelocity();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	bool Status();
	
	//Prototype :
	//Arguments : 
	//Description : 
	//Precondition : 
	//Postcondition : 
	//Protection Level : 
	void EnemyHasDied();
};