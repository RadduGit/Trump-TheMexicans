#pragma once
#include "SFML\Graphics.hpp"

class Help
{
private:
	sf::Font font;
	sf::Text text[5];


public:
	Help(float width, float height);
	~Help();

	void draw(sf::RenderWindow & window);
};