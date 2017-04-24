#include "rock.h"
Rock :: Rock(float dim1, float dim2, float p1, float p2, float coef, char tpath[]) : speed(coef), rx(p1), ry(p2), dimx(dim1), dimy(dim2), rock(sf::Vector2f(dim1, dim2))
{
	initx = p1;
	inity = p2;
	rtext.loadFromFile(tpath);
	rock.setTexture(&rtext);
	rock.setPosition(rx, ry);
}

void Rock :: Descend()
{
	rock.move(0.0f, speed);
	ry += speed;
}

void Rock :: Appear(sf::RenderWindow& window)
{
	window.draw(rock);
}

bool Rock :: InBounds()
{
	return ry <= 768.0f;
}

void Rock :: Reestablish()
{
	rx = initx;
	ry = inity;
	rock.setPosition(initx, inity);
}
