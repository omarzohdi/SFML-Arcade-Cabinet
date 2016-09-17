#include "Tetris.h"

Tetris::Tetris()
{
	srand(unsigned int(time(0)));
	titlestexture.loadFromFile("images/tetris/tiles.png");
	PieceSprite.setTexture(titlestexture, true);
	PreviewSprite.setTexture(titlestexture, true);
	GameArea.setTexture(titlestexture, true);

	this->GetNewPiece(nextpiece);
	this->SpawnPiece();

	Font.loadFromFile("fonts/verdanab.ttf");

	ScoreText.setFont(Font);
	ScoreText.setCharacterSize(20);
	ScoreText.setString("0");

	sf::FloatRect ScoreTextRect = ScoreText.getLocalBounds();
	ScoreText.setOrigin(ScoreTextRect.left + ScoreTextRect.width / 2.0f,
		ScoreTextRect.top + ScoreTextRect.height / 2.0f);
	ScoreText.setPosition(sf::Vector2f(SCREENWIDTH / 2.0f, 500.0f));
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

		if (gameover) return (2);
	}

	return (-1);
}

void Tetris::Update()
{
	if (!gameover)
	{ 
		this->MovePiece();
		this->RotatePiece();
		this->Tick();
		this->checkLine();
		this->UpdateScoreAndDifficulty();

		this->ResetVars();
	}
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

	//Fix this use a different sprite for the playing field!
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 0) continue;
			GameArea.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
			GameArea.setPosition( float(this->CenterSpriteHorizontally() + (j * 18) ),
				float(i * 18));
			window.draw(GameArea);
		}
	}

	//draw the sprite into the game area.
	for (int i = 0; i < 4; i++)
	{
		PieceSprite.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
		PieceSprite.setPosition(float(this->CenterSpriteHorizontally() + currpiece[i].x * 18),
			float(currpiece[i].y * 18));
		window.draw(PieceSprite);
	}

	//draw next piece in preview area.
	for (int i = 0; i < 4; i++)
	{
		PreviewSprite.setTextureRect(sf::IntRect(nextcolornum * 18, 0, 18, 18));
		PreviewSprite.setPosition(float( (SCREENWIDTH - 72 ) + nextpiece[i].x * 18),
							float(10 + nextpiece[i].y * 18));
		window.draw(PreviewSprite);
	}


	ScoreText.setColor(sf::Color(255, 255, 255, 255));
	window.draw(ScoreText);

	window.display();
}

bool Tetris::checkCollision()
{
	for (int i = 0; i < 4; i++)
	{
		if (currpiece[i].x < 0 || currpiece[i].x >= N || currpiece[i].y >= M) return 0;
		else if (field[currpiece[i].y][currpiece[i].x]) return 0;
	}
	return 1;
};

void Tetris::checkLine()
{
	//M is height 20
	//N is width 10
	int k = M - 1;
	for (int i = M - 1; i > 0; --i)
	{
		int count = 0; 
		
		for (int j = 0; j < N; j++)
		{
			//increment Count of blocks 
			if (field[i][j]) count++;
			
			//Override K line with above line.
			field[k][j] = field[i][j];
		}
		
		//decrement K if the line is not full
		if (count < N) { k--; }
		else { linescombo++; totlines++; }

	}
}

void Tetris::MovePiece()
{
	for (int i = 0; i < 4; i++)
	{
		temppiece[i] = currpiece[i];
		currpiece[i].x += dx;
	}
	if (!checkCollision()) for (int i = 0; i < 4; i++) currpiece[i] = temppiece[i];
}

void Tetris::RotatePiece()
{
	if (rotate)
	{
		Point p = currpiece[1]; //center of rotation
		for (int i = 0; i < 4; i++)
		{
			int x = currpiece[i].y - p.y;
			int y = currpiece[i].x - p.x;

			currpiece[i].x = p.x - x;
			currpiece[i].y = p.y + y;
		}
		if (!checkCollision()) for (int i = 0; i < 4; i++) currpiece[i] = temppiece[i];
	}
}

void Tetris::GetNewPiece(Point * newPoint)
{
	//Spawn a new piece.
	nextcolornum = 1 + rand() % 7;

	int n = rand() % 7;
	for (int i = 0; i<4; i++)
	{
		newPoint[i].x = figures[n][i] % 2;
		newPoint[i].y = figures[n][i] / 2;
	}
}

void Tetris::SpawnPiece()
{	
	for (int i = 0; i < 4; i++)
	{
		this->currpiece[i] = this->nextpiece[i];
		this->currpiece[i].x += 4;
	}
	
	colorNum = nextcolornum;

	this->GetNewPiece(nextpiece);
	
}

bool Tetris::CheckForGameOverCondition()
{
	for (int i = 0; i < 4; ++i)
	{
		
		if (field[currpiece[i].y][currpiece[i].x] != 0)
		{
			return true;
		}

	}
	return false;
}

void Tetris::Tick()
{
	if (timer>delay)
	{
		//move into temporary
		for (int i = 0; i<4; i++) { temppiece[i] = currpiece[i]; currpiece[i].y += 1; }

		if (!checkCollision())
		{
			//since it hit the end of the level restore the temp.
			for (int i = 0; i<4; i++) field[temppiece[i].y][temppiece[i].x] = colorNum;

			this->SpawnPiece();
			this->gameover = this->CheckForGameOverCondition();
		}

		timer = 0;
	}
}

void Tetris::UpdateScoreAndDifficulty()
{
	////Score Update
	if (linescombo > 4)
	{
		int fval = linescombo / 4;
		int sval = linescombo % 4;

		for (int i = 0; i < fval; ++i)
		{
			score += this->UpdateScore(4);
		}

		score += this->UpdateScore(sval);
		
		ScoreText.setString(std::to_string(score));
	}
	else if (linescombo > 0)
	{
		score += this->UpdateScore(linescombo);
		ScoreText.setString(std::to_string(score));
	}

	linescombo = 0;

	////Difficulty Update
	if (totlines % 10 == 0)
		delay = UpdateDifficulty();

}

int Tetris::UpdateScore(int inVal)
{
	int multiplier = 0;

	switch (inVal)
	{
		case 1: multiplier = 40;	break;
		case 2: multiplier = 100;	break;
		case 3: multiplier = 300;	break;
		case 4: multiplier = 1200;	break;
	}

	return ( multiplier * (diff + 1) );
}

float Tetris::UpdateDifficulty()
{
	if (totlines == 0) return 0.8f;
	else if (totlines == 10) return 0.72f;
	else if (totlines == 20) return 0.63f;
	else if (totlines == 30) return 0.55f;
	else if (totlines == 40) return 0.47f;
	else if (totlines == 50) return 0.38f;
	else if (totlines == 60) return 0.3f;
	else if (totlines == 70) return 0.22f;
	else if (totlines == 80) return 0.13f;
	else if (totlines == 90) return 0.1f;
	else if (totlines >= 100 && totlines <= 120) return 0.08f;
	else if (totlines >= 130 && totlines <= 150) return 0.07f;
	else if (totlines >= 160 && totlines <= 180) return 0.05f;
	else if (totlines >= 190 && totlines <= 280) return 0.03f;
	else if (totlines >= 290) return 0.02f;
	else return 0.8f;
}