#pragma once
#include <iostream>
#include <math.h>

using namespace std;
class Vector2
{
public:
	float mX;
	float mY;
	
	//Prototype : Vector2()
	//Arguments : none
	//Description : Creates an instance of the Vector2 class
	//Precondition : none
	//Postcondition : an instance of the Vector2 class is created
	//Protection Level : public
	Vector2();

	//Prototype : Vector2(float x, float y)
	//Arguments : 2 floats
	//Description : Creates an instance of the Vector2 class
	//Precondition : none
	//Postcondition : an instance of the Vector2 class is created
	//Protection Level : public
	Vector2(float x, float y);

	//Prototype : Vector2 operator + (Vector2 & other)
	//Arguments : Vector2
	//Description : Adds two instances of the Vector2 class together
	//Precondition : there must be two instances of the vector2 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector2 operator + (Vector2 & other);

	//Prototype : Vector2 operator - (Vector2 & other)
	//Arguments : Vector2
	//Description : Subtracts two instances of the Vector2 class
	//Precondition : there must be two instances of the vector2 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector2 operator - (Vector2 & other);

	//Prototype : Vector2 operator * (Vector2 & other)
	//Arguments : float
	//Description : multiplies two instances of the Vector2 class
	//Precondition : there must be two instances of the vector2 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector2 operator * (float other);

	//Prototype : bool operator == (Vector2 &other)
	//Arguments : Vector2
	//Description : Compares two instances of the Vector2 class
	//Precondition : there must be two instances of the vector2 class
	//Postcondition : a bool is returned
	//Protection Level : public
	bool operator == (Vector2 &other);

	//Prototype : float Dot(Vector2 &other)
	//Arguments : Vector2
	//Description : returns a float after calculating the Dot product
	//Precondition : there must be two instances of the vector2 class
	//Postcondition : the result is returned
	//Protection Level : public
	float Dot(Vector2 &other);

	//Prototype : Vector2 Normalize()
	//Arguments : none
	//Description : normalizes a vector
	//Precondition : there must be an instance of the vector2 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector2 Normalize();

	//Prototype : float Magnitude
	//Arguments : none
	//Description : returns a float after calculating magnitude
	//Precondition : there must be an instance of the vector2 class
	//Postcondition : the result is returned
	//Protection Level : public
	float Magnitude();

	//Prototype : friend istream& operator << (istream &in, Vector2 vector)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the Vector2 class
	//Postcondition : a Vector2 can be outputted to the console
	//Protection Level : public
	friend ostream& operator<<(ostream& os, const Vector2& vector);

	//Prototype : friend istream& operator >> (istream &in, Vector2 vector)
	//Arguments : none
	//Description : overloads the >> operator
	//Precondition : there must be an instance of the Vector2 class
	//Postcondition : a Vector2 can be inputted to the console
	//Protection Level : public
	friend istream & operator >> (istream &in, Vector2 vector);
};