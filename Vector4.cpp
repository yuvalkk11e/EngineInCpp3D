#include "Vector4.h"
using namespace std;

Vector4::Vector4()
{
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	values[3] = 0;
}

Vector4::Vector4(float * p)
{
	float * ptemp = p;
	this->values[0] = *ptemp++;
	this->values[1] = *ptemp++;
	this->values[2] = *ptemp++;
	this->values[3] = *ptemp++;
}

float* Vector4::GetValuesPointer()
{ 
	return this ->values;
}

void Vector4::SetValues(float * p)
{
	float * ptemp = p;
	this->values[0] = *ptemp;
	this->values[1] = *(++ptemp);
	this->values[2] = *(++ptemp);
	this->values[3] = *(++ptemp);
}

Vector4::Vector4(float a, float b, float c, float d)
{
	this->values[0] = a;
	this->values[1] = b;
	this->values[2] = c;
	this->values[3] = d;
}
void Vector4::toString()
{
	cout << this->values[0] << " ," << this->values[1] << " ," << this->values[2] << " ," << this->values[3] << endl;
}

Vector4 Vector4::operator +(Vector4 inVector)
{
	Vector4 temp = Vector4();
	for (int i = 0; i < 4; i++)
		temp.values[i] = values[i] + inVector.values[i];

	return temp;
}

Vector4 Vector4::operator =(Vector4 inVector)
{
	values[0] = inVector.values[0];
	values[1] = inVector.values[1];
	values[2] = inVector.values[2];
	values[3] = inVector.values[3];
	return *this;
}

Vector4 Vector4::operator *(Vector4 inVector)
{
	Vector4 temp = Vector4();
	for (int i = 0; i < 4; i++)
	{
		temp.values[i] = values[i] * inVector.values[i];
	}
	return temp;
}

Vector4 Vector4::operator *(Matrix inMatrix) //multiply the ROW VECTOR v by the columns of Matrix m
{
	return Vector4(
		values[0] * inMatrix.getValue(0,0) + values[1] * inMatrix.getValue(0,1) + values[2] * inMatrix.getValue(0,2) + values[3] * inMatrix.getValue(0,3),
		values[0] * inMatrix.getValue(1,0) + values[1] * inMatrix.getValue(1,1) + values[2] * inMatrix.getValue(1,2) + values[3] * inMatrix.getValue(1,3),
		values[0] * inMatrix.getValue(2,0) + values[1] * inMatrix.getValue(2,1) + values[2] * inMatrix.getValue(2,2) + values[3] * inMatrix.getValue(2,3),
		values[0] * inMatrix.getValue(3,0) + values[1] * inMatrix.getValue(3,1) + values[2] * inMatrix.getValue(3,2) + values[3] * inMatrix.getValue(3,3)
		);
	
}