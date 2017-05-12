#include "InputManager.h"
#include "player.h"
#include <iostream>
#include <thread>
#include <SFML\Graphics.hpp>

using namespace std;
extern bool fin;



void InputManager::CatchInput(Player* player1)
{
	while (!fin)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player1->MoveLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player1->MoveRight();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player1->MoveUp();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player1->MoveDown();
		}

		this_thread::sleep_for(std::chrono::milliseconds(15));
	 cout<<"Inp\n";
	}
}


