#include "rock.h"
#include <iostream>
using namespace std;
Rock :: Rock(float dim1, float dim2, float p1, float p2, float coef, char tpath[]) : Entity(dim1, dim2, p1, p2, coef, tpath)
{
	initx = p1;
	inity = p2;
	tip = 2;
}

void Rock :: Descend()
{
	shape.move(0.0f, speed);
	py += speed;
	speed += 0.01f;
}

bool Rock :: InBounds()
{
	return py <= 668.0f;
}

void Rock :: Reestablish()
{
	px = initx;
	py = inity;
	shape.setPosition(initx, inity);
}
