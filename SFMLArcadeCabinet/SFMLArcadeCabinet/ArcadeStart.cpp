#include <SFML/Graphics.hpp>
#include <time.h>

#include "ArcadeManager.h"

int main(void)
{	
	ArcadeManager Manager;

	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(320, 480), "Arcade Cabinet");

	Manager.Start();
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
			Manager.Events(e);
		}

		Manager.Process(clock, window);
	}

	Manager.Stop();

	return 0;
}