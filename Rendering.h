#pragma once
#include <Windows.h>
#include <math.h>
#include "wtypes.h"
#include "CommonHeaders.h"
#include "RenderBuffer.h"
#include "FaceBuffer.h"
class Rendering
{
	public:
		static void LinesFromCamera(HDC hdc, Vector3 Camera_Pos, Vector3 Camera_Look, VertexBuffer &Buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance); 
		static void LinesToCamera(HDC hdc, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, VertexBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);
		static sf::Image From(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, VertexBuffer &Buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);
		static sf::Image From(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, RenderBuffer &Buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);
		static VertexBuffer To(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, VertexBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);
		static VertexBuffer To(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, RenderBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);
		static VertexBuffer To(sf::RenderWindow &window, Vector3 Camera_Pos, Vector3 Camera_Look, Vector3 Up, FaceBuffer &buffer, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);
	
};