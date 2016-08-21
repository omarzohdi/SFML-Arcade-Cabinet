#ifndef TETRIS
#define TETRIS

#include "Game.h"

struct Point { int x, y; };

class Tetris : Game
{
private:
	enum { M = 20 , N = 10};

	Point a[4] = {0}, b[4] = { 0 };
	int field[M][N] = { 0 };

	int figures[7][4] = {
		1,3,5,7, //I
		2,4,5,7, //Z
		3,5,4,6, //S
		3,5,4,7, //T
		2,3,5,7, //L
		3,5,7,6, //J
		2,3,4,5, //O
	};

	int dx = 0, colorNum = 1;
	float timer = 0.0f, delay = 0.3f;
	bool rotate = 0;

	sf::Sprite s;
	sf::Texture t;

	bool checkCollision();
	void checkLine();

	void MovePiece();
	void RotatePiece();

	void Tick(sf::Clock& clock);
	void ResetVars(sf::Clock& clock);

public:
	Tetris();
	~Tetris();

	void Update(sf::Clock& clock);
	void Draw(sf::RenderWindow &window);
	void CatchEvents(sf::Event& e);
};

#endif