#include <SFML/Graphics.hpp>
#include <time.h>
#include "Tetris.h"
#include "ArcadeMenu.h"
#include <iostream>

class ArcadeManager
{
private:
	enum GameId { tetris_ , arkanoid_ , menu_ };

	ArcadeMenu * arcademenu;
	Tetris * tetris;
	Game * runningApp;
	GameId currGame;
	bool ChangeGame = false;

	void Update(sf::Clock& clock);
	void Draw(sf::RenderWindow &window);

public:
	ArcadeManager();
	~ArcadeManager();

	void Start();
	void Stop();
	
	void Events(sf::Event& e);
	void Process(sf::Clock& clock, sf::RenderWindow &window);
};

