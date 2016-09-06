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
	Game* Games;
	Game* MainMenu;
	int currgame = 0;
	bool running = true;
	bool started;

	//Games//
	ArcadeMenu am;
	Tetris t;

	Game* LoadGame(int);

public:
	ArcadeManager();
	~ArcadeManager();

	void Start();
	void Stop();

	void Process();
};

