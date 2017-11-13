#pragma once
#include "Vector3.h"
#include <iostream>
using namespace std;

class Matrix3
{
public:
	float mMat[9];
	Matrix3();
	Matrix3(float mat[]);
	Matrix3(float indexA, float indexB, float indexC, float indexD, float indexE,
		float indexF, float indexG, float indexH, float indexI);
	Matrix3 operator + (Matrix3 & other);
	Matrix3 operator - (Matrix3 & other);
	Matrix3 operator * (Matrix3 & other);
	Matrix3 RotateX(float angle);
	Matrix3 RotateY(float angle);
	Matrix3 RotateZ(float angle);
	Vector3 operator* (Vector3 & other);
	friend ostream& operator<<(ostream& os, Matrix3& matrix);
	friend istream& operator >> (istream &in, Matrix3 matrix);
};