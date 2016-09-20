#ifndef ARKANOID
#define ARKANOID

#include "Game.h"
#include "Constants.h"


constexpr float ballRadius{ 10.f }, ballVelocity{8.f};
constexpr float paddleWidth{ 60.0f }, paddleHeight{ 20.0f }, paddleVelocity{ 6.f };

class Arkanoid : public Game
{
	struct Paddle
	{
		sf::RectangleShape shape;
		sf::Vector2f velocity;

		Paddle(float mX, float mY)
		{
			shape.setPosition(mX, mY);
			shape.setSize({ paddleWidth, paddleHeight });
			shape.setFillColor(sf::Color::Green);
			shape.setOrigin(paddleWidth /2.f , paddleHeight /2.f);
		}


		float x() { return shape.getPosition().x; }
		float y() { return shape.getPosition().y; }
		float left() { return x() - shape.getSize().x / 2.f ; }
		float right() { return x() + shape.getSize().x / 2.f; }
		float top() { return y() - shape.getSize().y / 2.f; }
		float bottom() { return y() + shape.getSize().y / 2.f; }


		void Update()
		{
			shape.move(velocity);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
				velocity.x = -paddleVelocity;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < SCREENWIDTH)
				velocity.x = paddleVelocity;
			else
				velocity.x = 0;

		}
	};
	struct Ball
{
	sf::CircleShape shape;
	sf::Vector2f velocity {-ballVelocity, -ballVelocity};

	Ball(float mX, float mY)
	{
		shape.setPosition(mX, mY);
		shape.setRadius(ballRadius);
		shape.setFillColor(sf::Color::Red);
		shape.setOrigin(ballRadius, ballRadius);
	}

	float x() { return shape.getPosition().x; }
	float y() { return shape.getPosition().y; }
	float left() { return x() - shape.getRadius(); }
	float right() { return x() + shape.getRadius(); }
	float top() { return y() - shape.getRadius(); }
	float bottom() { return y() + shape.getRadius(); }
	
	void Update()
	{
		shape.move(velocity);

		//Set to positive value to move to the right
		//set to negative value to move to the left
		if (left() < 0) velocity.x = ballVelocity;
		else if (right() > SCREENWIDTH) velocity.x = -ballVelocity;

		//Set to positive value to move to the bottom
		//set to negative value to move to the top
		if (top() < 0) velocity.y = ballVelocity;
		else if (bottom() > SCREENHEIGHT) velocity.y = -ballVelocity;
	}
};

private:
	Ball ball{ SCREENWIDTH / 2.f, SCREENHEIGHT / 2.f };
	Paddle paddle{ SCREENWIDTH / 2.f, SCREENHEIGHT - 50 };

public:
	Arkanoid();
	~Arkanoid();

	virtual int Run(sf::RenderWindow &App);
	virtual void Update();
	virtual void Draw(sf::RenderWindow&);
};

#endif