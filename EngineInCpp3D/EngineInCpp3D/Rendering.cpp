#include "Rendering.h"
#include <math.h>

#define PI 3.14159265
#define PIr (180/PI) // I CHANGED FROM PI/180 TO THIS !

void Rendering::LinesFromCamera(HDC hdc, Vector3 Camera_Pos, Vector3 Camera_Look, VertexBuffer &Buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance)
{	
	float Angle_bith = (float)View_Angle / (float)HEIGHT;
	float Angle_bitw = (float)View_Angle / (float)WIDTH;
	float x_offset = 0;
	float y_offset = 0;
	float Temp_Angleh = (float)View_Angle / 2;
	float Temp_Anglew = -(float)View_Angle / 2;
	Vector3 Current_Pos = Camera_Pos;
	Vector3 Temp_Angle_Vector(0, 0, 0);
	//Vector3 A;
	//Vector3 B;
	Vector3 norm;
	float t;

	for (int i = 0; i < HEIGHT; i++)
	{
		Temp_Anglew = -(float)View_Angle / 2;
 		for (int j = 0; j < WIDTH; j++)
		{
			//Current_Pos = Vector3(Camera_Pos.GetValues(0) + float(tan(PIr*Temp_Anglew)) * 1, Camera_Pos.GetValues(1) + float(tan(PIr*Temp_Angleh) * 1), Camera_Pos.GetValues(2) + 1);
			Temp_Angle_Vector.SetValues((float)tan(PIr*Temp_Anglew) * 1, (float)tan(PIr*Temp_Angleh) * 1, 1);
			for (int k = 0; k < Buffer.getSize(); k += 3)
			{
				norm = (Buffer.getValue(k+1) - Buffer.getValue(k)).crossProduct(Buffer.getValue(k+2) - Buffer.getValue(k)); // we might need to divide  / absolute 
				t = (Buffer.getValue(k)*norm - Camera_Pos*norm) / (Temp_Angle_Vector * norm); 
				if (t > 0 && (Temp_Angle_Vector*t).length() < View_Distance)
				{
					if (MathFunctions::pointInTriangle(Camera_Pos + Temp_Angle_Vector*t, Buffer.getValue(k), Buffer.getValue(k + 1), Buffer.getValue(k + 2)))
					{
						SetPixel(hdc, j, i, RGB(0, 0, 255));
						break;
					}
				}
			}
			Temp_Anglew += Angle_bitw; 
		}
		Temp_Angleh -= Angle_bith;
	}
	SetPixel(hdc, 1, 1, RGB(0, 0, 0));
	
}

void Rendering::LinesToCamera(HDC hdc, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, VertexBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance)
{
	//c^2 = a^2 + b^2 - 2ab*cos(c) :: cos(c) = ( a^2 + b^2 - c^2 ) / 2ab
	float Angle_bith = (float)View_Angle / (float)HEIGHT;
	float Angle_bitw = (float)View_Angle / (float)WIDTH;
	float x_offset = 0;
	float y_offset = 0;
	float z_offset = 0;
	float inAngle;
	float Angley = (float)View_Angle / 2;
	float Anglex = -(float)View_Angle / 2;
	float Anglez = -(float)View_Angle / 2;
	Vector3 Current_Pos = Camera_Pos;
	Vector3 TempPoint;
	Vector3 Temp_Angle(0, 0, 0);
	bool Hit = false;
	int a,c = 0;
	int b = sqrt((Current_Pos.GetValues(0) - Camera_Look.GetValues(0))*(Current_Pos.GetValues(0) - Camera_Look.GetValues(0)) + (Current_Pos.GetValues(2) - Camera_Look.GetValues(2))*(Current_Pos.GetValues(2) - Camera_Look.GetValues(2)));
	//distance between the camera and origin 
	for (int i = 0; i < buffer.getSize(); i+=3)
	{
		TempPoint = buffer.getValue(0);
		a = sqrt((Current_Pos.GetValues(0) - TempPoint.GetValues(0))*(Current_Pos.GetValues(0) - TempPoint.GetValues(0)) + (Current_Pos.GetValues(2) - TempPoint.GetValues(2))*(Current_Pos.GetValues(2) - TempPoint.GetValues(2)));
		//distance between the point and origin  : a
		c = sqrt((Camera_Look.GetValues(0) - TempPoint.GetValues(0))*(Camera_Look.GetValues(0) - TempPoint.GetValues(0)) + (Camera_Look.GetValues(2) - TempPoint.GetValues(2))*(Camera_Look.GetValues(2) - TempPoint.GetValues(2)));
		inAngle = acos((a*a + b*b - c*c) / (2 * a*b));

		
		//Paint triangle to screen 
	}

}

