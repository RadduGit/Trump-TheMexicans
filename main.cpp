#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>
#include <SFML/Audio.hpp>
#include <mutex>

#include "EntityManager.h"
#include "inputmanager.h"
#include "game.h"
#include "player.h"
#include "rock.h"
#include "entity.h"
#include "Menu.h"
#include "Help.h"
#include "Score.h"
#include "Highscores.h"
#include "SoundManager.h"
#define ecranx 1366
#define ecrany 768

using namespace std;
unsigned int contorx = 0;
unsigned int e = 1;

mutex mvect, mwin;

EntityManager EntityManager::instance;
InputManager InputManager::instance;

EntityManager& emanager = EntityManager::getHandle();
InputManager& imanager = InputManager::getHandle();


bool fin = 0;

sf::RenderWindow  winMenu(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans");

Score score(winMenu.getSize().x, winMenu.getSize().y);
Highscores highscores(ecranx, ecrany);
vector < unsigned int > highScore;

SoundManager gameMusic("playMusic.ogg");
SoundManager menuMusic("salsa.ogg");

int main()
{
    highscores.import();
	bool pressed = 0;
	int n;

	Menu menu(winMenu.getSize().x, winMenu.getSize().y);
	Help help(winMenu.getSize().x, winMenu.getSize().y);

    menuMusic.playSound();
cout<<"HELLO\n";
	sf::RectangleShape wal(sf::Vector2f((float)ecranx, (float)ecrany));
	sf::Texture bk;
	bk.setSmooth(true);
	bk.loadFromFile("trump.jpg");
	wal.setTexture(&bk);

    while (!fin)
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
					fin = 1;
				}
			}
            winMenu.clear();
			winMenu.draw(wal);
			menu.draw(winMenu);

			winMenu.display();


		}

		winMenu.clear();

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
		    menuMusic.stopSound();
			gameMusic.playSound();

			Game Trump_TheMexs(1366, 768, "Trump & The Mexicans");

			Trump_TheMexs.Init();

            gameMusic.stopSound();
			menuMusic.playSound();

            fin = 0;
   cout<<"Finish";
			e = 1;
			winMenu.clear();
		}
	}
	winMenu.close();


cout<<"Cacat!" << endl;
	return 0;
}



