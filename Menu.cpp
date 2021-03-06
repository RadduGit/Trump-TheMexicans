#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}
	text[0].setStyle(sf::Text::Bold);
    text[0].setCharacterSize(60);
	text[0].setFont(font);
	text[0].setColor(sf::Color::Red);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(10.0f, height / 5 * 1));

	text[1].setStyle(sf::Text::Bold);
    text[1].setCharacterSize(60);
	text[1].setFont(font);
	text[1].setColor(sf::Color::Black);
	text[1].setString("Help");
	text[1].setPosition(sf::Vector2f(10.0f, height / 5 * 2));

    text[2].setStyle(sf::Text::Bold);
    text[2].setCharacterSize(60);
	text[2].setFont(font);
	text[2].setColor(sf::Color::Black);
	text[2].setString("Highscores");
	text[2].setPosition(sf::Vector2f(10.0f, height / 5 * 3));

	text[3].setStyle(sf::Text::Bold);
	text[3].setCharacterSize(60);
	text[3].setFont(font);
	text[3].setColor(sf::Color::Black);
	text[3].setString("Exit");
	text[3].setPosition(sf::Vector2f(10.0f, height / 5 * 4));

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
		text[currentItem].setFillColor(sf::Color::Black);
		--currentItem;
		text[currentItem].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (currentItem + 1 < 4)
	{
		text[currentItem].setFillColor(sf::Color::Black);
		++currentItem;
		text[currentItem].setFillColor(sf::Color::Red);
	}
}

unsigned int Menu::returnCurrentItem()
{
	return this->currentItem;
}
