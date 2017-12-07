#pragma once
#include <math.h>
#include <iostream>
using namespace std;
class Vector3
{
public:
	float mX;
	float mY;
	float mZ;

	//Prototype : Vector3()
	//Arguments : none
	//Description : Creates an instance of the Vector3 class
	//Precondition : none
	//Postcondition : an instance of the Vector3 class is created
	//Protection Level : public
	Vector3();
	
	//Prototype : Vector3(float x, float y, float z)
	//Arguments : 3 floats
	//Description : Creates an instance of the Vector3 class
	//Precondition : none
	//Postcondition : an instance of the Vector3 class is created
	//Protection Level : public
	Vector3(float x, float y, float z);
	
	//Prototype : Vector3 operator + (Vector3 & other)
	//Arguments : Vector3
	//Description : Adds two instances of the Vector3 class together
	//Precondition : there must be two instances of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector3 operator + (Vector3 & other);
	
	//Prototype : Vector3 operator - (Vector3 & other)
	//Arguments : Vector3
	//Description : Subtracts two instances of the Vector3 class
	//Precondition : there must be two instances of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector3 operator - (Vector3 & other);
	
	//Prototype : Vector3 operator * (Vector3 & other)
	//Arguments : float
	//Description : multiplies two instances of the Vector3 class
	//Precondition : there must be two instances of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector3 operator * (float other);
	
	//Prototype : bool operator == (Vector3 &other)
	//Arguments : Vector3
	//Description : Compares two instances of the Vector3 class
	//Precondition : there must be two instances of the vector3 class
	//Postcondition : a bool is returned
	//Protection Level : public
	bool operator == (Vector3 & other);
	
	//Prototype : float Dot(Vector3 &other)
	//Arguments : Vector3
	//Description : returns a float after calculating the Dot product
	//Precondition : there must be two instances of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	float Dot(Vector3 & other);
	
	//Prototype : Vector3 Cross(Vector3 & other)
	//Arguments : Vector3
	//Description : returns a Vector3 after calculating the Cross product
	//Precondition : there must be two instances of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector3 Cross(Vector3 & other);
	
	//Prototype : Vector3 Normalize()
	//Arguments : none
	//Description : normalizes a vector
	//Precondition : there must be an instance of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector3 Normalize();
	
	//Prototype : float Magnitude
	//Arguments : none
	//Description : returns a float after calculating magnitude
	//Precondition : there must be an instance of the vector3 class
	//Postcondition : the result is returned
	//Protection Level : public
	float Magnitude();
	
	//Prototype : friend istream& operator << (istream &in, Vector3 vector)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the Vector3 class
	//Postcondition : a Vector3 can be outputted to the console
	//Protection Level : public
	friend ostream& operator << (ostream& os, const Vector3& vector);
	
	//Prototype : friend istream& operator >> (istream &in, Vector3 vector)
	//Arguments : none
	//Description : overloads the >> operator
	//Precondition : there must be an instance of the Vector3 class
	//Postcondition : a Vector3 can be inputted to the console
	//Protection Level : public
	friend istream & operator >> (istream &in, Vector3 vector);

};