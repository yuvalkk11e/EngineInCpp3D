#pragma once
#include <iostream>
#include "Matrix.h"
class Vector
{
	friend class Matrix;

	private: 
		float values[4];

	public: 
		float* GetValuesPointer();
		void SetValues(float * p);
		Vector operator + (Vector inVector);
		Vector operator = (Vector inVector);
		Vector operator * (Vector inVector);
		void toString();
		Vector(float * p);
		Vector(float a, float b, float c, float d);
		Vector();
		~Vector();
		Vector operator * (const Matrix inMatrix); //multiply the ROW VECTOR v by the columns of Matrix m
};