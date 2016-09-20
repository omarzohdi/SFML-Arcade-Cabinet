#include "ArcadeMenu.h"


ArcadeMenu::ArcadeMenu()
{
	Font.loadFromFile("fonts/verdanab.ttf");
	

	MenuTetris.setFont(Font);
	MenuTetris.setCharacterSize(20);
	MenuTetris.setString("Tetris");
	
	sf::FloatRect MenuTetrisRect = MenuTetris.getLocalBounds();
	MenuTetris.setOrigin(MenuTetrisRect.left + MenuTetrisRect.width / 2.0f,
		MenuTetrisRect.top + MenuTetrisRect.height / 2.0f);
	MenuTetris.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 160.0f));


	MenuArkanoid.setFont(Font);
	MenuArkanoid.setCharacterSize(20);
	MenuArkanoid.setString("Arkanoid");

	sf::FloatRect MenuArkanoidRect = MenuArkanoid.getLocalBounds();
	MenuArkanoid.setOrigin(MenuArkanoidRect.left + MenuArkanoidRect.width / 2.0f,
		MenuArkanoidRect.top + MenuArkanoidRect.height / 2.0f);
	MenuArkanoid.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 220.0f));


	MenuExit.setFont(Font);
	MenuExit.setCharacterSize(20);
	MenuExit.setString("Exit");
	sf::FloatRect MenuExitRect = MenuExit.getLocalBounds();
	MenuExit.setOrigin(MenuExitRect.left + MenuExitRect.width / 2.0f,
		MenuExitRect.top + MenuExitRect.height / 2.0f);
	MenuExit.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 280.f));
}

ArcadeMenu::~ArcadeMenu()
{

}

int ArcadeMenu::Run(sf::RenderWindow &window)
{
	bool Running = true;
	playing = false;
	sf::Event e;

	while (Running)
	{
		this->Draw(window);

		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				return (-1);

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
					case sf::Keyboard::Up:
						if (menu > 0)
							menu --;
						break;
					case sf::Keyboard::Down:
						if (menu < 2)
							menu++;
						break;
					case sf::Keyboard::Return:
						return (this->startGame());
						break;
					default:
						break;
				}
			}
		}

	}

	return (-1);
}


int ArcadeMenu::startGame()
{
	switch (menu)
	{
	case 0:
		playing = true;
		return (3);
	case 1:
		playing = true;
		return (4);
	case 2:
		return (-1);
	default:
		break;
	}
}

void ArcadeMenu::Draw(sf::RenderWindow & window)
{
	MenuTetris.setColor(sf::Color(255, 255, 255, 255));
	MenuArkanoid.setColor(sf::Color(255, 255, 255, 255));
	MenuExit.setColor(sf::Color(255, 255, 255, 255));
	
	switch (menu)
	{
		case 0:
			MenuTetris.setColor(sf::Color(255, 0, 0, 255));
		break;
		case 1:
			MenuArkanoid.setColor(sf::Color(255, 0, 0, 255));
		break;
		case 2:
			MenuExit.setColor(sf::Color(255, 0, 0, 255));
			break;
	default:
		break;
	}

	//Clearing screen
	window.clear(sf::Color::Black);
	
	//Drawing
	window.draw(MenuTetris);
	window.draw(MenuArkanoid);
	window.draw(MenuExit);
	window.display();
}
