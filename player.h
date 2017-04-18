#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	float px, py, dimx, dimy, speed;
	sf::RectangleShape player;
	sf::Texture ptext;
public:
    Player(float, float, float, float, float, char[]);
	void MoveRight();
	void MoveLeft();
    void Appear(sf::RenderWindow&);
	
};
