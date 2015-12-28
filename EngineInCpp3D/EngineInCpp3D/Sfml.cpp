#pragma once
#include "CommonHeaders.h"
#include "RenderBuffer.h"
#include "TransformationMatrixes.h"
#include "Rendering.h"
#include "CameraHandle.h"
#include <random>
//#include <Game.h>
int main()
{

	//Initialize our data 
	Vector3 v_array[6] = { Vector3(-15, -15, 100), Vector3(15, -15, 100), Vector3(0, 15, 100), Vector3(-15, 15, 300), Vector3(15, 15, 300), Vector3(0, -15, 300) };
	//VertexBuffer buffer(v_array,6);
	VertexBuffer buffer(0);
	buffer.CreateCube(20, Vector3(100, 0, 200), 0);
	buffer.CreateCube(20, Vector3(-100, 0, 200), 36);
	buffer.CreateCube(20, Vector3(0, 0, 200), 72);
	buffer.CreateCube(20, Vector3(0, 100, 200), 108);
	buffer.CreateCube(20, Vector3(0, -100, 200), 144);
	RenderBuffer renderBuffer(buffer.getSize());
	renderBuffer = buffer;

	float sensitivity = 1.1;
	CameraHandle cameraHandle(500, 500, sensitivity); // THE CAMERA WILL ROTATE INCORRECTLY AT THE FIRST FRAME !

	float step = 4;
	float rotate = 2;

	Matrix m = TransformationMatrixes::rotationMatrix(0, 0, 0);
	int Screen_Width = 1000, Screen_Height = 1000;
	int View_Angle = 90;
	Vector3 up(0, 1, 0);
	Vector3  Camera_Pos(0, 0, 0);
	Vector3 Camera_Look(0, 0, 0);
	int View_Distance = 1500;

	//CREATE OUR WINDOW
	sf::RenderWindow window(sf::VideoMode(Screen_Width, Screen_Height), "3D Rendering! -- Yuval's Engine!");

	//Create shapes
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture background;
	sf::RenderTexture texture;
	if (!texture.create(1000, 1000))
		return -1;
	image.create(1000, 1000, sf::Color::Black);
	image.setPixel(100, 100, sf::Color::Red);

	//if (!image.saveToFile("result.png"))
		//return 1;

	sf::Uint8* pixels = new sf::Uint8[Screen_Width * Screen_Height * 4];
	for (int i = 0; i < Screen_Width * Screen_Height * 4; i++)
	{
		pixels[i] = rand() % 255;
	}
	if (!background.loadFromImage(image))
		return -1;
	sprite.setTexture(background);

	//Rendering Method : raysFromCamera OR raysToCamera
	std::string renderMethod = "To";

	//Game Loop
	while (window.isOpen()){

		//CREATE OUR EVENT HANDLE
		sf::Event event;

		//Event Loop
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::W:
						renderBuffer.moveForward(step);
						break;
					case sf::Keyboard::A:
						renderBuffer.moveLeft(step);
						break;
					case sf::Keyboard::S:
						renderBuffer.moveBackward(step);
						break;
					case sf::Keyboard::D:
						renderBuffer.moveRight(step);
						break;

					case sf::Keyboard::Space:
						renderBuffer.moveUp(step);
						break;
					case sf::Keyboard::LShift:
						renderBuffer.moveDown(step);
						break;
					}
					break;

				case sf::Event::MouseMoved:
					cameraHandle.MouseMovedCamera(event, renderBuffer);
					break;
					
				default:
					break;
			}
		}

		//Game Logic		
		

		if (renderMethod == "From")
		{
			background.update(Rendering::From(window, Camera_Pos, Camera_Look, renderBuffer, View_Angle, Screen_Height, Screen_Width, View_Distance));
			sprite.setTexture(background);

			//Draw Logic
			window.clear(sf::Color::White);
			window.draw(sprite);
			window.display();
		}

		if (renderMethod == "To")
		{
			Rendering::To(window, Camera_Pos, Camera_Look, up, renderBuffer, View_Angle, Screen_Width, Screen_Height, View_Distance).DrawBufferTriangles(window);
		}
	}
}