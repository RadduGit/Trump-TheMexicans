#pragma once
#include "SFML\Graphics.hpp"
#include<vector>
#include<fstream>
#include <string>


using namespace std;
extern vector < unsigned int > highScore;
class Highscores
{
private:
	sf::Font font;
	sf::Text text;
	float width, height;


public:
	Highscores(float width, float height);
	~Highscores();

	void import();
	void saveHighscores();
	void draw(sf::RenderWindow & window);
	void addHighscore(unsigned long long);
};
