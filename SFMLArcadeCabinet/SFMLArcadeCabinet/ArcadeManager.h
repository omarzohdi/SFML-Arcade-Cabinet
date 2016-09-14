#include <SFML/Graphics.hpp>
#include <time.h>
#include "GameFactory.h"
#include <iostream>
#include "Constants.h"


class ArcadeManager
{
private:
	sf::RenderWindow * App;
	Game* Games;
	Game* MainMenu;
	GameId currgame = menu_;
	bool running = true;
	bool started;
	GameFactory F;

public:
	ArcadeManager();
	~ArcadeManager();

	void Start();
	void Stop();

	void Process();
};

