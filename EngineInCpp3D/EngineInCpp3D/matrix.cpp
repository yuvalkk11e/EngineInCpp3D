using namespace std;
#include "Matrix.h"


Matrix::~Matrix()
{
	//for (int i = 0; i < m; i++)
	//{
	//delete pointer[i];
	//}
	//delete pointer;
}
Matrix::Matrix(int row, int col)
{
	m = row;
	n = col;
	pointer = new int *[m];
	for (int i = 0; i < m; i++)
	{
		pointer[i] = new int[n];
	}
}

Matrix::Matrix(int row, int col, int values[])
{
	m = row;
	n = col;
	pointer = new int *[m];
	for (int i = 0; i < m; i++)
	{
		pointer[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			pointer[i][j] = values[i*n + j];
		}
	}

}
int* Matrix:: operator [](int key)
{
	return pointer[key];
}

Matrix Matrix::IdentityMatrix(int len){
	return ScalarMultiplication(len, 1);
}


Matrix Matrix::ScalarMultiplication(int len, int scalar){
	//TODO: change type of scalar to float
	Matrix I(len, len);
	for (int i = 0; i < len; i++) I[len][len] = scalar;
	return I;
}

void Matrix::enterValues()
{
	cout << " enter values for Matrix :" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> pointer[i][j];
		}
	}
}
void Matrix::toString()
{
	cout << " Matrix values are : " << endl;
	for (int i = 0; i < m; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << pointer[j][i] << " , ";
		}
	}
}
Matrix Matrix::operator + (Matrix inMatrix)
{
	Matrix temp(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.pointer[i][j] = pointer[i][j] + inMatrix.pointer[i][j];
		}
	}
	return temp;
}
Matrix Matrix::operator = (Matrix inMatrix)
{
	m = inMatrix.m;
	n = inMatrix.n;
	pointer = inMatrix.pointer;
	return *this;
}

Matrix Matrix::operator * (Matrix inMatrix)
{
	//Assuming next Matrix is a nx1 Matrix (inMatrix rows = opmatrix columns) Then :
	Matrix temp(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp.pointer[i][j] = pointer[i][j] * inMatrix.pointer[0][i];
		}
	}
	//Otherwise this would only multiply the first column Vector times opmatrix. 
	return temp;
}

//MATRIX.CPP VERSION1