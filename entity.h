#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Entity
{
protected:
	float px, py, dimx, dimy, speed;
	unsigned int tip = 1;
	sf::RectangleShape shape;
	sf::Texture text;
public:
	Entity(float, float, float, float, float, char[]);
	void Appear(sf::RenderWindow&);
	
};
