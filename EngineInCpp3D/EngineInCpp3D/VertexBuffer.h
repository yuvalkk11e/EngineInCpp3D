#pragma once
#include "Point.h"
#include <Windows.h>
#include "wtypes.h"
//#include <GLFW\glfw3.h>

class VertexBuffer
{
	friend class Point;
private:

	Point * ptr;
	int size;

public:
	VertexBuffer(int size); //Initialize buffer with empty points by size
	VertexBuffer(Point* ptr2, int size); //Initialize buffer with already existing point_array;
	VertexBuffer(); //TO-DO
	~VertexBuffer();
	void CreateCube(float size,float center, int bufferpos);
	void setSize(int size);
	void Insert(Point p); //TO-DO
	void Remove(); //TO-DO
	void DrawBufferLines(HDC hdc);
	void DrawBufferTriangles(HDC hdc); //Size Of VertexBuffer Must Be SUITABLE TO %3 !!
};