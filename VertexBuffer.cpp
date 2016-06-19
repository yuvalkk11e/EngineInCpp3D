
#include "VertexBuffer.h"


VertexBuffer::VertexBuffer(int size)
{
	this->size = size;
	ptr = new Vector3[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] =  Vector3(0,0,0);
	}
}

VertexBuffer::VertexBuffer(Vector3 * ptr2,int size)
{
	this->size = size;
	this->ptr = ptr2;
}


void VertexBuffer::setSize(int size)
{
	this->size = size;
	int csize = this->size;
	Vector3 * ptr2 = new Vector3[csize];
	for (int i = 0; i < csize; i++)
	{
		ptr2[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new Vector3[size];
	for (int j = 0; j < size; j++)
	{
		ptr[j] = ptr2[j];
	}
	if (size > csize)
	{
		for (int x = csize; x < size ; x++)
			ptr[x] = Vector3(0, 0, 0);
	}
}

void VertexBuffer::Insert (Vector3 p)
{
	//
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
	for (int i = 0; i < size; i += 3)
	{
		HPEN htemppen = CreatePen(PS_INSIDEFRAME,1,RGB(255,0,0));
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

void VertexBuffer::DrawBufferTriangles(sf::RenderWindow &window) //Size Of VertexBuffer Must Be SUITABLE TO %3 !!
{

	
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	float color = 0;
	//triangle.setOutlineColor(sf::Color::Cyan);
	sf::Texture texture;
	if (!texture.loadFromFile("minecraftStone.png", sf::IntRect(10, 10, 1000, 1000)))
	{
		//meme
	}
	triangle.setTexture(&texture);
	sf::Vector2f vertice;

	//Sort Buffer !
	SortByZ();
	//Clean Buffer of off screen triangles !
	CleanTriangles();
	window.clear(sf::Color::White);
	for (int i = 0; i < size; i += 3)
	{
		for (int k = 0; k < 3; k++)
		{
			//triangle.setFillColor(sf::Color(color, color, color));
			color += 1;
			vertice.x = ptr[i + k].GetValues(0);
			vertice.y = ptr[i + k].GetValues(1);
			triangle.setPoint(k, vertice);
		}
		window.draw(triangle);
	}
	window.display();
}

void VertexBuffer::CreateCube(float sizein,Vector3 center,int bufferpos)
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

	VertexBuffer copy = *this;
	ptr = new Vector3[size+36];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = copy.getValue(i);
	}
	size += 36;

	ptr[0 + bufferpos] = TLF;
	ptr[1 + bufferpos] = TRF;
	ptr[2 + bufferpos] = BLF;
	ptr[3 + bufferpos] = BLF;
	ptr[4 + bufferpos] = TRF;
	ptr[5 + bufferpos] = BRF;

	ptr[6 + bufferpos] = BRF;
	ptr[7 + bufferpos] = BRB;
	ptr[8 + bufferpos] =TRB;
	ptr[9 + bufferpos] = TRB;
	ptr[10 + bufferpos] = TRF;
	ptr[11 + bufferpos] = BRF;

	ptr[12 + bufferpos] = TLB;
	ptr[13 + bufferpos] = TRB;
	ptr[14 + bufferpos] = BLB;
	ptr[15 + bufferpos] = BLB;
	ptr[16 + bufferpos] = TRB;
	ptr[17 + bufferpos] = BRB;

	ptr[18 + bufferpos] = BLF;
	ptr[19 + bufferpos] = BLB;
	ptr[20 + bufferpos] = TLB;
	ptr[21 + bufferpos] = TLB;
	ptr[22 + bufferpos] = TLF;
	ptr[23 + bufferpos] = BLF;

	ptr[24 + bufferpos] = TLF;
	ptr[25 + bufferpos] = TRF;
	ptr[26 + bufferpos] = TRB;
	ptr[27 + bufferpos] = TRB;
	ptr[28 + bufferpos] = TLF;
	ptr[29 + bufferpos] = TLB;

	ptr[30 + bufferpos] = BLF;
	ptr[31 + bufferpos] = BRF;
	ptr[32 + bufferpos] = BRB;
	ptr[33 + bufferpos] = BRB;
	ptr[34 + bufferpos] = BLF;
	ptr[35 + bufferpos] = BLB;
}

void VertexBuffer::TransforMatrix(Matrix m)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = ptr[i] * m;
	}
}

void VertexBuffer::SortByZ()
{
	//CURRENTLY PREFORMING NATURAL SORT ALGO.
	//END ARRAY IS SORTED FROM BIGGEST Z TO SMALLEST Z
	//IN TESTING !
	for (int k = 0; k < size; k+=3)
	{
		float smallest = ptr[k].GetValues(2);
		int placement = k;
		for (int i = k; i < size; i+=3)
		{
			for (int p = 0; p < 3; p++)
			{
				if (ptr[i+p].GetValues(2) > smallest)
				{
					smallest = ptr[i+p].GetValues(2);
					placement = i;
				}
			}
		}
		for (int x = 0; x < 3; x++)
		{
			(*this).Switch(k+x, placement+x);
		}
	}
		
}

void VertexBuffer::Switch(int pos1, int pos2)
{
	Vector3 temp(0, 0, 0);
	temp = ptr[pos1];
	ptr[pos1] = ptr[pos2];
	ptr[pos2] = temp;
}

void VertexBuffer::CleanTriangles()
{
	//Screen Size needed !!!
	//Screen == 1000
	for (int i = 0; i < size; i+=3)
	{
		if ((ptr[i].GetValues(0) < 0 || ptr[i].GetValues(0) > 1000 || ptr[i].GetValues(1) < 0 || ptr[i].GetValues(1) > 1000) &&
			(ptr[i + 1].GetValues(0) < 0 || ptr[i + 1].GetValues(0) > 1000 || ptr[i + 1].GetValues(1) < 0 || ptr[i + 1].GetValues(1) > 1000) &&
			(ptr[i + 2].GetValues(0) < 0 || ptr[i + 2].GetValues(0) > 1000 || ptr[i + 2].GetValues(1) < 0 || ptr[i + 2].GetValues(1) > 1000))
		{
			//delete triangle
			ptr[i] = Vector3();
			ptr[i + 1] = Vector3();
			ptr[i + 2] = Vector3();
		}
	}
}

VertexBuffer::~VertexBuffer()
{
}

__device__ Vector3 VertexBuffer::getValue(int pos)
{
	return ptr[pos];
}
void VertexBuffer::setValue(int pos, Vector3 v)
{
	ptr[pos] = v; 
}
int VertexBuffer::getSize()
{
	return size;
}

VertexBuffer VertexBuffer::operator = (VertexBuffer &buffer)
{
	size = buffer.getSize();
	for (int i = 0; i < size; i++)
	{
		ptr[i] = buffer.getValue(i);
	}
	return *this;
}