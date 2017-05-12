#pragma once
#include <SFML/Graphics.hpp>
#include<vector>

#include <stdlib.h>


using namespace std;

class Entity;
class Player;
class Rock;

extern bool fin;
extern int numcol;



class EntityManager {

	static EntityManager instance;
	EntityManager() {}
	void operator=(EntityManager&);
	EntityManager(const EntityManager&);

public:
	static EntityManager& getHandle() {
		return instance;
	}
	 bool verifSpam(vector <Entity*>&, int);
	 void spam(vector <Entity*>&);
	 static void PlayerThread(Player*);
	 static void Spam(vector <Entity*>&);
	 bool isCollision(Player*, Rock*);
     void Iterate(vector <Entity*>&, sf::RenderWindow& win1,sf::RectangleShape& wall);
};


