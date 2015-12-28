#include "TransformationMatrixes.h"
#include <math.h>

#define PI 3.14159265
#define PIr (PI/180)
Matrix TransformationMatrixes::rotationMatrix(double xangle, double yangle, double zangle)
{
	Matrix m = Matrix::IdentityMatrix(3);
	if (xangle != 0)
	{
		Matrix x2(3, 3, new float[9]{ 1, 0, 0, 0, float(cos(xangle*PIr)), float(sin(xangle*PIr)), 0, float(-sin(xangle*PIr)), float(cos(xangle*PIr)) });
		m = m*x2;
	}
	if (yangle != 0)
	{
		Matrix y2(3, 3, new float[9]{float(cos(yangle*PIr)), 0, float(-sin(yangle*PIr)), 0, 1, 0, float(sin(yangle*PIr)), 0, float(cos(yangle*PIr))});
		m = m*y2;
	}
	if (zangle != 0)
	{
		Matrix z2(3, 3, new float[9] {float(cos(zangle*PIr)), float(sin(zangle*PIr)), 0, float(-sin(zangle*PIr)), float(cos(zangle*PIr)), 0, 0, 0, 1});
		m = m*z2;
	}
		
	return m;
	
}

void TransformationMatrixes::test(){
	std::cout << 1;
}