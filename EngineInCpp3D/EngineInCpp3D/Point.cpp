#include "Point.h"


Point::Point()
{
}

Point::Point(float a, float b, float c)
{
	this->values[0] = a;
	this->values[1] = b;
	this->values[2] = c;
	this->color = RGB(0, 0, 0);
}

Point::Point(float a, float b, float c,COLORREF color)
{
	this->values[0] = a;
	this->values[1] = b;
	this->values[2] = c;
	this->color = color;
}

Point Point::operator +(Point inpoint)
{
	Point temp(0, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		temp.values[i] = values[i] + inpoint.values[i];
	}
	return temp;
}

Point Point::operator -(Point inpoint)
{
	Point temp(0, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		temp.values[i] = values[i] - inpoint.values[i];
	}
	return temp;
}

Point Point::operator *(Point inpoint)
{
	Point temp(0, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		temp.values[i] = values[i] * inpoint.values[i];
	}
	return temp;
}

Point Point::operator =(Point inpoint)
{
	for (int i = 0; i < 3; i++)
	{
		values[i] =  inpoint.values[i];
	}
	return *this;
}

Point::~Point()
{
}


