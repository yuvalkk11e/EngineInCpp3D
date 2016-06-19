#pragma once
#include <Windows.h>
#include "wtypes.h"
#include "CommonHeaders.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
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

	__device__ Vector3 getValue(int pos);
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

	//post Rendering stuff ! :
	//for sorting
	void SortByZ();
	void Switch(int pos1, int pos2);
	//for cleaning useless triangles
	void CleanTriangles();
	

	VertexBuffer operator = (VertexBuffer &buffer);

};