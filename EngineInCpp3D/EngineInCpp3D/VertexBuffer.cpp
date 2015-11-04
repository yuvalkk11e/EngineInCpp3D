
#include "VertexBuffer.h"
#include "Point.h"


VertexBuffer::VertexBuffer()
{
}

VertexBuffer::VertexBuffer(int size)
{
	this->size = size;
	ptr = new Point[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] =  Point(0,0,0);
	}
}

VertexBuffer::VertexBuffer(Point * ptr2,int size)
{
	this->size = size;
	this->ptr = ptr2;
}


void VertexBuffer::setSize(int size)
{
	this->size = size;
	int csize = this->size;
	Point * ptr2 = new Point[csize];
	for (int i = 0; i < csize; i++)
	{
		ptr2[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new Point[size];
	for (int j = 0; j < size; j++)
	{
		ptr[j] = ptr2[j];
	}
	if (size > csize)
	{
		for (int x = csize; x < size ; x++)
			ptr[x] = Point(0, 0, 0);
	}
}

void VertexBuffer::Insert(Point p)
{

}

void VertexBuffer::DrawBufferLines(HDC hdc)
{
	COLORREF red = RGB(255, 0, 0);
	int a, b, c,a2,b2,c2;
	for (int i = 0; i < size-1 ; i++) //size-1 Because Lines problem
	{
		a = (int)ptr[i].values[0];
		b = (int)ptr[i].values[1];
		c = (int)ptr[i].values[2];
		a2 = (int)ptr[i+1].values[0];
		b2 = (int)ptr[i+1].values[1];
		c2 = (int)ptr[i+1].values[2];
		MoveToEx(hdc, a, b, NULL);
		LineTo(hdc, a2, b2);
	}
}

void VertexBuffer::DrawBufferTriangles(HDC hdc) //Size Of VertexBuffer Must Be SUITABLE TO %3 !!
{
	COLORREF black = RGB(255, 255, 255);
	POINT arr[3];
	POINT p1, p2, p3;
	for (int i = 0; i < size-1; i += 3)
	{
		HPEN htemppen = CreatePen(PS_INSIDEFRAME,1,ptr[i].color);
		HBRUSH htempbrush = CreateSolidBrush(RGB(0,255,0));
		HPEN hPen = (HPEN)SelectObject(hdc, htemppen);
		HBRUSH hBrush = (HBRUSH)SelectObject(hdc, htempbrush);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		DeleteObject(htempbrush);
		DeleteObject(htemppen);
		arr[0] = { ptr[i].values[0], ptr[i].values[1] };
		arr[1] = { ptr[i + 1].values[0], ptr[i + 1].values[1] };
		arr[2] = { ptr[i + 2].values[0], ptr[i + 2].values[1] };
		SetBkColor(hdc, RGB(0,0,255));
		Polygon(hdc,arr,3);
	}
}

void VertexBuffer::CreateCube(float size,float center,int bufferpos)
{
	for (int i = bufferpos; i < bufferpos + 36; i++)
	{
		//ptr[i] = Point(center + );
	}
}


VertexBuffer::~VertexBuffer()
{
}