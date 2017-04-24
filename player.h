#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
class Player : public Entity
{

public:
    Player(float, float, float, float, float, char[]);
	void MoveRight();
	void MoveLeft();
    void Appear(sf::RenderWindow&);
	
};
