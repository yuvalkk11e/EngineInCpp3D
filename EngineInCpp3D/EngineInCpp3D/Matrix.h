#pragma once
#include <iostream>
#include "Vector.h"
class Matrix
{
private:
	int **pointer, m, n;
	Matrix();

public:
	~Matrix();
	Matrix(int row, int col);
	Matrix(int row, int col, int values[]);
	static Matrix IdentityMatrix(int len);
	static Matrix ScalarMultiplication(int len, int scalar);

	void enterValues();
	void toString();
	Matrix operator + (Matrix inMatrix);
	Matrix operator = (Matrix inMatrix);
	Matrix operator * (const Matrix inMatrix);
//	Vector operator * (const Vector inVector);
	int *operator [] (int i);
};


