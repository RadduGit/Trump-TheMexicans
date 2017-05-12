#include "Score.h"

using namespace std;

string to_string(int);


Score::Score(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	value = 0;
	speed = 1;
	text.setFont(font);
	text.setColor(sf::Color::White);
	ss = to_string(value);
	text.setString(ss);
	text.setPosition(sf::Vector2f(width / 11 * 10 , height / 10  ));
}

Score::~Score()
{

}

void Score::increaseSpeed()
{
	speed += 0.5;
}

void Score::increaseScore()
{
	value += speed;
	increaseSpeed();
}

void Score::draw(sf::RenderWindow &window)
{
	ss = to_string(value);
	cout << "Scor-ul este: " << ss << endl;
	text.setString(ss);
	window.draw(text);
	increaseScore();
}

void Score::reset()
{
	value = 0;
}

unsigned long long Score::showScore()
{
	return value;
}
