#ifndef GAMEFACTORY
#define GAMEFACTORY

#include "Game.h"
#include "Tetris.h"
#include "ArcadeMenu.h"
#include "GameOver.h"
#include "Arkanoid.h"

class GameFactory
{
public:

	inline Game * CreateGame(GameId inGameid)
	{
		switch (inGameid)
		{
		case menu_:
			return new ArcadeMenu();
		case tetris_:
			return new Tetris();
		case gameover_:
			return new GameOver();
		case arkanoid_:
			return new Arkanoid();
		default:
			return new ArcadeMenu();
		}
	}
};
#endif