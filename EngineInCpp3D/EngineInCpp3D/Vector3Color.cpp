#include "Vector3Color.h"


Vector3Color::Vector3Color()
	:Vector3()
{
		color = sf::Color::Black;
}

Vector3Color::Vector3Color(float * p, sf::Color color1)
	: Vector3(p)
{
	color = color1;
}

Vector3Color::Vector3Color(float a, float b, float c, sf::Color color1)
	:Vector3(a, b, c)
{
	color = color1;
}

sf::Color Vector3Color::GetColor()
{
	return color;
}

void Vector3Color::SetColor(sf::Color color1)
{
	color = color1;
}

void Vector3Color::SetColor(int r, int g, int b, int a)
{
	color = sf::Color(r, g, b, a);
}

void Vector3Color::SetColor(int r, int g, int b)
{
	color = sf::Color(r, g, b);
}
