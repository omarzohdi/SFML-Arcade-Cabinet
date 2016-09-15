#ifndef TETRIS
#define TETRIS

#include "Game.h"
#include "Constants.h"

class Tetris : public Game
{
private:
	enum { M = 20, N = 10 };
	struct Point { int x, y; };

	sf::Texture titlestexture;
	sf::Sprite GameArea;
	sf::Sprite PieceSprite;
	sf::Sprite PreviewSprite;

	sf::Font Font;
	sf::Text ScoreText;

	Point currpiece[4] = { 0 }, temppiece[4] = { 0 }, nextpiece[4] = { 0 };
	float timer = 0.0f, delay = 0.8f;
	int dx = 0, colorNum = 1, nextcolornum = 1, 
		linescombo = 0, score = 0, diff = 0, totlines = 0;
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

	void GetNewPiece(Point *);
	void SpawnPiece();

	void UpdateScoreAndDifficulty();
	int UpdateScore(int);
	float UpdateDifficulty();

	inline float CenterSpriteHorizontally() { return ((SCREENWIDTH / 2.0f) - (N / 2 * 18)); };
	//points equal to the number of grid spaces that the 
	//player has continuously soft dropped the piece.

	/*
	 Level    Drop speed
         (frames/line)
     00            48 (0.8 s)
     01            43 (0.72s)
     02            38 (0.63s) 
     03            33 (0.55s) 
     04            28 (0.47s) 
     05            23 (0.38s)
     06            18 (0.3 s) 
     07            13 (0.22s)
     08             8 (0.13s)
     09             6 (0.1 s)
  10-12             5 (0.08s) 
  13-15             4 (0.07s)
  16-18             3 (0.05s)
  19-28             2 (0.03s)
    29+             1 (0.02s)
	*/

public:
	Tetris();
	~Tetris();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update();
	virtual void Draw(sf::RenderWindow &window);
};

#endif