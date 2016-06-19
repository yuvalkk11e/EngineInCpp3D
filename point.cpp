#include "Point.h"


Point::Point()
{
}

Point::~Point()
{
	delete[] values;
	delete[] color;
}

Point::Point(float a, float b, float c)
{
	values[0] = a;
	values[1] = b;
	values[2] = c;
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
}

Point::Point(float a, float b, float c,int color1[])
{
	values[0] = a;
	values[1] = b;
	values[2] = c;
	color[0] = color1[0];
	color[1] = color1[1];
	color[2] = color1[2];
}

float* Point::getValues()
{
	return values;
}

float Point::getValue(int pos)
{
	return values[pos];
}

void Point::setValues(float value[])
{
	values[0] = value[0];
	values[1] = value[1];
	values[2] = value[2];
}

void Point::setValue(int pos, float value)
{
	values[pos] = value;
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


