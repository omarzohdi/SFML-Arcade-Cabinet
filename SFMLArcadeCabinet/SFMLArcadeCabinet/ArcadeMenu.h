#ifndef ARCADEMENU
#define ARCADEMENU

#include "Game.h"
#include  <iostream>
class ArcadeMenu : public Game
{
	
private:
	
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;
	bool playing = false;
	

public:
	ArcadeMenu();
	~ArcadeMenu();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update() {};
	virtual void Draw(sf::RenderWindow &window);
};

#endif