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

int ArcadeMenu::Run(sf::RenderWindow &window, sf::Clock& clock)
{
	bool Running = true;
	sf::Event e;

	while (Running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::KeyPressed)
				if (e.key.code == sf::Keyboard::Escape) return(0);
			this->CatchEvents(e);
		}

		this->Update(clock);
		this->Draw(window);
	}

	return (-1);
}

void ArcadeMenu::Update(sf::Clock & clock)
{
}

void ArcadeMenu::Draw(sf::RenderWindow & window)
{
	window.clear(sf::Color::Black);
	window.draw(s);
	window.display();
}

int ArcadeMenu::CatchEvents(sf::Event & e)
{
	return 0;
}
