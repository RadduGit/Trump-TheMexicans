#pragma once
#include"SFML\Graphics.hpp"

class Menu
{

private:
	unsigned int currentItem;
	sf::Font font;
	sf::Text text[4];


public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow & window);
	void moveUp();
	void moveDown();
	unsigned int returnCurrentItem();

};