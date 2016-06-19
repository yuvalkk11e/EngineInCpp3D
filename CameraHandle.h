#pragma once
#include "CommonHeaders.h"
#include "RenderBuffer.h"
#include "TransformationMatrixes.h"
#include "FaceBuffer.h"

template <class T>
class CameraHandle
{
private:
	int xpos;
	int ypos;
	float sensitivity;
	T buffer;
	 
public:
	CameraHandle(int x, int y, float sensitivity1, T buff)
	{
		buffer = buff;
		xpos = x;
		ypos = y;
		sensitivity = sensitivity1;
	}

	void MouseMovedCamera(sf::Event event)
	{
		int x = event.mouseMove.x;
		int y = event.mouseMove.y;

		int xmoved = (x - xpos)*sensitivity;
		int ymoved = (y - ypos)*sensitivity;

		Matrix m = TransformationMatrixes::rotationMatrix(ymoved, xmoved, 0);
		buffer.TransforMatrix(m);
		Vector3 rotation = buffer.getRotation();
		buffer.setRotations(rotation.GetValues(0) + xmoved, rotation.GetValues(1) + ymoved, rotation.GetValues(2));

		xpos = x;
		ypos = y;
	}

	void KeyboardMovedCamera(sf::Event event, float step)
	{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				buffer.moveForward(step);
				break;
			case sf::Keyboard::A:
				buffer.moveLeft(step);
				break;
			case sf::Keyboard::S:
				buffer.moveBackward(step);
				break;
			case sf::Keyboard::D:
				buffer.moveRight(step);
				break;

			case sf::Keyboard::Space:
				buffer.moveUp(step);
				break;
			case sf::Keyboard::LShift:
				buffer.moveDown(step);
				break;
			}
	}
};



