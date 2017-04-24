#include "player.h"

Player :: Player(float dim1, float dim2, float p1, float p2, float coef, char tpath[]) : Entity(dim1, dim2, p1, p2, coef, tpath)
{ }

void Player :: MoveRight()
{
	if (px + speed >= 0 && px + speed + dimx <= 1366)
	{
		shape.move(speed, 0.0f);
		px += speed;
	}
}

void Player :: MoveLeft()
{
	if (px - speed >= 0 && px - speed + dimx <= 1366)
	{
		shape.move(-speed, 0.0f);
		px -= speed;
	}
}

void Player :: MoveUp()
{
	if (py - speed >= 0 && py - speed + dimy <= 768)
	{
		shape.move(0.0f, -speed);
		py -= speed;
	}
}

void Player :: MoveDown()
{
	if (py + speed >= 0 && py + speed + dimy <= 768)
	{
		shape.move(0.0f, speed);
		py += speed;
	}
}

void Player :: Appear(sf::RenderWindow& window)
{
	window.draw(shape);
}
