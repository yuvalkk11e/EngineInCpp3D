#pragma once
#include <Windows.h>
class Point
{
	friend class VertexBuffer;
	protected: 
		float values[3];
		COLORREF color;

	public:
		Point(float a, float b, float c);
		Point(float a, float b, float c, COLORREF color);
		Point();
		~Point();
		Point operator +(Point inpoint);
		Point operator *(Point inpoint);
		Point operator =(Point inpoint);
		Point operator -(Point inpoint);
};

