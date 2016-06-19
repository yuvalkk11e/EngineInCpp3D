#include "MathFunctions.h"


bool MathFunctions::pointInTriangle(Vector3 p, Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 ba = b - a;
	Vector3 ca = c - a;
	Vector3 pa = p - a;

	float u = ((ba*ba)*(pa*ca) - (ba*ca)*(pa*ba)) / ((ca*ca)*(ba*ba) - (ca*ba)*(ba*ca));
	float v = ((ca*ca)*(pa*ba) - (ca*ba)*(pa*ca)) / ((ca*ca)*(ba*ba) - (ca*ba)*(ba*ca));	//float div = ((ca*ca)*(ba*ba) - (ca*ba)*(ba*ca));

	if (u > 0 && v > 0 && u + v < 1)
		return true;
	return false; 	
}

//Vector3 MathFunctions::findNormal(Triangle t)
//{
	//return t.getValue(0).crossProduct(t.getValue(1));
//}

Vector3 MathFunctions::findNormal(Vector3 a, Vector3 b)
{
	return a.crossProduct(b);
}
