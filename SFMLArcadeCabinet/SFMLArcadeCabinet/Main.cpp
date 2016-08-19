#include <SFML/Graphics.hpp>
#include <time.h>

// size of the entire game field
const int M = 20;
const int N = 10;

// Game Field
int field[M][N] = { 0 };

struct Point
{int x, y;} a[4], b[4];

/// 0 1 /// each number corrisponds 
/// 2 3 /// to a different shape
/// 4 5 /// each numbr is a tile.
/// 6 7 ///

int figures[7][4] = {

	1,3,5,7, //I
	2,4,5,7, //Z
	3,5,4,6, //S
	3,5,4,7, //T
	2,3,5,7, //L
	3,5,7,6, //J
	2,3,4,5, //O
};

//Check boundries
bool check()
{
	for (int i = 0; i < 4; i++)
	{
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;
	}
	return 1;
};

int main_(void)
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(320, 480), "Arcade Cabinet");

	//load texture
	sf::Texture t;
	t.loadFromFile("images/tetris/tiles.png");

	//load it into spriet
	sf::Sprite s(t);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));

	int dx = 0;
	bool rotate = 0;
	int colorNum = 1;
	float timer = 0;
	float delay = 0.3;

	sf::Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();

			if (e.type == sf::Event::KeyPressed)
				if (e.key.code == sf::Keyboard::Up) rotate = true;
				else if (e.key.code == sf::Keyboard::Left) dx = -1;
				else if (e.key.code == sf::Keyboard::Right) dx = 1;
		}


		///// Move Operation ////
		for (int i = 0; i < 4; i++)
		{
			b[i] = a[i];
			a[i].x += dx;
		}
		if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

		///// Rotate ////
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
			if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
		}

		/////Tick//////
		////move down at time interval.
		if (timer>delay)
		{
			for (int i = 0; i<4; i++) { b[i] = a[i]; a[i].y += 1; }

			if (!check())
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

		//int n = 2; //Selected piece
		
		/*
		//transfer the tiles into a point to be later used in the game area.
		//only if it's the start of the area?
		if (a[0].x == 0)
			for (int i = 0; i < 4; ++i)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
			*/

		//clear variables for next cycle.
		dx = 0;
		rotate = 0;
		delay = 0.3;

		////Draw///
		window.clear(sf::Color::White);

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

		//window.draw(s);
		window.display();
	}

	return 0;
}