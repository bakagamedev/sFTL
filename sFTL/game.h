#pragma once
#include "system.h"

class Game
{
private:
	System ab = System();
public:
	Game();
	void step();
};

Game::Game()
{
	ab.boot();
}

void Game::step()
{
	if (ab.nextFrame())
	{
		ab.pollButtons();

		//insert game here
			
		ab.display();
	}
}