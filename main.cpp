#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>
#include <stdlib.h> 
#include <time.h> 

#include "player.h"
#include "rock.h"

using namespace std;

bool verifSpam(const std::vector<Rock*> rock, int poz)
{
	int spam = 0;
	bool A[1500];
	for (int i = 0; i < 1367; ++i)
	{
		A[i] = 0;
	}
	for (int i = 0; i < rock.size(); ++i)
	{
		if (rock[i]->ry <= 600)
		{
			for (int j = rock[i]->initx - 5; j < rock[i]->initx + 145; ++j)
			{
				A[j] = 1;
			}
		}
	}
	for (int j = poz - 5; j < poz + 145; ++j)
	{
		A[j] = 1;
	}
	for (int i = 0; i < 1367; ++i)
	{
		if (A[i] == 0)
		{
			++spam;
		}
		else
		{
			spam = 0;
		}
		if (spam >= 142)
		{
			return 1;
		}
	}
	return 0;
}

sf::RenderWindow  win1(sf::VideoMode(1366, 768), "Trump & The Mexicans", sf::Style::Default);
Player* player1 = new Player(140.0f, 200.0f, 500.0f, 500.0f, 5.0f, "mex.png");
Rock* rock1 = new Rock(140.0f, 100.0f, 100.0f, -140.0f, 5.0f, "rock1.png");
Rock* rock2 = new Rock(140.0f, 100.0f, 400.0f, -140.0f, 4.0f, "rock1.png");
Rock* rock3 = new Rock(140.0f, 100.0f, 700.0f, -140.0f, 3.0f, "rock1.png");
Rock* rock4 = new Rock(140.0f, 100.0f, 1000.0f, -140.0f, 2.0f, "rock1.png");
vector <Rock*> rock;
bool fin = 0;
int numcol;
int poz;
void col(Player* p, Rock* r)
{
	if (r->ry + r->dimy >= p->py && ((r->rx >= p->px && r->rx <= p->px + p->dimx) ||
		(r->rx + r->dimx >= p->px && r->rx + r->dimx <= p->px + p->dimx)))
	{
		numcol++;
		cout << "Collision " << numcol << "\n";
	}
}

void PlayerThread()
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

		Sleep(5);
	}
}

void RockThread(Rock* rock1)
{
	while (!fin)
	{
		rock1->Descend();
		if (!rock1->InBounds())
		{
			rock1->Reestablish();
		}
		Sleep(5);
	}
}

int main()
{
	srand(time(NULL));
	poz = rand() % 1200;
	while (rock.size() < 4)
	{
		poz = rand() % 1200;
		if (verifSpam(rock, poz))
		{
			rock.push_back(new Rock(140.0f, 100.0f, poz, -140.0f, 3.0f, "rock1.png"));
		}
		Sleep(500);
	}
	sf::RectangleShape wall(sf::Vector2f(1366.0f, 768.0f));
	sf::Texture back;
	back.loadFromFile("wall.jpg");
	wall.setTexture(&back);

std::thread t1(PlayerThread);
	std::thread t2(RockThread,rock[0]);
	Sleep(500);
	std::thread t3(RockThread,rock[1]);
	Sleep(500);
	std::thread t4(RockThread, rock[2]);
	Sleep(500);
	std::thread t5(RockThread, rock[3]);

	t1; t2; t3; t4; t5;

	while (!fin)
	{

		win1.clear();
		win1.draw(wall);
		player1->Appear(win1);
		for (int i = 0; i < rock.size(); ++i)
		{
			rock[i]->Appear(win1);
			col(player1, rock[i]);
		}
		win1.display();
		sf::Event ev1;
        
		while (win1.pollEvent(ev1))
		{
			switch (ev1.type)
			{
			case sf::Event::Closed:
				win1.close();
				fin = 1;
				break;
			}
		}	
	}
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	return 0;
}



