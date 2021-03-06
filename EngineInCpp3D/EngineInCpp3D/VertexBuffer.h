#pragma once
#include <Windows.h>
#include "wtypes.h"
#include "CommonHeaders.h"
//#include "Rendering.h"

//#include <GLFW\glfw3.h>

class VertexBuffer
{
	friend class Vector3;
protected:

	Vector3 * ptr;
	int size;

public:
	VertexBuffer(int size); //Initialize buffer with empty points by size
	VertexBuffer(Vector3 * ptr2, int size); //Initialize buffer with already existing point_array;
	VertexBuffer(); //TO-DO
	~VertexBuffer();

	Vector3 getValue(int pos);
	void setValue(int pos, Vector3 v);
	int getSize();

	void CreateCube(float sizein, Vector3 center, int bufferpos);
	void setSize(int size);
	void Insert(Vector3 p); //TO-DO
	void Remove(); //TO-DO
	void TransforMatrix(Matrix m);
	void DrawBufferLines(HDC hdc);
	void DrawBufferTriangles(HDC hdc); //Size Of VertexBuffer Must Be SUITABLE TO %3 !!
	void DrawBufferTriangles(sf::RenderWindow &window);
	void SortByZ();

	VertexBuffer operator = (VertexBuffer &buffer);

};