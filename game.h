#include <SFML/Graphics.hpp>
#include <vector>
#include "EntityManager.h"
#include "inputmanager.h"
#include "entity.h"
using namespace std;
class Game{

    vector <Entity*> object;

	sf::RenderWindow  win1;
	sf::RectangleShape background;
	sf::Texture backtexture;

	Game(const Game&);
	void operator=(Game&);
    friend class EntityManager;
public:

	Game(float ex, float ey, string name) : win1(sf::VideoMode(ex, ey), name, sf::Style::Default),
	  background(sf::Vector2f((float)ex, (float)ey))
	{

	   backtexture.setSmooth(true);
	   backtexture.loadFromFile("wall.jpg");
	   background.setTexture(&backtexture);
	}

    void Init();

};
