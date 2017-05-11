#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>

#include"EntityManager.h"
#include "player.h"
#include "rock.h"
#include "entity.h"
#include "Menu.h"
#define ecranx 1366	
#define ecrany 768
using namespace std;

unsigned int contorx = 0;

//sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans", sf::Style::Default);

vector <Entity*> object;

bool fin = 0;
int numcol;
sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans");

EntityManager EntityManager::entityManager;
EntityManager& entityManager = EntityManager::getHandle();
int main()
{   
	unsigned int e = 1;
	bool pressed = 0, f = 1;
	int n;

	Menu menu(win1.getSize().x, win1.getSize().y);
	sf::Event event;
	


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
					f = 0;
				}
			}
			menu.draw(win1);
			win1.display();
		}

		win1.clear();
		win1.create(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans");
		if (e == 0)
		{
			entityManager.start();
			win1.clear();
			win1.create(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans");
			e = 1;
		}
	}

	return 0;
}



///De terminat coliziunea + spamarea random
///De vector cu stergeri si spamari noi
///De facut type la clasele tale
///Player este tip 1, pietrele
///sunt tip 2 si power-up este tip 3