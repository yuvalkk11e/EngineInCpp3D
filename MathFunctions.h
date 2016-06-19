#pragma once
#include <math.h>
#include "Vector3.h"
#include "Matrix.h"
#include "Triangle.h"


class MathFunctions
{
public:
	static bool pointInTriangle(Vector3 p, Vector3 a, Vector3 b, Vector3 c);
	static Vector3 findNormal(Vector3 a, Vector3 b);

};

