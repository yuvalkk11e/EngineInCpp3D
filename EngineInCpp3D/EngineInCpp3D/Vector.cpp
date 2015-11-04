#include "Vector.h"
using namespace std;

Vector::Vector()
{
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	values[3] = 0;
}

Vector::~Vector()
{
}
Vector::Vector(float * p)
{
	float * ptemp = p;
	this->values[0] = *ptemp++;
	this->values[1] = *ptemp++;
	this->values[2] = *ptemp++;
	this->values[3] = *ptemp++;
}

float* Vector::GetValuesPointer()
{ 
	return this ->values;
}

void Vector::SetValues(float * p)
{
	float * ptemp = p;
	this->values[0] = *ptemp;
	this->values[1] = *(++ptemp);
	this->values[2] = *(++ptemp);
	this->values[3] = *(++ptemp);
}

Vector::Vector(float a, float b, float c, float d)
{
	this->values[0] = a;
	this->values[1] = b;
	this->values[2] = c;
	this->values[3] = d;
}
void Vector::toString()
{
	cout << this->values[0] << " ," << this->values[1] << " ," << this->values[2] << " ," << this->values[3] << endl;
}

Vector Vector::operator +(Vector inVector)
{
	Vector temp(0,0,0,0);
	for (int i = 0; i < 4; i++)
		temp.values[i] = values[i] + inVector.values[i];

	return temp;
}

Vector Vector::operator =(Vector inVector)
{
	values[0] = inVector.values[0];
	values[1] = inVector.values[1];
	values[2] = inVector.values[2];
	values[3] = inVector.values[3];
	return *this;
}

Vector Vector::operator *(Vector inVector)
{
	Vector temp(0,0,0,0);
	for (int i = 0; i < 4; i++)
	{
		temp.values[i] = values[i] * inVector.values[i];
	}
	return temp;
}

Vector Vector::operator *(Matrix inMatrix) //multiply the ROW VECTOR v by the columns of Matrix m
{
	return Vector(
		values[0] * inMatrix[0][0] + values[1] * inMatrix[0][1] + values[2] * inMatrix[0][2] + values[3] * inMatrix[0][3],
		values[0] * inMatrix[1][0] + values[1] * inMatrix[1][1] + values[2] * inMatrix[1][2] + values[3] * inMatrix[1][3],
		values[0] * inMatrix[2][0] + values[1] * inMatrix[2][1] + values[2] * inMatrix[2][2] + values[3] * inMatrix[2][3],
		values[0] * inMatrix[3][0] + values[1] * inMatrix[3][1] + values[2] * inMatrix[3][2] + values[3] * inMatrix[3][3]
		);
	
}