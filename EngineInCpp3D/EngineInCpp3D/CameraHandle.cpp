#include "CameraHandle.h"


CameraHandle::CameraHandle()
{
	xpos = 0;
	ypos = 0;
}

CameraHandle::CameraHandle(int xposi, int yposi)
{
	xpos = xposi;
	ypos = yposi;
	sensitivity = 1;
}

CameraHandle::CameraHandle(int xposi, int yposi, float sensitivity2)
{
	xpos = xposi;
	ypos = yposi;
	sensitivity = sensitivity2;
}

CameraHandle::~CameraHandle()
{
	//ADD DESTRUCTOR
}

void CameraHandle::MouseMovedCamera(sf::Event event, RenderBuffer render)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;
	 
	int xmoved = (x - xpos)*sensitivity;
	int ymoved = (y - ypos)*sensitivity;

	Matrix m = TransformationMatrixes::rotationMatrix(ymoved, xmoved, 0);
	render.TransforMatrix(m);
	Vector3 rotation = render.getRotation();
	render.setRotations(rotation.GetValues(0) + xmoved, rotation.GetValues(1) + ymoved, rotation.GetValues(2));
	
	xpos = x;
	ypos = y;
}