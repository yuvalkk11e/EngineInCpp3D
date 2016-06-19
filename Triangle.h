#pragma once
#include "Vector3.h"
#include "MathFunctions.h"
class Triangle
{
private:
	Vector3 values[3];
	Vector3 normal;

public:
	Triangle();
	Triangle(Vector3 a, Vector3 b, Vector3 c, Vector3 norm);
	Triangle(Vector3 arr[], Vector3 &norm);
	Triangle(float a[], float b[], float c[], Vector3 &norm);
	~Triangle();

	void setValues(Vector3 &a, Vector3 &b, Vector3 &c);
	void setValue(int pos, Vector3 &p);
	void setNormal(Vector3 &v);
	Vector3* getValues();
	Vector3 getValue(int pos);
	Vector3 getNormal();

	bool pointInTriangle(Vector3 &p);
	float angleTrianglePoint(Vector3 &p);

	Triangle operator = (Triangle &t);

	//
	
};