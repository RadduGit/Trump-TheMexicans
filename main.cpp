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
#define ecranx 1366	
#define ecrany 768
using namespace std;

unsigned int contorx = 0;

//sf::RenderWindow  win1(sf::VideoMode(ecranx, ecrany), "Trump & The Mexicans", sf::Style::Default);

vector <Entity*> object;

bool fin = 0;
int numcol;
/*void col(Player* p, Rock* r)
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
		numcol++;
		fin = 1;
		cout << fx1 << " " << fx2 << " " << sx1 << " " << sx2 << " " << fy1 << " " << fy2 << sy1 << " " << sy2 << "\n";
		cout << "Collision " << (intx2 - intx1)*(inty2 - inty1) << "\n";
		//system("pause");
		fin = 1;
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





void createRockThreat(vector <Entity*> object)
{
	while (!fin)
	{
		entityManager.spam(object);
		Sleep(25);
	}
}
*/

EntityManager EntityManager::entityManager;
EntityManager& entityManager = EntityManager::getHandle();
int main()
{   
	/*srand(unsigned int(time(NULL)));
	for (int i = 0; i < 100; i++)
		rand();
	object.push_back(new Player(140.0f, 200.0f, 1166.0f, 500.0f, 5.0f, "mex.png"));
	//entityManager.spam(object);
	
	sf::RectangleShape wall(sf::Vector2f((float) ecranx, (float) ecrany));
	sf::Texture back;
	back.setSmooth(true);
	back.loadFromFile("wall.jpg");
	wall.setTexture(&back);

    std::thread t1(PlayerThread, static_cast<Player*>(object[0]));
	Sleep(600);
	std::thread t2(createRockThreat, object);
	
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
		for (int i = 1; i < object.size(); ++i)
		{
			(static_cast < Rock* > (object[i]))->Descend();
			if (!(static_cast < Rock* > (object[i]))->InBounds())
			{
				object.erase(object.begin() + i);
			}
		}
		Sleep(5);
		++contorx;
	}


	
	t1.join();
	t2.join();
	
	win1.close();*/
	entityManager.start();
	return 0;
}



///De terminat coliziunea + spamarea random
///De vector cu stergeri si spamari noi
///De facut type la clasele tale
///Player este tip 1, pietrele
///sunt tip 2 si power-up este tip 3