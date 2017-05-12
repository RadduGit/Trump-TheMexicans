#include "game.h"
#include "windows.h"
#include "player.h"
#include <thread>
#include <mutex>
extern vector<Entity*>object;
extern InputManager& imanager;
extern EntityManager& emanager;
extern bool fin;
extern mutex mvect;

void Game::Init()
{
    Sleep(600);



    object.push_back(new Player(140.0f, 200.0f, 1166.0f, 500.0f, 16.0f, "mex.png"));

    thread inputThread(&InputManager::CatchInput, &imanager, static_cast<Player*> (object[0]));
    thread SpamThread(&emanager.Spam, std::ref(object));

    emanager.Iterate(object, win1, background);

    sf::Event ev1;
     while(!fin)
     {

		while (win1.pollEvent(ev1))
		{
			switch (ev1.type)
			{
			case sf::Event::Closed:

               mvect.lock();

			    while(!object.empty())
                {
                    delete object[object.size() - 1];
                    object.pop_back();
                }


                mvect.unlock();
                win1.close();
				fin = 1;

				break;

			}
		}

     }

    win1.close();

    inputThread.join();
    SpamThread.join();

}
