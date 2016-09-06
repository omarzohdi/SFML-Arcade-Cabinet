#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <time.h>

class Game
{

protected:
	Game() {};
public:
	
	virtual int Run(sf::RenderWindow &App, sf::Clock&) = 0;
	virtual void Update(sf::Clock&) = 0;
	virtual void Draw(sf::RenderWindow&) = 0;
	virtual int CatchEvents(sf::Event& e) = 0;

	virtual ~Game() {};
};

#endif