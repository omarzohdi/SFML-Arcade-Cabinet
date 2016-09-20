#include "Arkanoid.h"

Arkanoid::Arkanoid() { }
Arkanoid ::~Arkanoid() { }

int Arkanoid::Run(sf::RenderWindow &window)
{ 
	bool Running = true;
	sf::Event e;

	while (Running)
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				return (-1);

			if (e.type == sf::Event::KeyPressed)
			{
				switch (e.key.code)
				{
					return (0);
					break;
				default: break;
				}
			}
		}

		this->Draw(window);
		this->Update();

		//if (gameover) return (2);
	}

	return (-1);
}
void Arkanoid::Update() 
{
	ball.Update();
	paddle.Update();
}
void Arkanoid::Draw(sf::RenderWindow& window) 
{
	window.clear(sf::Color::Black);

	window.draw(ball.shape);
	window.draw(paddle.shape);

	window.display();
}