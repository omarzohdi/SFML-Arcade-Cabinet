#pragma once
#include "cScreen.h";

class screen_1 : public cScreen
{
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	screen_1(void);
	virtual int Run(sf::RenderWindow &App);
};