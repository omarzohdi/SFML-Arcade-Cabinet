#ifndef ARKANOID
#define ARKANOID

#include "Game.h"
class Arkanoid :
	public Game
{
public:
	Arkanoid();
	~Arkanoid();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update();
	virtual void Draw(sf::RenderWindow&);
};

#endif