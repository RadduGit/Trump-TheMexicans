#pragma once

#include<vector>

#include "entity.h"
#include "rock.h"
#include "player.h"
#include "Score.h"
#include "Highscores.h"
#include <stdlib.h>


using namespace std;

extern vector <Entity*> object;
extern bool fin;
extern int numcol;
extern Score score;
extern Highscores highscores;
//extern sf::RenderWindow  win1;

class EntityManager {
	
	static EntityManager entityManager;
	EntityManager()
	{

	};
	void operator=(EntityManager&);
	EntityManager(const EntityManager&);
public:
	static EntityManager& getHandle() {
		return entityManager;
	}
	 bool verifSpam(vector <Entity*> &, int);
	 void spam(vector <Entity*> &);
	 void start();
	 static void PlayerThread(Player *);
	 static void createRockThread();
	 void col(Player *p, Rock *r);
	
	 //friend void PlayerThread(Player *);
	 //friend void createRockThreat(vector <Entity*> );

};

	