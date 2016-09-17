#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <time.h>

enum GameId {
	exit_ = -1, 
	menu_ = 0,
	pause_,
	gameover_,

	tetris_, 
	arkanoid_
};

class Game
{

protected:
	Game() {};
	sf::Clock clock;
public:
	
	virtual int Run(sf::RenderWindow &App) = 0;
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow&) = 0;

	virtual ~Game() {};
};
#endif