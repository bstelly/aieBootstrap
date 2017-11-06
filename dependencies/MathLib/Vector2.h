#pragma once
#include <iostream>
#include <math.h>

using namespace std;
class Vector2
{
public:
	float mX;
	float mY;

	Vector2();
	Vector2(float x, float y);
	Vector2 operator + (Vector2 & other);
	Vector2 operator - (Vector2 & other);
	Vector2 operator * (float other);
	bool operator == (Vector2 &other);
	float Dot(Vector2 &other);
	Vector2 Normalize();
	float Magnitude();
	friend ostream& operator<<(ostream& os, const Vector2& vector);
	friend istream & operator >> (istream &in, Vector2 vector);
};