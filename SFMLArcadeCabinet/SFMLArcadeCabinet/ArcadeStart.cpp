#include <SFML/Graphics.hpp>
#include <time.h>

//#include "screen_0.h"
//#include "screen_1.h"
#include "ArcadeManager.h"
//#include "Game.h";
//#include "Tetris.h";
//#include "ArcadeMenu.h";


/*
int main__(void)
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
*/
int main(void)
{

	ArcadeManager manager;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(320, 480), "Arcade Cabinet");
	App.setMouseCursorVisible(false);

	manager.Start();
	manager.Process();
	manager.Stop();

	return EXIT_SUCCESS;
}