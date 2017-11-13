#pragma once
#include <iostream>
#include "Vector2.h"
using namespace std;

class Matrix2
{
public:
	float mMat[4];
	Matrix2();
	Matrix2(float mat[]);
	Matrix2(float indexA, float indexB, float indexC, float indexD);
	Matrix2 operator + (Matrix2 & other);
	Matrix2 operator - (Matrix2 & other);
	Matrix2 operator * (Matrix2 & other);
	Matrix2 RotateX(float angle);
	Matrix2 RotateY(float angle);
	Vector2 operator* (Vector2 & other);
	friend ostream& operator<<(ostream& os, Matrix2& matrix);
	friend istream& operator >> (istream &in, Matrix2 matrix);

};