#include "Tetris.h"

Tetris::Tetris()
{
	srand(time(0));
	t.loadFromFile("images/tetris/tiles.png");
	s.setTexture(t, true);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));
}

Tetris::~Tetris()
{
}

void Tetris::CatchEvents(sf::Event& e)
{
	if (e.type == sf::Event::KeyPressed)
		if (e.key.code == sf::Keyboard::Up) rotate = true;
		else if (e.key.code == sf::Keyboard::Left) dx = -1;
		else if (e.key.code == sf::Keyboard::Right) dx = 1;
}
void Tetris::Update()
{
	this->MovePiece();
	this->RotatePiece();
	this->Tick();

	this->ResetVars();
}

void Tetris::ResetVars()
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;

	dx = 0;
	rotate = 0;
	delay = 0.3;
}

void Tetris::Draw(sf::RenderWindow &window)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 0) continue;

			s.setPosition(j * 18, i * 18);
			window.draw(s);
		}
	}

	//draw the sprite into the game area.
	for (int i = 0; i < 4; i++)
	{
		s.setPosition(a[i].x * 18, a[i].y * 18);
		window.draw(s);
	}

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

