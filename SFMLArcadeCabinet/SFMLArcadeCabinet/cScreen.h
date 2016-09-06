#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};

