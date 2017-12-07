#pragma once
#include <iostream>
#include "Vector4.h"
using namespace std;

class Matrix4
{
public:
	float mMat[16];

	//Prototype : Matrix4()
	//Arguments : none
	//Description : Creates an instance of the Matrix4 class
	//Precondition : none
	//Postcondition : an instance of the Matrix4 class is created
	//Protection Level : public
	Matrix4();

	//Prototype : Matrix4(float mat[])
	//Arguments : float
	//Description : Creates an instance of the Matrix4 class
	//Precondition : none
	//Postcondition : an instance of the Matrix4 class is created
	//Protection Level : public
	Matrix4(float mat[]);

	//Prototype : float indexA, float indexB, float indexC, float indexD, float indexE,
				//float indexF, float indexG, float indexH, float indexI, float indexJ,
				//float indexK, float indexL, float indexM, float indexN, float indexO,
				//float indexP
	//Arguments : 16 floats
	//Description : Creates an instance of the Matrix4 class
	//Precondition : none
	//Postcondition : an instance of the Matrix4 class is created
	//Protection Level : public
	Matrix4(float indexA, float indexB, float indexC, float indexD, float indexE,
		float indexF, float indexG, float indexH, float indexI, float indexJ,
		float indexK, float indexL, float indexM, float indexN, float indexO,
		float indexP);

	//Prototype : Matrix4 operator + (Matrix4 & other)
	//Arguments : Matrix4
	//Description : adds two matrices together and returns the result
	//Precondition : there must be two instances of the matrix4 class 
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix4 operator + (Matrix4 & other);

	//Prototype : Matrix4 operator - (Matrix4 & other)
	//Arguments : Matrix4
	//Description : subtracts 2 instances of the matrix4 class and returns the result
	//Precondition : there must be two instances of the matrix4 class
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix4 operator - (Matrix4 & other);

	//Prototype : Matrix4 operator * (Matrix4 & other)
	//Arguments : Matrix2
	//Description : Multiplies 2 instances of the Matrix4 class and returns the result
	//Precondition : there must be two instances of the matrix4 class
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix4 operator * (Matrix4 & other);

	//Prototype : Matrix4 RotateX(float angle)
	//Arguments : float
	//Description : rotates the matrix on its x axis
	//Precondition : there must be an instance of the matrix4 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix4 RotateX(float angle);


	//Prototype : Matrix4 RotateY(float angle)
	//Arguments : float
	//Description : rotates the matrix on its y axis
	//Precondition : there must be an instance of the matrix4 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix4 RotateY(float angle);

	//Prototype : Matrix4 RotateZ(float angle)
	//Arguments : float
	//Description : rotates the matrix on its z axis
	//Precondition : there must be an instance of the matrix4 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix4 RotateZ(float angle);

	//Prototype : Vector4 operator* (Vector4 & other)
	//Arguments : Vector4
	//Description : Multiplies a matrix4 by a vector4
	//Precondition : there must be an instance of the matrix4 class
	//Postcondition : the matrix is multiplied
	//Protection Level : public
	Vector4 operator* (Vector4 & other);

	//Prototype : friend ostream& operator<<(ostream& os, Matrix4& matrix)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the matrix4 class
	//Postcondition : A matrix4 can be outputted to the console
	//Protection Level : public
	friend ostream& operator<<(ostream& os, Matrix4& matrix);

	//Prototype : friend ostream& operator<<(ostream& os, Matrix4& matrix)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the matrix4 class
	//Postcondition : A matrix4 can be outputted to the console
	//Protection Level : public
	friend istream& operator >> (istream &in, Matrix4 matrix);
};