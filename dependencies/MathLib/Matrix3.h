#pragma once
#include "Vector3.h"
#include <iostream>
using namespace std;

class Matrix3
{
public:
	
	float mMat[9];
	
	//Prototype : Matrix3()
	//Arguments : none
	//Description : Creates an instance of the Matrix3 class
	//Precondition : none
	//Postcondition : an instance of the Matrix3 class is created
	//Protection Level : public
	Matrix3();
	
	//Prototype : Matrix3(float mat[])
	//Arguments : float
	//Description : Creates an instance of the Matrix3 class
	//Precondition : none
	//Postcondition : an instance of the Matrix3 class is created
	//Protection Level : public
	Matrix3(float mat[]);
	
	//Prototype : Matrix3(float indexA, float indexB, float indexC, float indexD, float indexE,
				//float indexF, float indexG, float indexH, float indexI);
	//Arguments : 9 floats
	//Description : Creates an instance of the Matrix3 class
	//Precondition : none
	//Postcondition : an instance of teh Matrix3 class is created
	//Protection Level : public
	Matrix3(float indexA, float indexB, float indexC, float indexD, float indexE,
		float indexF, float indexG, float indexH, float indexI);

	//Prototype : Matrix3 operator + (Matrix3 & other)
	//Arguments : Matrix3
	//Description : adds two matrix3 together and returns the result
	//Precondition : there must be two instances of the matrix3 class 
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix3 operator + (Matrix3 & other);

	//Prototype : Matrix3 operator - (Matrix3 & other)
	//Arguments : Matrix3
	//Description : subtracts 2 instances of the matrix3 class and returns the result
	//Precondition : there must be two instances of the matrix3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix3 operator - (Matrix3 & other);

	//Prototype : Matrix3 operator * (Matrix3 & other)
	//Arguments : Matrix3
	//Description : Multiplies 2 instances of the Matrix3 class and returns the result
	//Precondition : there must be two instances of the matrix3 class
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix3 operator * (Matrix3 & other);

	//Prototype : Matrix3 RotateX(float angle)
	//Arguments : float
	//Description : rotates the matrix on its x axis
	//Precondition : there must be an instance of the matrix3 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix3 RotateX(float angle);

	//Prototype : Matrix3 RotateY(float angle)
	//Arguments : float
	//Description : rotates the matrix on its y axis
	//Precondition : there must be an instance of the matrix3 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix3 RotateY(float angle);

	//Prototype : Matrix3 RotateZ(float angle)
	//Arguments : float
	//Description : rotates the matrix on its z axis
	//Precondition : there must be an instance of the matrix3 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix3 RotateZ(float angle);

	//Prototype : Vector3 operator* (Vector3 & other)
	//Arguments : Vector3
	//Description : Multiplies a matrix3 by a vector3
	//Precondition : there must be an instance of the matrix3 class
	//Postcondition : the matrix is multiplied
	//Protection Level : public
	Vector3 operator* (Vector3 & other);

	//Prototype : friend ostream& operator<<(ostream& os, Matrix3& matrix)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the matrix3 class
	//Postcondition : A matrix3 can be outputted to the console
	//Protection Level : public
	friend ostream& operator<<(ostream& os, Matrix3& matrix);

	//Prototype : friend istream& operator >> (istream &in, Matrix3 matrix)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the matrix3 class
	//Postcondition : A matrix3 can be outputted to the console
	//Protection Level : public
	friend istream& operator >> (istream &in, Matrix3 matrix);
};