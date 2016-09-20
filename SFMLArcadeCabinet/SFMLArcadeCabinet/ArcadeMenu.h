#ifndef ARCADEMENU
#define ARCADEMENU

#include "Constants.h"
#include "Game.h"
#include  <iostream>

class ArcadeMenu : public Game
{
	
private:
	
	sf::Font Font;
	sf::Text MenuTetris;
	sf::Text MenuExit;
	sf::Text MenuArkanoid;
	int menu = 0;
	bool playing = false;

	int startGame();

public:
	ArcadeMenu();
	~ArcadeMenu();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update() {};
	virtual void Draw(sf::RenderWindow &window);
};

#endif