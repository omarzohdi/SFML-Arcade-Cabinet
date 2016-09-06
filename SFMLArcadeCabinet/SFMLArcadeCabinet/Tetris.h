#ifndef TETRIS
#define TETRIS

#include "Game.h"

class Tetris : public Game
{
private:
	enum { M = 20 , N = 10};
	struct Point { int x, y; };

	sf::Texture t;
	sf::Sprite s;
	
	Point a[4] = { 0 }, b[4] = { 0 };
	float timer = 0.0f, delay = 0.3f;
	int dx = 0, colorNum = 1;
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
	bool rotate = 0;

	bool checkCollision();
	void checkLine();

	void MovePiece();
	void RotatePiece();

	void Tick();
	void ResetVars();

public:
	Tetris();
	~Tetris();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update();
	virtual void Draw(sf::RenderWindow &window);
};

#endif