#include "EntityManager.h"
#include <windows.h>
#include <thread>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>

#include"EntityManager.h"
#include "player.h"
#include "rock.h"
#include "entity.h"
#define ecranx 1366	
#define ecrany 768
using namespace std;

bool EntityManager::verifSpam(vector < Entity* > &obj, int poz)
{
	unsigned int spam1 = 0, final1, inceput1;
	int j;
	bool A[1500];
	for (int i = 0; i < 1367; ++i)
	{
		A[i] = false;
	}
	for (int i = 0; i < obj.size(); ++i)
	{
		if (obj[i]->tip == 2)
		{
			if ((static_cast <Rock*> (obj[i]))->py <= 200)
			{
				//cout << "salam" << endl;

				inceput1 = (static_cast <Rock*> (obj[i]))->px - 20;
				final1 = (static_cast <Rock*> (obj[i]))->px + 145;
				cout << inceput1 << " " << final1 << endl;
				for (int j = inceput1; j <= final1; ++j)
				{
					A[j] = true;
					//cout << "paine" << endl;
				}
			}
		}
	}

	if (poz - 300 < 0 || poz - 300 > 2000)
	{
		inceput1 = 0;
	}
	else
	{
		inceput1 = poz - 300;
	}

	if (poz + 500 >= 1367)
	{
		final1 = 1367;
	}
	else
	{
		final1 = poz + 500;
	}
	cout << inceput1 << " " << final1 << endl;
	cout << poz << endl;
	for (int j = inceput1; j < final1; ++j)
	{
		if (A[j] == true)
		{
			cout << "cacpula" << endl;
			return false;
		}
	}
	for (int j = poz - 20; j < poz + 145 ; ++j)
	{
		A[j] = true;
	}
	for (int i = 0; i < 1367; ++i)
	{
		if (A[i] == false)
		{
			++spam1;
		}
		else
		{
			spam1 = 0;
		}
		if (spam1 >= 142)
		{
				return true;
		}
	}
	
}

void EntityManager::spam(vector < Entity* > &obj)
{
	
	int poz;
	if (obj.size() < 10)
	{
		poz = rand() % 1150 + 50;
		while (!verifSpam(obj, poz) && !fin)
		{
			poz = rand() % 1150 + 50;
		
		}
		cout << "1" << endl;
		obj.push_back(new Rock(140.0f, 100.0f, poz, -140.0f, 3.0f, "rock1.png"));
	}
}

void EntityManager::col(Player *p, Rock *r)
{
	int fx1 = p->px, fx2 = p->px + p->dimx, fy1 = p->py, fy2 = p->py + p->dimy;
	int sx1 = r->px, sx2 = r->px + r->dimx, sy1 = r->py, sy2 = r->py + r->dimy;

	int isx = 0, isy = 0, intx1 = 0, intx2 = 0, inty1 = 0, inty2 = 0;

	if (fx1 < sx1)
	{
		if (fx2 >= sx1)
		{
			isx = 1;
			intx1 = sx1;
			intx2 = min(sx2, fx2);
		}
	}
	else
		if (fx1 <= sx2)
		{
			isx = 1;
			intx1 = fx1;
			intx2 = min(sx2, fx2);
		}

	if (fy1 < sy1)
	{
		if (fy2 >= sy1)
		{
			isy = 1;
			inty1 = sy1;
			inty2 = min(sy2, fy2);
		}
	}
	else
		if (fy1 <= sy2)
		{
			isy = 1;
			inty1 = fy1;
			inty2 = min(sy2, fy2);
		}

	if (isx && isy && (intx2 - intx1)*(inty2 - inty1) > 2000)
	{
		fin = 1;
		cout << fx1 << " " << fx2 << " " << sx1 << " " << sx2 << " " << fy1 << " " << fy2 << sy1 << " " << sy2 << "\n";
		cout << "Collision " << (intx2 - intx1)*(inty2 - inty1) << "\n";
		//system("pause");
		//fin = 1;
	}
}

void EntityManager::createRockThread()
{
	while (!fin)
	{
		entityManager.spam(object);
		Sleep(25);
	}
	cout << "pula1" << endl;
}

void EntityManager::PlayerThread(Player* player1)
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
		Sleep(5);
	}
	cout << "pula2" << endl;
}

void EntityManager::start()
{
	fin = 0;
	sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans", sf::Style::Default);
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < 100; i++)
		rand();
	object.push_back(new Player(140.0f, 200.0f, 1166.0f, 500.0f, 5.0f, "mex.png"));

	sf::RectangleShape wall(sf::Vector2f((float)ecranx, (float)ecrany));
	sf::Texture back;
	back.setSmooth(true);
	back.loadFromFile("wall.jpg");
	wall.setTexture(&back);

	std::thread t1(PlayerThread, (static_cast<Player*>(object[0])) );
	Sleep(600);
	std::thread t2(createRockThread);

	while (!fin)
	{
		win1.clear();
		win1.draw(wall);
		for (unsigned int i = 0; i < object.size(); ++i)
		{
			object[i]->Appear(win1);
			if (i != 0)
			{
				col(static_cast <Player*> (object[0]), static_cast <Rock*> (object[i]));
			}
		}
		score.draw(win1);
		win1.display();

		sf::Event ev1;
		/*while (win1.pollEvent(ev1))
		{
			switch (ev1.type)
			{
			case sf::Event::Closed:
				win1.close();
				fin = 1;
				break;
			}
		}*/
		for (int i = 1; i < object.size(); ++i)
		{
			(static_cast < Rock* > (object[i]))->Descend();
			if (!(static_cast < Rock* > (object[i]))->InBounds())
			{
				object.erase(object.begin() + i);
			}
		}
		Sleep(5);
	}
	highscores.addHighscore(score.showScore());
	score.reset();

	object.clear();

	t1.join();
	t2.join();

	object.clear();

	object.resize(0);

	win1.close();
	cout << "pula3!" << endl;
}
