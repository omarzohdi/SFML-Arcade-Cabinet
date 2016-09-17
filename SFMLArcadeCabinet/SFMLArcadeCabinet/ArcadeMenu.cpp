#include "ArcadeMenu.h"


ArcadeMenu::ArcadeMenu()
{
	Font.loadFromFile("fonts/verdanab.ttf");
	
	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Tetris");
	
	sf::FloatRect Menu1Rect = Menu1.getLocalBounds();
	Menu1.setOrigin(Menu1Rect.left + Menu1Rect.width / 2.0f,
		Menu1Rect.top + Menu1Rect.height / 2.0f);
	Menu1.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 160.0f));

	Menu2.setFont(Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	sf::FloatRect Menu2Rect = Menu2.getLocalBounds();
	Menu2.setOrigin(Menu2Rect.left + Menu2Rect.width / 2.0f,
		Menu2Rect.top + Menu2Rect.height / 2.0f);
	Menu2.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 220.0f));
}

ArcadeMenu::~ArcadeMenu()
{

}

int ArcadeMenu::Run(sf::RenderWindow &window)
{
	bool Running = true;
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
						menu = 0;
						break;
					case sf::Keyboard::Down:
						menu = 1;
						break;
					case sf::Keyboard::Return:
						if (menu == 0)
						{
							//Let's get play !
							playing = true;
							return (3);
						}
						else
						{
							//Let's get work...
							return (-1);
						}
						break;
					default:
						break;
				}
			}
		}

	}

	return (-1);
}

void ArcadeMenu::Draw(sf::RenderWindow & window)
{
	if (menu == 0)
	{
		Menu1.setColor(sf::Color(255, 0, 0, 255));
		Menu2.setColor(sf::Color(255, 255, 255, 255));
	}
	else
	{
		Menu1.setColor(sf::Color(255, 255, 255, 255));
		Menu2.setColor(sf::Color(255, 0, 0, 255));
	}

	//Clearing screen
	window.clear(sf::Color::Black);
	
	//Drawing
	window.draw(Menu1);
	window.draw(Menu2);
	window.display();
}
