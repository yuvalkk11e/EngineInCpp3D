#pragma once
#include <iostream>
#include "Vector3.h"
class Matrix
{
private:
	float **pointer;
	int m, n;
	Matrix();

public:
	~Matrix();
	Matrix(int row, int col);
	Matrix(int row, int col, float values[]);
	static Matrix IdentityMatrix(int len);
	static Matrix ScalarMultiplication(int len, float scalar);
	float Det2();
	float Determinent();
	Matrix inverseMatrix();
	float getValue(int row, int column) const;
	void setValue(int row, int column, float value);
	void enterValues();
	void toString();
	Matrix operator + (const Matrix inMatrix) const;
	Matrix operator = (const Matrix inMatrix);
	Matrix operator * (const Matrix inMatrix) const;
	//float *operator [] (int i);
};


