#include "player.h"

Player :: Player(float dim1, float dim2, float p1, float p2, float coef, char tpath[]) : speed(coef), px(p1), py(p2), dimx(dim1), dimy(dim2), player(sf::Vector2f(dim1, dim2))
{
	ptext.loadFromFile(tpath);
	player.setTexture(&ptext);
	player.setPosition(px, py);
}

void Player :: MoveRight()
{
	if (px + speed >= 0 && px + speed + dimx <= 1366)
	{
		player.move(speed, 0.0f);
		px += speed;
	}
}

void Player :: MoveLeft()
{
	if (px - speed >= 0 && px - speed + dimx <= 1366)
	{
		player.move(-speed, 0.0f);
		px -= speed;
	}
}

void Player :: Appear(sf::RenderWindow& window)
{
	window.draw(player);
}