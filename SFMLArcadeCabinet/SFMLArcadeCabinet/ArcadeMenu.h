#ifndef ARCADEMENU
#define ARCADEMENU

#include "Game.h"
class ArcadeMenu : public Game
{
	
private:
	sf::Texture t;
	sf::Sprite s;
	

public:
	ArcadeMenu();
	~ArcadeMenu();

	virtual void Update(sf::Clock& clock);
	virtual void Draw(sf::RenderWindow &window);
	virtual void CatchEvents(sf::Event& e);
};

#endif