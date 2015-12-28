#include "Vector3.h"
using namespace std;

Vector3::Vector3()
{
	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
}

Vector3::Vector3(float * p)
{
	float * ptemp = p;
	this->values[0] = *ptemp++;
	this->values[1] = *ptemp++;
	this->values[2] = *ptemp++;
}

Vector3::Vector3(float a, float b, float c)
{
	this->values[0] = a;
	this->values[1] = b;
	this->values[2] = c;
}

float* Vector3::GetValuesPointer()
{
	return this->values;
}

void Vector3::SetValues(float * p)
{
	values[0] = *p;
	values[1] = *(++p);
	values[2] = *(++p);
}
void Vector3::SetValues(float a, float b, float c)
{
	values[0] = a;
	values[1] = b;
	values[2] = c;
}
float Vector3::GetValues(int pos) const
{
	return values[pos];
}
void Vector3::SetValue(int pos,float value )
{
	values[pos] = value;
}

void Vector3::toString()
{
	cout << this->values[0] << " ," << this->values[1] << " ," << this->values[2] << endl;
}

bool Vector3::equals(Vector3 &inVector) const
{
	if (values[0] == inVector.GetValues(0) && values[1] == inVector.GetValues(1) && values[2] == inVector.GetValues(2))
		return true;
	return false;
}

Vector3 Vector3::operator +(Vector3 &inVector) const
{
	Vector3 temp = Vector3();
	for (int i = 0; i < 3; i++)
		temp.values[i] = values[i] + inVector.values[i];

	return temp;
}

Vector3 Vector3::operator -(Vector3 &inVector) const
{
	Vector3 temp = Vector3();
	for (int i = 0; i < 3; i++)
		temp.values[i] = values[i] - inVector.values[i];

	return temp;
}

Vector3 Vector3::operator /(Vector3 &inVector) const
{
	Vector3 temp = Vector3();
	for (int i = 0; i < 3; i++)
	{
		temp.values[i] = values[i] / inVector.values[i];
	}
	return temp;
}

Vector3 Vector3::operator =(Vector3 &inVector)
{
	values[0] = inVector.values[0];
	values[1] = inVector.values[1];
	values[2] = inVector.values[2];
	return *this;
}

float Vector3::operator *(Vector3 &inVector) const
{
	float result = 0;
	for (int i = 0; i < 3; i++)
	{
		result += values[i] * inVector.values[i];
	}
	return result;
}

Vector3 Vector3::operator *(Matrix &inMatrix) const //multiply the ROW VECTOR v by the columns of Matrix m
{
	Vector3 temp(0, 0, 0);
	temp.values[0] = values[0] * inMatrix.getValue(0, 0) + values[1] * inMatrix.getValue(1, 0) + values[2] * inMatrix.getValue(2, 0);
	temp.values[1] = values[0] * inMatrix.getValue(0, 1) + values[1] * inMatrix.getValue(1, 1) + values[2] * inMatrix.getValue(2, 1);
	temp.values[2] = values[0] * inMatrix.getValue(0, 2) + values[1] * inMatrix.getValue(1, 2) + values[2] * inMatrix.getValue(2, 2);
	return temp;
}
Vector3 Vector3::operator *(float i) const
{
	Vector3 temp = Vector3();
	for (int j = 0; j < 3; j++)
	{
		temp.values[j] = values[j] * i;
	}
	return temp;
}

float Vector3::distance(Vector3 &inVector) const
{
	return inVector.length() - (*this).length();
}

float Vector3::length() const
{
	return sqrt(values[0] * values[0] + values[1] * values[1] + values[2] * values[2]);
}

Vector3 Vector3::crossProduct(Vector3 &inVector) const
{
	Vector3 temp = Vector3();
	temp.values[0] = values[1] * inVector.values[2] - values[2] * inVector.values[1];
	temp.values[1] = values[2] * inVector.values[0] - values[0] * inVector.values[2];
	temp.values[2] = values[0] * inVector.values[1] - values[1] * inVector.values[0];
	return temp;
}

Vector3 Vector3::absolute() const
{
	Vector3 temp(0, 0, 0);
	temp.values[0] = abs(values[0]);
	temp.values[1] = abs(values[1]);
	temp.values[2] = abs(values[2]);
	return temp;
}
