#pragma once
#include <iostream>
#include "Matrix.h"
class Vector4
{
	friend class Matrix;
	friend class VertexBuffer;
	private: 
		float values[4];

	public: 
		float* GetValuesPointer();
		void SetValues(float * p);
		Vector4 operator + (Vector4 inVector);
		Vector4 operator = (Vector4 inVector);
		Vector4 operator * (Vector4 inVector);
		void toString();
		Vector4(float * p);
		Vector4(float a, float b, float c, float d);
		Vector4();
		//~Vector4();
		Vector4 operator * (const Matrix inMatrix); //multiply the ROW VECTOR v by the columns of Matrix m
};