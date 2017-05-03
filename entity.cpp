#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
Entity::Entity(float dim1, float dim2, float p1, float p2, float coef, char tpath[]) : speed(coef), px(p1), py(p2), dimx(dim1),
																						dimy(dim2), shape(sf::Vector2f(dim1, dim2))
{
	text.loadFromFile(tpath);
	shape.setTexture(&text);
	shape.setPosition(px, py);

}

void Entity::Appear(sf::RenderWindow& window)
{
	window.draw(shape);
}
