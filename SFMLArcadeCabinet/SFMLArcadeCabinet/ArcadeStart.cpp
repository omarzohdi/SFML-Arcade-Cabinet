#include <SFML/Graphics.hpp>
#include <time.h>
#include "ArcadeManager.h"

int main(void)
{
	ArcadeManager manager;

	//Window creation
	manager.Start();
	manager.Process();
	manager.Stop();

	return EXIT_SUCCESS;
}