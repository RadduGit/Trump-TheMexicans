#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class Rock;

class Player : public Entity
{

public:
    Player(float, float, float, float, float, char[]);
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
    void Appear(sf::RenderWindow&);
	friend void Collision(Player* p, Rock* r);
	friend class EntityManager;
	friend class InputManager;
};


