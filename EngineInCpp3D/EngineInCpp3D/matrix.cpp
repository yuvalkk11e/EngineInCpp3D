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
	pointer = new float *[m];
	for (int i = 0; i < m; i++)
	{
		pointer[i] = new float[n];
		for (int j = 0; j < n; j++)
			pointer[i][j] = 0;
	}
}

Matrix::Matrix(int row, int col, float values[])
{
	m = row;
	n = col;
	pointer = new float *[m];
	for (int i = 0; i < m; i++)
	{
		pointer[i] = new float[n];
		for (int j = 0; j < n; j++)
		{
			pointer[i][j] = values[i*n + j];
		}
	}

}

Matrix Matrix::IdentityMatrix(int len){
	return ScalarMultiplication(len, 1);
}


Matrix Matrix::ScalarMultiplication(int len, float scalar){
	//TODO: change type of scalar to float
	Matrix I(len, len);
	for (int i = 0; i < len; i++)
		I.pointer[i][i] = scalar;
	return I;
}

float Matrix::getValue(int row, int column) const
{
	return pointer[row][column];
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
Matrix Matrix::operator + (Matrix inMatrix) const
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

Matrix Matrix::operator * (Matrix inMatrix) const
{
	//This functions assumes the matrix's columns number equals their rows.
	if (m == n && inMatrix.m == inMatrix.n)
	{
		Matrix temp(m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					temp.pointer[i][j] += pointer[i][k] * inMatrix.pointer[j][k];
			}
		}
		return temp;
	}
	//NEED TO THROW AN ERROR
	return Matrix(3, 3);
}