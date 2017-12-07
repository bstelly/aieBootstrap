#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Vector4
{
public:
	float mX;
	float mY;
	float mZ;
	float mW;

	//Prototype : Vector4()
	//Arguments : none
	//Description : Creates an instance of the Vector4 class
	//Precondition : none
	//Postcondition : an instance of the Vector4 class is created
	//Protection Level : public
	Vector4();
	
	//Prototype : Vector4(float x, float y, float z, float w)
	//Arguments : 4 floats
	//Description : Creates an instance of the Vector4 class
	//Precondition : none
	//Postcondition : an instance of the Vector4 class is created
	//Protection Level : public
	Vector4(float x, float y, float z, float w);
	
	//Prototype : Vector4 operator + (Vector4 & other)
	//Arguments : Vector4
	//Description : Adds two instances of the Vector4 class together
	//Precondition : there must be two instances of the vector4 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector4 operator + (Vector4 & other);
	
	//Prototype : Vector4 operator - (Vector4 & other)
	//Arguments : Vector4
	//Description : Subtracts two instances of the Vector4 class
	//Precondition : there must be two instances of the vector4 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector4 operator - (Vector4 & other);
	
	//Prototype : Vector4 operator * (Vector4 & other)
	//Arguments : float
	//Description : multiplies two instances of the Vector4 class
	//Precondition : there must be two instances of the vector4 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector4 operator * (float other);
	
	//Prototype : bool operator == (Vector4 &other)
	//Arguments : Vector4
	//Description : Compares two instances of the Vector4 class
	//Precondition : there must be two instances of the vector4 class
	//Postcondition : a bool is returned
	//Protection Level : public
	bool operator == (Vector4 & other);
	
	//Prototype : float Dot(Vector4 &other)
	//Arguments : Vector4
	//Description : returns a float after calculating the Dot product
	//Precondition : there must be two instances of the vector4 class
	//Postcondition : the result is returned
	//Protection Level : public
	float Dot(Vector4 & other);
	
	//Prototype : Vector4 Normalize()
	//Arguments : none
	//Description : normalizes a vector
	//Precondition : there must be an instance of the vector4 class
	//Postcondition : the result is returned
	//Protection Level : public
	Vector4 Normalize();
	
	//Prototype : float Magnitude
	//Arguments : none
	//Description : returns a float after calculating magnitude
	//Precondition : there must be an instance of the vector4 class
	//Postcondition : the result is returned
	//Protection Level : public
	float Magnitude();
	
	//Prototype : friend istream& operator << (istream &in, Vector4 vector)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the Vector4 class
	//Postcondition : a Vector4 can be outputted to the console
	//Protection Level : public
	friend ostream& operator<<(ostream& os, const Vector4& vector);
	
	//Prototype : friend istream& operator >> (istream &in, Vector4 vector)
	//Arguments : none
	//Description : overloads the >> operator
	//Precondition : there must be an instance of the Vector4 class
	//Postcondition : a Vector4 can be inputted to the console
	//Protection Level : public
	friend istream & operator >> (istream &in, Vector4 vector);

};
