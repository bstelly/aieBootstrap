#pragma once
#include <iostream>
#include "Vector2.h"
using namespace std;

class Matrix2
{
public:
	float mMat[4];
	
	//Prototype : Matrix2()
	//Arguments : none
	//Description : Creates an instance of the Matrix2 class
	//Precondition : none
	//Postcondition : an instance of the Matrix2 class is created
	//Protection Level : public
	Matrix2();
	
	//Prototype : Matrix2(float mat[])
	//Arguments : float
	//Description : Creates an instance of the Matrix2 class
	//Precondition : none
	//Postcondition : an instance of the Matrix2 class is created
	//Protection Level : public
	Matrix2(float mat[]);
	
	//Prototype : Matrix2(float indexA, float indexB, float indexC, float indexD)
	//Arguments : 4 floats
	//Description : creates an instance of the matrix2 class
	//Precondition : none
	//Postcondition : an instance of the matrix2 class is created
	//Protection Level : public
	Matrix2(float indexA, float indexB, float indexC, float indexD);
	
	//Prototype : Matrix2 operator + (Matrix2 & other)
	//Arguments : Matrix2
	//Description : adds two matrices together and returns the result
	//Precondition : there must be two instances of the matrix2 class 
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix2 operator + (Matrix2 & other);
	
	//Prototype : Matrix2 operator - (Matrix2 & other)
	//Arguments : Matrix2
	//Description : subtracts 2 instances of the matrix2 class and returns the result
	//Precondition : there must be two instances of the matrix2 class
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix2 operator - (Matrix2 & other);
	
	//Prototype : Matrix2 operator * (Matrix2 & other)
	//Arguments : Matrix2
	//Description : Multiplies 2 instances of the Matrix2 class and returns the result
	//Precondition : there must be two instances of the matrix2 class
	//Postcondition : the result is returned
	//Protection Level : public
	Matrix2 operator * (Matrix2 & other);
	
	//Prototype : Matrix2 RotateX(float angle)
	//Arguments : float
	//Description : rotates the matrix on its x axis
	//Precondition : there must be an instance of the matrix2 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix2 RotateX(float angle);
	
	//Prototype : Matrix2 RotateY(float angle)
	//Arguments : float
	//Description : rotates the matrix on its y axis
	//Precondition : there must be an instance of the matrix2 class
	//Postcondition : the matrix is rotated
	//Protection Level : public
	Matrix2 RotateY(float angle);
	
	//Prototype : Vector2 operator* (Vector2 & other)
	//Arguments : Vector2
	//Description : Multiplies a matrix2 by a vector2
	//Precondition : there must be an instance of the matrix2 class
	//Postcondition : the matrix is multiplied
	//Protection Level : public
	Vector2 operator* (Vector2 & other);
	
	//Prototype : friend ostream& operator<<(ostream& os, Matrix2& matrix)
	//Arguments : none
	//Description : overloads the << operator
	//Precondition : there must be an instance of the matrix2 class
	//Postcondition : A matrix2 can be outputted to the console
	//Protection Level : public
	friend ostream& operator<<(ostream& os, Matrix2& matrix);
	
	//Prototype : friend istream& operator >> (istream &in, Matrix2 matrix)
	//Arguments : none
	//Description : overloads the >> operator
	//Precondition : there must be an instance of the matrix2 class
	//Postcondition : a matrix2 can be inputted to the console
	//Protection Level : public
	friend istream& operator >> (istream &in, Matrix2 matrix);

};