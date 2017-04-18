#pragma once
#include <SFML/Graphics.hpp>


class Rock
{
public:
	float initx, inity, rx, ry, dimx, dimy, speed;
	sf::RectangleShape rock;
	sf::Texture rtext;
public:
	
	Rock(float, float, float, float, float, char[]);
	void Descend();
    void Appear(sf::RenderWindow&);
	bool InBounds();
    void Reestablish();
	
};
