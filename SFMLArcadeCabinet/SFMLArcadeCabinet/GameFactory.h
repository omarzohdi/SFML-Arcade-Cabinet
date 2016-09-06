#ifndef GAMEFACTORY
#define GAMEFACTORY

#include "Game.h";
#include "Tetris.h";
#include "ArcadeMenu.h";

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
		default:
			return new ArcadeMenu();
		}
	}
};
#endif