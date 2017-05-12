#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>

#include "EntityManager.h"
#include "player.h"
#include "rock.h"
#include "entity.h"
#include "Menu.h"
#include "Help.h"
#include "Score.h"
#include "Highscores.h"
#define ecranx 1366	
#define ecrany 768
using namespace std;

unsigned int contorx = 0;
unsigned int e = 1;

//sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans", sf::Style::Default);

vector <Entity*> object;
vector < unsigned int > highScore;

Highscores highscores(ecranx, ecrany);

bool fin = 0;
int numcol;
sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans");

Score score(win1.getSize().x, win1.getSize().y);

EntityManager EntityManager::entityManager;
EntityManager& entityManager = EntityManager::getHandle();
int main()
{   
	highscores.import();
	bool pressed = 0, f = 1;
	int n;

	Menu menu(win1.getSize().x, win1.getSize().y);
	Help help(win1.getSize().x, win1.getSize().y);
	//sf::Event event;
	


	while (f)
	{
		while (e == 1)
		{
			if (pressed == 1)
			{
				Sleep(150);
			}
			pressed = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				menu.moveUp();
				pressed = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				menu.moveDown();
				pressed = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
			{
				pressed = 1;
				cout << e << endl;
				if (menu.returnCurrentItem() == 0)
				{
					e = 0;
				}
				else if (menu.returnCurrentItem() == 1)
				{
					e = 2;
				}
				else if (menu.returnCurrentItem() == 2)
				{
					e = 3;
				}
				else if (menu.returnCurrentItem() == 3)
				{
					e = 4;
					f = 0;
				}
			}
			menu.draw(win1);
			win1.display();
		}

		win1.clear();

		if (e == 2)
		{
			sf::RenderWindow  win2(sf::VideoMode(ecranx, ecrany), "Trump & The Mexican");
			win2.clear();
			help.draw(win2);
			win2.display();
			Sleep(300);
			while (e == 2)
			{
				help.draw(win2);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
				{
					e = 1;
				}
			}
			win2.clear();
			win2.close();
		}

		if (e == 3)
		{
			highscores.import();
			highscores.saveHighscores();
			sf::RenderWindow  win3(sf::VideoMode(ecranx, ecrany), "Trump & The Mexican");
			win3.clear();
			highscores.draw(win3);
			win3.display();
			Sleep(300);
			while (e == 3)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
				{
					e = 1;
				}
			}
			win3.clear();
			win3.close();
			
		}

		if (e == 0)
		{
			entityManager.start();
			e = 1;
			win1.clear();
		}
	}

	return 0;
}


