#include "ArcadeManager.h"

//Menu to select Games.

ArcadeManager::ArcadeManager() {}

ArcadeManager::~ArcadeManager() {}

void ArcadeManager::Start() 
{
	this->started = true;

	this->App = new sf::RenderWindow(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT), "Arcade Cabinet");
	this->App->setMouseCursorVisible(false);

	MainMenu = F.CreateGame(menu_);
}

void ArcadeManager::Stop() 
{
	delete this->App;
	if (this->Games != nullptr)
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
				this->currgame = (GameId) this->MainMenu->Run(*App);
			else if (currgame > 0)
			{
				if (this->Games != nullptr)
					delete this->Games;
				this->Games = F.CreateGame(this->currgame);
			
				this->currgame = (GameId) this->Games->Run(*App);
			}
		}
	}
}