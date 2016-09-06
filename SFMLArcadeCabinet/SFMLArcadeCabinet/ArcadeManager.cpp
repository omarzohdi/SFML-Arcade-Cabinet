#include "ArcadeManager.h"

//Menu to select Games.

ArcadeManager::ArcadeManager() {}

ArcadeManager::~ArcadeManager() {}

void ArcadeManager::Start() 
{
	this->started = true;

	this->App = new sf::RenderWindow(sf::VideoMode(320, 480), "Arcade Cabinet");
	this->App->setMouseCursorVisible(false);
	
	///Add Games to List//
	this->Games.push_back(&am);
	this->Games.push_back(&t);
}

void ArcadeManager::Stop() 
{
	delete this->App;
	this->started = false;

	///Clear List///
	for (std::vector< Game* >::iterator it = Games.begin(); it != Games.end(); ++it)
	{
		delete (*it);
	}
	Games.clear();
}

void ArcadeManager::Process()
{
	if (this->started)
	{
		while (this->currgame >= 0)
		{
			this->currgame = this->Games[this->currgame]->Run(*App, this->clock);
		}
	}
}