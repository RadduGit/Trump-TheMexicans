#include"Help.h"

Help::Help(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	text[0].setFont(font);
	text[0].setColor(sf::Color::White);
	text[0].setString("In this game, you are a Mexican and you try to reach America by climbing the wall built by");
	text[0].setPosition(sf::Vector2f(width / 9, height / 6 * 1));

	text[1].setFont(font);
	text[1].setColor(sf::Color::White);
	text[1].setString("Donald Trump!");
	text[1].setPosition(sf::Vector2f(width / 9, height / 6 * 2));

	text[2].setFont(font);
	text[2].setColor(sf::Color::White);
	text[2].setString("You have to move with WASD to dodge the stones that are trying to stop you!");
	text[2].setPosition(sf::Vector2f(width / 9, height / 6 * 3));

	text[3].setFont(font);
	text[3].setColor(sf::Color::White);
	text[3].setString("Good Luck!");
	text[3].setPosition(sf::Vector2f(width / 9, height / 6 * 4));

	text[4].setFont(font);
	text[4].setColor(sf::Color::Red);
	text[4].setString("Press Enter to go back to the Menu");
	text[4].setPosition(sf::Vector2f(width / 9, height / 6 * 5));
}

void Help::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 5; ++i)
	{
		window.draw(text[i]);
	}
}

Help::~Help()
{

}