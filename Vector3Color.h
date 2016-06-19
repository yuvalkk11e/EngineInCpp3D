
#pragma once
#include "CommonHeaders.h"

class Vector3Color : public Vector3
{
private:
	float values[3];
	sf::Color color;

public:
	sf::Color GetColor();
	void SetColor(sf::Color color1);
	void SetColor(int r, int g, int b, int a);
	void SetColor(int r, int g, int b);
	Vector3Color(float * p, sf::Color color);
	Vector3Color(float a, float b, float c, sf::Color);
	Vector3Color();
	//~Vector3()
};