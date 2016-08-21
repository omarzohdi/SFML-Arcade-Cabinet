#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <time.h>

class Game
{
public:
	Game();
	~Game();

	virtual void Update(sf::Clock&) = 0;
	virtual void Draw(sf::RenderWindow&) = 0;
};

#endif