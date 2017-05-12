#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>

class Score
{
private:
	std::string ss;
	unsigned long long value, speed;
	void increaseSpeed();
	void increaseScore();
	sf::Font font;
	sf::Text text;
public:
	Score(float width, float height);
	~Score();
	void draw(sf::RenderWindow &window);
	void reset();
	unsigned long long showScore();
	

};