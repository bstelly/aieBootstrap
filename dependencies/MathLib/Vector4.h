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

	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4 operator + (Vector4 & other);
	Vector4 operator - (Vector4 & other);
	Vector4 operator * (float other);
	bool operator == (Vector4 & other);
	float Dot(Vector4 & other);
	Vector4 Normalize();
	float Magnitude();
	friend ostream& operator<<(ostream& os, const Vector4& vector);
	friend istream & operator >> (istream &in, Vector4 vector);

};
