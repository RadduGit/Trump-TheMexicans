#include "Highscores.h"
#include <string>
Highscores::Highscores(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	this->width = width;
	this->height = height;




}

Highscores::~Highscores()
{

}

void Highscores::import()
{
	highScore.clear();
	highScore.resize(0);
	unsigned long long a;
	ifstream fin("fisier.txt");
	while (fin >> a)
	{
		highScore.push_back(a);
	}
	//highScore.pop_back();
	fin.close();
}

void Highscores::saveHighscores()
{
	ofstream fout("fisier.txt");
	for (int i = 0; i < highScore.size(); ++i)
	{
		fout << highScore[i] << " ";
	}
	fout.close();
}

void Highscores::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < highScore.size(); ++i)
	{
		text.setFont(font);
		text.setColor(sf::Color::Green);
		string ss;
		ss = "High Score #";

		ss += to_string(i + 1);
		ss += " : ";
		ss += to_string(highScore[i]);
		text.setPosition(sf::Vector2f(width / 3, height / 13 * (i + 1)));
		text.setString(ss);
		window.draw(text);
	}
	text.setFont(font);
	text.setColor(sf::Color::Red);
	text.setString("Press Enter to go back to the Menu");
	text.setPosition(sf::Vector2f(width / 4 + 20 , height / 13 * 11));
	window.draw(text);
}

void Highscores::addHighscore(unsigned long long x)
{
	int i, p, pf = 0;
	if (highScore.size() < 10)
	{
		pf = 1;
		highScore.push_back(x);
		i = highScore.size() - 2;
		while (i >= 0)
		{
			if (highScore[i] < x)
			{
				p = highScore[i];
				highScore[i] = highScore[i + 1];
				highScore[i + 1] = p;
			}
				--i;
		}
	}
	else
	{
		if (highScore[9] < x)
		{
			pf = 1;
			highScore[9] = x;
			i = highScore.size() - 2;
			while (i >= 0)
			{
				if (highScore[i] < x)
				{
					p = highScore[i];
					highScore[i] = highScore[i + 1];
					highScore[i + 1] = p;
				}
				--i;
			}
		}

	}
	if (pf == 1)
	{
		saveHighscores();
	}
}
