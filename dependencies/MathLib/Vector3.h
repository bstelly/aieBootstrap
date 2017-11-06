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

	Vector3();
	Vector3(float x, float y, float z);
	Vector3 operator + (Vector3 & other);
	Vector3 operator - (Vector3 & other);
	Vector3 operator * (float other);
	bool operator == (Vector3 & other);
	float Dot(Vector3 & other);
	Vector3 Cross(Vector3 & other);
	Vector3 Normalize();
	float Magnitude();
	friend ostream& operator << (ostream& os, const Vector3& vector);
	friend istream & operator >> (istream &in, Vector3 vector);

};