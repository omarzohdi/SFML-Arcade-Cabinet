#ifndef GAMEOVER
#define GAMEOVER

#include "Game.h"
#include "Constants.h"


class GameOver :
	public Game
{

private:
	sf::Font Font;
	sf::Text Title;
	sf::Text Menu1;

	int highscore = 0;
	int selection = 0;

public:
	GameOver();
	~GameOver();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update() {};
	virtual void Draw(sf::RenderWindow&);
};
#endif