sf::Image Rendering::From(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, VertexBuffer &Buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance)
{
	float Angle_bith = (float)View_Angle / (float)HEIGHT;
	float Angle_bitw = (float)View_Angle / (float)WIDTH;
	float x_offset = 0;
	float y_offset = 0;
	float Temp_Angleh = (float)View_Angle / 2;
	float Temp_Anglew = -(float)View_Angle / 2;
	Vector3 Current_Pos = Camera_Pos;
	Vector3 Temp_Angle_Vector(0, 0, 0);
	//Vector3 A;
	//Vector3 B;
	Vector3 norm;
	float t;
	sf::Image image;
	image.create(WIDTH, HEIGHT, sf::Color::White);
	float color = 0;

	for (int i = 0; i < HEIGHT; i++)
	{
		Temp_Anglew = -(float)View_Angle / 2;
		for (int j = 0; j < WIDTH; j++)
		{
			//Current_Pos = Vector3(Camera_Pos.GetValues(0) + float(tan(PIr*Temp_Anglew)) * 1, Camera_Pos.GetValues(1) + float(tan(PIr*Temp_Angleh) * 1), Camera_Pos.GetValues(2) + 1);
			Temp_Angle_Vector.SetValues((float)tan(PIr*Temp_Anglew) * 1, (float)tan(PIr*Temp_Angleh) * 1, 1);
			for (int k = 0; k < Buffer.getSize(); k += 3)
			{
				//Ray Triangle intersection
				norm = (Buffer.getValue(k + 1) - Buffer.getValue(k)).crossProduct(Buffer.getValue(k + 2) - Buffer.getValue(k)); // we might need to divide  / absolute 
				t = (Buffer.getValue(k)*norm - Camera_Pos*norm) / (Temp_Angle_Vector * norm);
				if (t > 0 && (Temp_Angle_Vector*t).length() < View_Distance)
				{
					if (MathFunctions::pointInTriangle(Camera_Pos + Temp_Angle_Vector*t, Buffer.getValue(k), Buffer.getValue(k + 1), Buffer.getValue(k + 2)))
					{
						image.setPixel(j, i, sf::Color(color,color,color));
						color++;
						break;
					}
				}
			}
			Temp_Anglew += Angle_bitw;
		}
		Temp_Angleh -= Angle_bith;
	}
	return image;
}

VertexBuffer Rendering::To(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, VertexBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance)
{
	//c^2 = a^2 + b^2 - 2ab*cos(c) :: cos(c) = ( a^2 + b^2 - c^2 ) / 2ab
	float Angle_bith = (float)View_Angle / (float)HEIGHT;
	float Angle_bitw = (float)View_Angle / (float)WIDTH;
	float x_offset = 0;
	float y_offset = 0;
	float inAngle;
	float Angleyz;
	float Anglexz;
	Vector3 Lookat(0, 0, 1);
	Vector3 TempPoint(0, 0, 0);
	Vector3 a(0, 0, 0);
	Vector3 b(0, 0, 0);
	VertexBuffer scene(buffer.getSize());
	for (int i = 0; i < buffer.getSize(); i++)
	{
		TempPoint = buffer.getValue(i);
		a = Vector3(TempPoint.GetValues(0), 0, TempPoint.GetValues(2));
		b = Vector3(0, TempPoint.GetValues(1), TempPoint.GetValues(2));
		x_offset = ((Lookat*a) / (a.length() * Lookat.length()));
		Anglexz = acos(x_offset)*PIr;
		if (a.GetValues(0) < 0)
			Anglexz = -Anglexz;
		if (abs(Anglexz) < float(View_Angle) / 2) // CAN THE ANGLE BE NAGATIVE ?
		{
			y_offset = ((Lookat*b) / (b.length() * Lookat.length()));
			Angleyz = acos(y_offset)*PIr;
			if (b.GetValues(1) < 0)
				Angleyz = -Angleyz;
			if (abs(Angleyz) < float(View_Angle) / 2) //CAN THE ANGLE BE NAGTIVE ?
			{
				scene.setValue(i, Vector3(Anglexz / Angle_bitw + float(WIDTH )/ 2, -Angleyz / Angle_bith + float(HEIGHT) / 2, 0));
			}
		}
	}
	return scene;
}

