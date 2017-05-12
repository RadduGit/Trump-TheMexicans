#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
Entity::Entity(float dim1, float dim2, float p1, float p2, float coef, char tpath[]) : px(p1), py(p2), dimx(dim1), dimy(dim2), shape(sf::Vector2f(dim1, dim2)), speed(coef)
{
	text.loadFromFile(tpath);
	text.setSmooth(true);
	shape.setTexture(&text);
	shape.setPosition(px, py);

}

void Entity::Appear(sf::RenderWindow& window)
{
	window.draw(shape);
}

