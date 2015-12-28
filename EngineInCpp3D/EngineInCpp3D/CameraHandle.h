#pragma once
#include "CommonHeaders.h"
#include "RenderBuffer.h"
#include "TransformationMatrixes.h"

class CameraHandle
{
private:
	int xpos;
	int ypos;
	float sensitivity;

public:
	CameraHandle();
	CameraHandle(int xposi, int yposi);
	CameraHandle(int xposi, int yposi, float sensitivity2);
	~CameraHandle();
	
	void MouseMovedCamera(sf::Event event, RenderBuffer render);
	
};

