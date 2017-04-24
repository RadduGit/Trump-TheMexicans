#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"

class Rock : public Entity
{
private:
	float initx, inity;
public:
	Rock(float, float, float, float, float, char[]);
	void Descend();
	bool InBounds();
    void Reestablish();	
};
