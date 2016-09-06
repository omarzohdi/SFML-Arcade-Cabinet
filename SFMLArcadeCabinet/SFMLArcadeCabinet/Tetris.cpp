#include "Tetris.h"

Tetris::Tetris()
{
	srand(unsigned int(time(0)));
	t.loadFromFile("images/tetris/tiles.png");
	s.setTexture(t, true);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));
}

Tetris::~Tetris(){}

int Tetris::Run(sf::RenderWindow &window)
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
				case sf::Keyboard::Up:
					this->rotate = true;
					break;
				case sf::Keyboard::Down:
					this->delay = 0.05f;
					break;
				case sf::Keyboard::Left:
					this->dx = -1;
					break;
				case sf::Keyboard::Right:
					this->dx = 1;
					break;
				case sf::Keyboard::Escape:
					return (0);
					break;
				default: break;
				}
			}
		}

		this->Draw(window);
		this->Update();
	}

	return (-1);
}

void Tetris::Update()
{
	this->MovePiece();
	this->RotatePiece();
	this->Tick();
	this->checkLine();

	this->ResetVars();
}

void Tetris::ResetVars()
{
	float time = clock.getElapsedTime().asSeconds();
	timer += time;

	dx = 0;
	rotate = 0.0f;
	delay = 0.3f;
	clock.restart();
}

void Tetris::Draw(sf::RenderWindow &window)
{
	window.clear(sf::Color::Black);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 0) continue;
			s.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
			s.setPosition( float(j * 18), float(i * 18));
			window.draw(s);
		}
	}

	//draw the sprite into the game area.
	for (int i = 0; i < 4; i++)
	{
		s.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
		s.setPosition(float(a[i].x * 18), float(a[i].y * 18));
		window.draw(s);
	}

	window.display();
}

bool Tetris::checkCollision()
{
	for (int i = 0; i < 4; i++)
	{
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;
	}
	return 1;
};

void Tetris::checkLine()
{
	int k = M - 1;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];

		}
		if (count < N)  k--;

	}
}

void Tetris::MovePiece()
{
	for (int i = 0; i < 4; i++)
	{
		b[i] = a[i];
		a[i].x += dx;
	}
	if (!checkCollision()) for (int i = 0; i < 4; i++) a[i] = b[i];
}

void Tetris::RotatePiece()
{
	if (rotate)
	{
		Point p = a[1]; //center of rotation
		for (int i = 0; i < 4; i++)
		{
			int x = a[i].y - p.y;
			int y = a[i].x - p.x;

			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}
		if (!checkCollision()) for (int i = 0; i < 4; i++) a[i] = b[i];
	}
}

void Tetris::Tick()
{
	if (timer>delay)
	{
		for (int i = 0; i<4; i++) { b[i] = a[i]; a[i].y += 1; }

		if (!checkCollision())
		{
			for (int i = 0; i<4; i++) field[b[i].y][b[i].x] = colorNum;

			colorNum = 1 + rand() % 7;
			int n = rand() % 7;
			for (int i = 0; i<4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}

		timer = 0;
	}
}

