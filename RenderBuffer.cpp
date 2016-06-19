#include "RenderBuffer.h"

RenderBuffer::RenderBuffer(int size)
	:VertexBuffer(size)
{
	rotations = Vector3(0, 0, 0);
	transformation = Vector3(0, 0, 0);
}

RenderBuffer::RenderBuffer(Vector3 * ptr, int size)
	:VertexBuffer(ptr, size)
{
	rotations = Vector3(0, 0, 0);
	transformation = Vector3(0, 0, 0);
}


RenderBuffer::~RenderBuffer()
{
}

void RenderBuffer::moveForward(float step)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i].SetValue(2, ptr[i].GetValues(2) - step);
	}
	transformation.SetValue(2, transformation.GetValues(1) - step);
}

void RenderBuffer::moveBackward(float step)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i].SetValue(2, ptr[i].GetValues(2) + step);
	}
	transformation.SetValue(2, transformation.GetValues(1) + step);
}

void RenderBuffer::moveLeft(float step)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i].SetValue(0, ptr[i].GetValues(0) + step);
	}
	transformation.SetValue(0, transformation.GetValues(1) + step);
}

void RenderBuffer::moveRight(float step)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i].SetValue(0, ptr[i].GetValues(0) - step);
	}
	transformation.SetValue(0, transformation.GetValues(1) - step);
}

void RenderBuffer::moveUp(float step)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i].SetValue(1, ptr[i].GetValues(1) - step);
	}
	transformation.SetValue(1, transformation.GetValues(1) - step);
}

void RenderBuffer::moveDown(float step)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i].SetValue(1, ptr[i].GetValues(1) + step);
	}
	transformation.SetValue(1, transformation.GetValues(1) + step);
}

void RenderBuffer::rotateDown(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(step, 0, 0);
	rotations.SetValue(0, rotations.GetValues(0) + step);
	(*this).TransforMatrix(m);
}

void RenderBuffer::rotateUp(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(-step, 0, 0);
	rotations.SetValue(0, rotations.GetValues(0) - step);
	(*this).TransforMatrix(m);
}

void RenderBuffer::rotateRight(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(0, step, 0);
	rotations.SetValue(1, rotations.GetValues(1) + step);
	(*this).TransforMatrix(m);
}

void RenderBuffer::rotateLeft(float step)
{
	Matrix m = TransformationMatrixes::rotationMatrix(0, -step, 0);
	rotations.SetValue(1, rotations.GetValues(1) - step);
	(*this).TransforMatrix(m);
}

RenderBuffer RenderBuffer::operator =(VertexBuffer buffer)
{
	size = buffer.getSize();
	for (int i = 0; i < size; i++)
	{
		ptr[i] = buffer.getValue(i);
	}
	return *this;
}