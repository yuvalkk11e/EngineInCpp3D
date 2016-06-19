#pragma once
#include <Windows.h>
class Point
{
	friend class VertexBuffer;
	protected: 
		float values[3];
		int color[3];

	public:
		Point();
		Point(float a, float b, float c);
		Point(float a, float b, float c, int color[]);
		~Point();

		void setValues(float value[]);
		void setValue(int pos, float value);
		float* getValues();
		float getValue(int pos);

		Point operator +(Point inpoint);
		Point operator *(Point inpoint);
		Point operator =(Point inpoint);
		Point operator -(Point inpoint);
};

