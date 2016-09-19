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
	sf::Texture backgroudntexture;

	sf::Sprite GameArea;
	sf::Sprite backgroundsprite;
	sf::Sprite PieceSprite;
	sf::Sprite PreviewSprite;

	sf::Font Font;
	sf::Text ScoreText;
	sf::Text HighScoreText;
	sf::Text HighScore;

	Point currpiece[4] = { 0 }, temppiece[4] = { 0 }, nextpiece[4] = { 0 };
	float timer = 0.0f, delay = 0.8f;
	int dx = 0, colorNum = 1, nextcolornum = 1, 
		linescombo = 0, score = 0, highscore = 0, diff = 0, totlines = 0;
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
	bool rotate = 0, gameover = 0;

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

	bool CheckForGameOverCondition();

	inline float CenterSpriteHorizontally() { return ((SCREENWIDTH / 2.0f) - (N / 2 * 18)); };
	//points equal to the number of grid spaces that the 
	//player has continuously soft dropped the piece.

public:
	Tetris();
	~Tetris();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update();
	virtual void Draw(sf::RenderWindow &window);
};

#endif