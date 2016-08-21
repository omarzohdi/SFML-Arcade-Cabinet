#include <SFML/Graphics.hpp>
#include <time.h>
#include "Tetris.h"

int main(void)
{	
	Tetris T;
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(320, 480), "Arcade Cabinet");

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();

			T.CatchEvents(e);
		}

		window.clear(sf::Color::Black);
		
		T.Update(clock);
		T.Draw(window);
		
		clock.restart();
		window.display();
	}

	return 0;
}