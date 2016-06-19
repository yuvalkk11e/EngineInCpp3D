#include "Triangle.h"


Triangle::Triangle()
{
	values[0] = Vector3(0, 0, 0);
	values[1] = Vector3(0, 0, 0);
	values[2] = Vector3(0, 0, 0);
	normal = Vector3(0, 0, 0);
}

Triangle::Triangle(Vector3 a, Vector3 b, Vector3 c, Vector3 norm)
{
	values[0] = a;
	values[1] = b;
	values[2] = c;
	normal = norm;
}

Triangle::Triangle(Vector3 arr[], Vector3 & norm)
{
	values[0] = arr[0];
	values[1] = arr[1];
	values[2] = arr[2];
	normal = norm;
}

Triangle::Triangle(float a[], float b[], float c[], Vector3 & norm)
{
	values[0].SetValues(a);
	values[1].SetValues(b);
	values[2].SetValues(c);
	normal = norm;
}

Triangle::~Triangle()
{
	//delete[] values;
	//delete &normal;
}

void Triangle::setValues(Vector3 & a, Vector3 & b, Vector3 & c)
{
	values[0] = a;
	values[1] = b;
	values[2] = c;
}

void Triangle::setValue(int pos, Vector3 & p)
{
	values[pos] = p;
}

void Triangle::setNormal(Vector3 & v)
{
	normal = v;
}

Vector3 * Triangle::getValues()
{
	return values;
}

Vector3 Triangle::getValue(int pos)
{
	return values[pos];
}

Vector3 Triangle::getNormal()
{
	return normal;
}

bool Triangle::pointInTriangle(Vector3 & p)
{
	return MathFunctions::pointInTriangle(p, values[0], values[1], values[2]);
}

float Triangle::angleTrianglePoint(Vector3 & p)
{
	float angle;
	angle = (p*normal) / (p.length()*normal.length());
	return acos(angle);
}

Triangle Triangle::operator = (Triangle &t)
{
	for (int i = 0; i < 3; i++)
	{
		values[i] = t.values[i];
	}
	normal = t.normal;
	return *this;
}




