#pragma once
#include <iostream>
#include "Matrix.h"
class Vector3
{
	friend class Matrix;
	friend class VertexBuffer;
private:
	float values[3];

public:
	float* GetValuesPointer();

	//Change all SetValues into == setValues for clarity 
	void SetValues(float * p);
	float GetValues(int pos) const;
	void SetValues(float a, float b, float c);
	void SetValue(int pos, float value);
	//void setValues(Vector3 v);

	float length() const;
	float distance(Vector3 &inVector) const;
	void toString();
	Vector3 absolute() const;
	bool equals(Vector3 &inVector) const;
	//float dotProduct(Vector3 &inVector); -- THIS FUNCTION WAS REPLACED BY THE OPERATOR * !!!
	Vector3 crossProduct (Vector3 &inVector) const;
	float angleBetween(Vector3 &inVector) const;

	Vector3 operator + (Vector3 &inVector) const;
	Vector3 operator - (Vector3 &inVector) const;
	Vector3 operator = (Vector3 &inVector);
	Vector3 operator * (Matrix &inMatrix) const;
	float operator * (Vector3 &inVector) const;
	Vector3 operator / (Vector3 &inVector) const;
	Vector3 operator * (float i) const;
	
	
	Vector3(float * p);
	Vector3(float a, float b, float c);
	Vector3();
	//~Vector3();
	
};
