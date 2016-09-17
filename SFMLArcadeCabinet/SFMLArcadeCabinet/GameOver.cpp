#include "GameOver.h"

GameOver::GameOver()
{
	Font.loadFromFile("fonts/verdanab.ttf");

	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Back to Menu");

	sf::FloatRect Menu1Rect = Menu1.getLocalBounds();
	Menu1.setOrigin(Menu1Rect.left + Menu1Rect.width / 2.0f,
		Menu1Rect.top + Menu1Rect.height / 2.0f);
	Menu1.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 260.0f));

	Title.setFont(Font);
	Title.setCharacterSize(20);
	Title.setString("GameOver");

	sf::FloatRect TitleRect = Title.getLocalBounds();
	Title.setOrigin(TitleRect.left + TitleRect.width / 2.0f,
		TitleRect.top + TitleRect.height / 2.0f);
	Title.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 160.0f));

}

int GameOver::Run(sf::RenderWindow &window)
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
					/*
				case sf::Keyboard::Up:
					selection = 0;
					break;
				case sf::Keyboard::Down:
					selection= 1;
					break;
					*/
				case sf::Keyboard::Return:
					if (selection == 0)
					{
						//Let's get play !
						return (1);
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

void GameOver::Draw(sf::RenderWindow & window)
{
	if (selection == 0)
	{
		Menu1.setColor(sf::Color(255, 0, 0, 255));
	}

	//Clearing screen
	window.clear(sf::Color::Black);

	//Drawing
	window.draw(Menu1);
	window.draw(Title);
	window.display();
}

GameOver::~GameOver()
{
	
}
