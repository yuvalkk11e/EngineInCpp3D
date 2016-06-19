#include "FaceBuffer.h"


FaceBuffer::FaceBuffer()
{
	values = new Triangle[0];
	size = 0;
	taken = 0;
}

FaceBuffer::FaceBuffer(int size1)
{
	size = size1;
	values = new Triangle[size];
	for (int i = 0; i < size; i++)
	{
		values[i] = Triangle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0));
	}
	taken = 0;
}

FaceBuffer::FaceBuffer(int size1, int taken1, Triangle * triangles)
{
	size = size1;
	values = triangles;
	taken = taken1;
}

FaceBuffer::~FaceBuffer()
{
	//delete[] values;
	//delete &size;
	//delete &taken;
}

void FaceBuffer::setValues(Triangle * ptr,int stopAt)
{
	for (int i = 0; i < stopAt; i++)
	{
		//assyme place was allready filled with info.
		values[i] = ptr[i];
	}
	taken += stopAt;
}

void FaceBuffer::setValue(int pos, Triangle &t)
{
	//assume place was already filled with info.
	values[pos] = t;
}

void FaceBuffer::setSize(int size1)
{
	size = size1;
	FaceBuffer copy = *this;
	values = new Triangle[size];
	for (int i = 0; i < size; i++)
	{
		values[i] = copy.getValue(i);
	}
	
}

void FaceBuffer::setTaken(int t)
{
	taken = t;
}

Triangle FaceBuffer::getValue(int pos)
{
	return values[pos];
}

Triangle* FaceBuffer::getValues()
{
	return values;
}

int FaceBuffer::getSize()
{
	return size;
}

int FaceBuffer::getTaken()
{
	return taken;
}

void FaceBuffer::increaseSize(int s)
{
	size += s;
}

void FaceBuffer::increaseTaken(int t)
{
	taken += t;
}

bool FaceBuffer::addTriangle(Triangle &t)
{
	if (taken < size)
	{
		values[taken] = t;
		taken += 1;
		return true;
	}
	return false;
}

void FaceBuffer::createCube(float sizein, Vector3 &center, int bufferPos)
{
	float tsize = sizein / 2;
	Vector3 TLF = Vector3(-tsize, +tsize, -tsize) + center;
	Vector3 TRF = Vector3(+tsize, +tsize, -tsize) + center;
	Vector3 BLF = Vector3(-tsize, -tsize, -tsize) + center;
	Vector3 BRF = Vector3(+tsize, -tsize, -tsize) + center;
	Vector3 TLB = Vector3(-tsize, +tsize, +tsize) + center;
	Vector3 TRB = Vector3(+tsize, +tsize, +tsize) + center;
	Vector3 BLB = Vector3(-tsize, -tsize, +tsize) + center;
	Vector3 BRB = Vector3(+tsize, -tsize, +tsize) + center;

	Vector3 NRight(1, 0, 0);
	Vector3 NLeft(-1, 0, 0);
	Vector3 NUp(0, 1, 0);
	Vector3 NDown(0, -1, 0);
	Vector3 NIn(0, 0, 1);
	Vector3 NOut(0, 0, -1);



	values[bufferPos] =  Triangle(TLF, TRF, BLF,NOut);
	values[bufferPos + 1] = Triangle(BLF, TRF, BRF, NOut);

	values[bufferPos + 2] = Triangle(BRF, BRB, TRB, NRight);
	values[bufferPos + 3] = Triangle(TRB, TRF, BRF, NRight);

	values[bufferPos + 4] = Triangle(TLB, TRB, BLB, NIn);
	values[bufferPos + 5] = Triangle(BLB, TRB, BRB, NIn);

	values[bufferPos + 6] = Triangle(BLF, BLB, TLB, NLeft);
	values[bufferPos + 7] = Triangle(TLB, TLF, BLF, NLeft);

	values[bufferPos + 8] = Triangle(TLF, TRF, TRB, NUp);
	values[bufferPos + 9] = Triangle(TRB, TLF, TLB, NUp);

	values[bufferPos + 10] = Triangle(BLF, BRF, BRB, NDown);
	values[bufferPos + 11] = Triangle(BRB, BLF, BLB, NDown);

	taken += 12;
}

void FaceBuffer::TransforMatrix(Matrix &m)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j)*m);
		}
	}
}


void FaceBuffer::moveForward(float step)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j) + Vector3(0,0,-step));
		}
	}
	transformation.SetValue(2, transformation.GetValues(1) - step);
}

void FaceBuffer::moveBackward(float step)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j) + Vector3(0, 0, +step));
		}
	}
	transformation.SetValue(2, transformation.GetValues(1) + step);
}

void FaceBuffer::moveLeft(float step)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j) + Vector3(step, 0, 0));
		}
	}
	transformation.SetValue(0, transformation.GetValues(1) + step);
}

void FaceBuffer::moveRight(float step)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j) + Vector3(-step, 0, 0));
		}
	}
	transformation.SetValue(0, transformation.GetValues(1) - step);
}

void FaceBuffer::moveUp(float step)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j) + Vector3(0, -step, 0));
		}
	}
	transformation.SetValue(1, transformation.GetValues(1) - step);
}

void FaceBuffer::moveDown(float step)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			values[i].setValue(j, values[i].getValue(j) + Vector3(0, step, 0));
		}
	}
	transformation.SetValue(1, transformation.GetValues(1) + step);
}

void FaceBuffer::rotateDown(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(step, 0, 0);
	rotations.SetValue(0, rotations.GetValues(0) + step);
	(*this).TransforMatrix(m);
}

void FaceBuffer::rotateUp(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(-step, 0, 0);
	rotations.SetValue(0, rotations.GetValues(0) - step);
	(*this).TransforMatrix(m);
}

void FaceBuffer::rotateRight(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(0, step, 0);
	rotations.SetValue(1, rotations.GetValues(1) + step);
	(*this).TransforMatrix(m);
}

void FaceBuffer::rotateLeft(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(0, -step, 0);
	rotations.SetValue(1, rotations.GetValues(1) - step);
	(*this).TransforMatrix(m);
}
