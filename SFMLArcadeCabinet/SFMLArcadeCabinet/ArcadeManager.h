#include <SFML/Graphics.hpp>
#include <time.h>
#include "Tetris.h"
#include "ArcadeMenu.h"
#include <iostream>

class ArcadeManager
{
private:
	enum GameId { tetris_ , arkanoid_ , menu_ };

	sf::RenderWindow * App;
	sf::Clock clock;
	std::vector<Game*> Games;
	int currgame = 0;
	bool running = true;
	bool started;

	//Games//
	ArcadeMenu am;
	Tetris t;

public:
	ArcadeManager();
	~ArcadeManager();

	void Start();
	void Stop();

	void Process();
};

