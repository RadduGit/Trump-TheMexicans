#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>

#include "player.h"
#include "rock.h"
#include "entity.h"
#define ecranx 1366	
#define ecrany 768
using namespace std;

sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans", sf::Style::Default);

vector <Entity*> object;

bool fin = 0;
int numcol;
void col(Player* p, Rock* r)
{ 
	if (r->py + r->dimy >= p->py && ((r->px >= p->px && r->px <= p->px + p->dimx) || 
		(r->px + r->dimx >= p->px && r->px + r->dimx <= p->px + p->dimx))  )
	{   
		numcol++;
		fin = 1;
		cout << "Collision " << numcol << "\n" ;
	}
}

void PlayerThread(Player* player1)
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
		Sleep(10);
	}
}

int main()
{   
	object.push_back(new Player(140.0f, 200.0f, 1166.0f, 500.0f, 5.0f, "mex.png"));
	object.push_back(new Rock(140.0f, 100.0f, 100.0f, -140.0f, 6.0f, "rock1.png"));
	object.push_back(new Rock(140.0f, 100.0f, 400.0f, -140.0f, 5.0f, "rock1.png"));
	object.push_back(new Rock(140.0f, 100.0f, 700.0f, -140.0f, 4.0f, "rock1.png"));
	object.push_back(new Rock(140.0f, 100.0f, 1000.0f, -140.0f, 3.0f, "rock1.png"));
	
	sf::RectangleShape wall(sf::Vector2f((float) ecranx, (float) ecrany));
	sf::Texture back;
	back.loadFromFile("wall.jpg");
	wall.setTexture(&back);

    std::thread t1(PlayerThread, static_cast<Player*>(object[0]));
	Sleep(300);
	std::thread t2(RockThread,static_cast<Rock*>(object[1]));
	Sleep(300);
	std::thread t3(RockThread, static_cast<Rock*>(object[2]));
	Sleep(500);
	std::thread t4(RockThread, static_cast<Rock*>(object[3]));
	Sleep(500);
	std::thread t5(RockThread, static_cast<Rock*>(object[4]));

	t1; t2; t3; t4; t5;
	
	while (!fin)
	{
		win1.clear();
		win1.draw(wall);
		for (int i = 0; i < object.size(); ++i)
		{
			object[i]->Appear(win1);
			if (i != 0)
			{
				col(static_cast <Player*> (object[0]), static_cast <Rock*> (object[i]));
			}
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



///De terminat coliziunea + spamarea random
///De vector cu stergeri si spamari noi
///De facut type la clasele tale
///Player este tip 1, pietrele
///sunt tip 2 si power-up este tip 3