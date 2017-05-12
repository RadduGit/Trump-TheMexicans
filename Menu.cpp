#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	text[0].setFont(font);
	text[0].setColor(sf::Color::Black);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(width / 2, height / 5 * 1));

	text[1].setFont(font);
	text[1].setColor(sf::Color::White);
	text[1].setString("Help");
	text[1].setPosition(sf::Vector2f(width / 2, height / 5 * 2));

	text[2].setFont(font);
	text[2].setColor(sf::Color::White);
	text[2].setString("Highscores");
	text[2].setPosition(sf::Vector2f(width / 2, height / 5 * 3));

	text[3].setFont(font);
	text[3].setColor(sf::Color::White);
	text[3].setString("Exit");
	text[3].setPosition(sf::Vector2f(width / 2, height / 5 * 4));

	currentItem = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; ++i)
	{
		window.draw(text[i]);
	}
}

void Menu::moveUp()
{
	if (currentItem > 0)
	{
		text[currentItem].setFillColor(sf::Color::White);
		--currentItem;
		text[currentItem].setFillColor(sf::Color::Black);
	}
}

void Menu::moveDown()
{
	if (currentItem + 1 < 4)
	{
		text[currentItem].setFillColor(sf::Color::White);
		++currentItem;
		text[currentItem].setFillColor(sf::Color::Black);
	}
}

unsigned int Menu::returnCurrentItem()
{
	return this->currentItem;
}