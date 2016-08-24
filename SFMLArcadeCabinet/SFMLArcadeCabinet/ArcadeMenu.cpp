#include "ArcadeMenu.h"

ArcadeMenu::ArcadeMenu()
{
	t.loadFromFile("images/tetris/tiles.png");
	s.setTexture(t, true);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));
}


ArcadeMenu::~ArcadeMenu()
{

}

void ArcadeMenu::Update(sf::Clock & clock)
{
}

void ArcadeMenu::Draw(sf::RenderWindow & window)
{
	window.draw(s);
}

void ArcadeMenu::CatchEvents(sf::Event & e)
{
}
