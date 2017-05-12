#include <windows.h>
#include <thread>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <thread>
#include <vector>
#include <mutex>
#include "Score.h"

#include "EntityManager.h"
#include "player.h"
#include "Highscores.h"
#include "rock.h"
#include "entity.h"
#define ecranx 1366
#define ecrany 768
using namespace std;

extern Score score;
extern Highscores highscores;

class Game;
extern sf::RenderWindow  win1;
extern sf::RectangleShape wall;

extern EntityManager& emanager;

extern mutex mvect, mwin;
mutex m;
bool EntityManager::verifSpam(vector < Entity* > &obj, int poz)
{
	unsigned int spam1 = 0, final1, inceput1;
	int j;
	bool A[1500];

    memset(A, 0, sizeof(A));


	for (int i = 0; i < obj.size(); ++i)
	{
		if (obj[i]->tip == 2)
		{
		    mvect.lock();

			if ((static_cast <Rock*> (obj[i]))->py <= 200)
			{

				inceput1 = (static_cast <Rock*> (obj[i]))->px - 20;
				final1 = (static_cast <Rock*> (obj[i]))->px + 145;

				mvect.unlock();


				for (int j = inceput1; j <= final1; ++j)
				   A[j] = true;
			}
			else
                mvect.unlock();
		}
	}

	if (poz - 200 < 0 || poz - 200 > 2000)
	{
		inceput1 = 0;
	}
	else
	{
		inceput1 = poz - 200;
	}

	if (poz + 350 >= 1367)
	{
		final1 = 1367;
	}
	else
	{
		final1 = poz + 350;
	}

	for (int j = inceput1; j < final1; ++j)
	{
		if (A[j] == true)
		{

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

bool EntityManager::isCollision(Player *p, Rock *r)
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
        return true;
		//cout << fx1 << " " << fx2 << " " << sx1 << " " << sx2 << " " << fy1 << " " << fy2 << sy1 << " " << sy2 << "\n";
		//cout << "Collision " << (intx2 - intx1)*(inty2 - inty1) << "\n";

	}

    return false;
}

void EntityManager::Spam(vector<Entity*>& obj)
{   int poz;

	while (!fin)
	{
		if (obj.size() < 10)
	    {

        poz = rand() % 1150 + 50;

		while (!emanager.verifSpam(obj, poz) && !fin)
		{
			poz = rand() % 1150 + 50;

		}

		mvect.lock();
		obj.push_back(new Rock(140.0f, 100.0f, poz, -140.0f, 2.0f,"rock1.png"));
        mvect.unlock();

	    }
		this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void EntityManager::Iterate(vector <Entity*>& obj, sf::RenderWindow& win1, sf::RectangleShape& wall)
{
	srand(time(NULL));

	while (!fin)
	{
		win1.clear();
		win1.draw(wall);

		for (int i = 0; i < obj.size(); ++i)
		{
         if (i && isCollision(static_cast <Player*> (obj[0]), static_cast <Rock*> (obj[i])))
			  fin = 1;

         if (i)
         {
            (static_cast < Rock* > (obj[i]))->Descend();

			if (!(static_cast < Rock* > (obj[i]))->InBounds())
			{
			    mvect.lock();

               cout << i << " " << obj.size() << "\n";
			   delete obj[i];

			    obj[i] = obj[obj.size()-1];
				obj.pop_back();

			    mvect.unlock();
			}
         }
         obj[i]->Appear(win1);
		}

        score.draw(win1);
        win1.display();


	}

	highscores.addHighscore(score.showScore());
	score.reset();


}
