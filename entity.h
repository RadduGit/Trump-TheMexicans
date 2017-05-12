#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Entity
{
protected:
	float px, py, dimx, dimy, speed;
	sf::RectangleShape shape;
	sf::Texture text;
public:
	Entity(float, float, float, float, float, char[]);
	~Entity() {}
	void Appear(sf::RenderWindow&);
	unsigned int tip = 1;
	friend class EntityManager;

};
