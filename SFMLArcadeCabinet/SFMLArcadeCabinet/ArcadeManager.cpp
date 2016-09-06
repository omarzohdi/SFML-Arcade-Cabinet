#include "ArcadeManager.h"

//Menu to select Games.

ArcadeManager::ArcadeManager() {}

ArcadeManager::~ArcadeManager() {}

void ArcadeManager::Start() 
{
	this->started = true;

	this->App = new sf::RenderWindow(sf::VideoMode(320, 480), "Arcade Cabinet");
	this->App->setMouseCursorVisible(false);

	MainMenu = LoadGame(0);
}

void ArcadeManager::Stop() 
{
	delete this->App;
	delete this->Games;
	this->started = false;
}

void ArcadeManager::Process()
{
	if (this->started)
	{
		while (this->currgame >= 0)
		{
			if (currgame == 0)
				this->currgame = this->MainMenu->Run(*App, this->clock);
			else if (currgame > 0)
			{
				if (this->Games != 0)
					delete this->Games;
				this->Games = LoadGame(this->currgame);
			
				this->currgame = this->Games->Run(*App, this->clock);
			}
		}
	}
}

//Temporary Code!!!
Game * ArcadeManager::LoadGame(int in)
{
	switch (in)
	{
		case 0:
			return new ArcadeMenu();
		case 1:
			return new Tetris();
		default:
			return new ArcadeMenu();
	}
}