VertexBuffer Rendering::To(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, RenderBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance)
{
	float Angle_bith = (float)View_Angle / (float)HEIGHT;
	float Angle_bitw = (float)View_Angle / (float)WIDTH;
	float x_offset = 0;
	float y_offset = 0;
	float inAngle;
	float Angleyz = 0;
	float Anglexz = 0;
	Vector3 Lookat(0, 0, 1);
	Vector3 TempPoint(0, 0, 0);
	Vector3 a(0, 0, 0);
	Vector3 b(0, 0, 0);
	VertexBuffer scene(buffer.getSize());
	for (int i = 0; i < buffer.getSize(); i++)
	{
		if (TempPoint.equals(buffer.getValue(i)))
		{
			scene.setValue(i, Vector3(Anglexz / Angle_bitw + float(WIDTH) / 2, -Angleyz / Angle_bith + float(HEIGHT) / 2, 0));
			continue;
		}

		TempPoint = buffer.getValue(i);
		a = Vector3(TempPoint.GetValues(0), 0, TempPoint.GetValues(2));
		b = Vector3(0, TempPoint.GetValues(1), TempPoint.GetValues(2));
		x_offset = ((Lookat*a) / (a.length() * Lookat.length()));
		Anglexz = acos(x_offset)*PIr;
		if (a.GetValues(0) < 0)
			Anglexz = -Anglexz;
		if (abs(Anglexz) < float(View_Angle) / 2) 
		{
			y_offset = ((Lookat*b) / (b.length() * Lookat.length()));
			Angleyz = acos(y_offset)*PIr;
			if (b.GetValues(1) < 0)
				Angleyz = -Angleyz;
			if (abs(Angleyz) < float(View_Angle) / 2) 
			{
				scene.setValue(i, Vector3(Anglexz / Angle_bitw + float(WIDTH) / 2, -Angleyz / Angle_bith + float(HEIGHT) / 2, 0));
			}
		}
	}
	return scene;
	//Paint triangle to screen 
}

sf::Image Rendering::From(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, RenderBuffer &Buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance)
{
	float Angle_bith = (float)View_Angle / (float)HEIGHT;
	float Angle_bitw = (float)View_Angle / (float)WIDTH;
	float x_offset = 0;
	float y_offset = 0;
	float Temp_Angleh = (float)View_Angle / 2;
	float Temp_Anglew = -(float)View_Angle / 2;
	Vector3 Current_Pos = Camera_Pos;
	Vector3 Temp_Angle_Vector(0, 0, 0);
	//Vector3 A;
	//Vector3 B;
	Vector3 norm;
	float t;
	sf::Image image;
	image.create(WIDTH, HEIGHT, sf::Color::White);
	float color = 0;


	for (int i = 0; i < HEIGHT; i++)
	{
		Temp_Anglew = -(float)View_Angle / 2;
		for (int j = 0; j < WIDTH; j++)
		{
			//Current_Pos = Vector3(Camera_Pos.GetValues(0) + float(tan(PIr*Temp_Anglew)) * 1, Camera_Pos.GetValues(1) + float(tan(PIr*Temp_Angleh) * 1), Camera_Pos.GetValues(2) + 1);
			Temp_Angle_Vector.SetValues((float)tan(PIr*Temp_Anglew) * 1, (float)tan(PIr*Temp_Angleh) * 1, 1);
			for (int k = 0; k < Buffer.getSize(); k += 3)
			{
				//Ray Triangle intersection
				norm = (Buffer.getValue(k + 1) - Buffer.getValue(k)).crossProduct(Buffer.getValue(k + 2) - Buffer.getValue(k)); // we might need to divide  / absolute 
				t = (Buffer.getValue(k)*norm - Camera_Pos*norm) / (Temp_Angle_Vector * norm);
				if (t > 0 && (Temp_Angle_Vector*t).length() < View_Distance)
				{
					if (MathFunctions::pointInTriangle(Camera_Pos + Temp_Angle_Vector*t, Buffer.getValue(k), Buffer.getValue(k + 1), Buffer.getValue(k + 2)))
					{
						image.setPixel(j, i, sf::Color(color,color,color));
						color += 10;
						break;
					}
				}
			}
			Temp_Anglew += Angle_bitw;
		}
		Temp_Angleh -= Angle_bith;
	}
	return image;
}
