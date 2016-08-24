#include "ArcadeManager.h"

//Menu to select Games.

ArcadeManager::ArcadeManager()
{
	this->arcademenu = new ArcadeMenu();
	this->tetris = new Tetris();
}

ArcadeManager::~ArcadeManager()
{
}

void ArcadeManager::Start()
{
	this->currGame = tetris_;
	this->runningApp = tetris;
}

void ArcadeManager::Stop()
{
	delete tetris;
	delete arcademenu;
}

void ArcadeManager::Events(sf::Event & e)
{
	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Escape)
		{
			currGame = menu_;
			ChangeGame = true;
		}
	}

	this->runningApp->CatchEvents(e);
}

void ArcadeManager::Process(sf::Clock& clock, sf::RenderWindow &window)
{
	this->Update(clock);
	this->Draw(window);

	if (this->ChangeGame)
	{
		switch ( currGame)
		{
			case menu_:
				this->runningApp = this->arcademenu;
			break;
			
			case tetris_:
				this->runningApp = this->tetris;
			break;
		
			default:
			break;
		}
		
		this->ChangeGame = false;
	}
}

void ArcadeManager::Update(sf::Clock& clock)
{
	this->runningApp->Update(clock);
	clock.restart();
}

void ArcadeManager::Draw(sf::RenderWindow &window)
{
	window.clear(sf::Color::Black);
	this->runningApp->Draw(window);
	window.display();
}
