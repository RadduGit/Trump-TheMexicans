#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>

#include "player.h"
#include "rock.h"

using namespace std;

sf::RenderWindow  win1(sf::VideoMode(1366, 768), "Trump & The Mexicans", sf::Style::Default);
Player* player1 = new Player(140.0f, 200.0f, 500.0f, 500.0f, 5.0f, "mex.png");
Rock* rock1 = new Rock(140.0f, 100.0f, 100.0f, -140.0f, 5.0f, "rock1.png");
Rock* rock2 = new Rock(140.0f, 100.0f, 400.0f, -140.0f, 4.0f, "rock1.png");
Rock* rock3 = new Rock(140.0f, 100.0f, 700.0f, -140.0f, 3.0f, "rock1.png");
Rock* rock4 = new Rock(140.0f, 100.0f, 1000.0f, -140.0f, 2.0f, "rock1.png");
bool fin = 0;
int numcol;
void col(Player* p, Rock* r)
{ 
	if (r->ry + r->dimy >= p->py && ((r->rx >= p->px && r->rx <= p->px + p->dimx) || 
		(r->rx + r->dimx >= p->px && r->rx + r->dimx <= p->px + p->dimx))  )
	{   
		numcol++;
		cout << "Collision " << numcol << "\n" ;
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
	sf::RectangleShape wall(sf::Vector2f(1366.0f, 768.0f));
	sf::Texture back;
	back.loadFromFile("wall.jpg");
	wall.setTexture(&back);

std::thread t1(PlayerThread);
	std::thread t2(RockThread,rock1);
	Sleep(300);
	std::thread t3(RockThread,rock2);
	Sleep(500);
	std::thread t4(RockThread, rock3);
	Sleep(500);
	std::thread t5(RockThread, rock4);

	t1; t2; t3; t4; t5;

	while (!fin)
	{
		win1.clear();
		win1.draw(wall);
		player1->Appear(win1);
		rock1->Appear(win1);
		col(player1, rock1);
		rock2->Appear(win1);
		col(player1, rock2);
		rock3->Appear(win1);
		col(player1, rock3);
		rock4->Appear(win1);
		col(player1, rock4);
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



