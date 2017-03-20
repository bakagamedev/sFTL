#pragma once	
#include "system.h"
#include "ship.h"
#include "types.h"

class Game
{
private:
	System *ab;
	int8_t page = 0;
	int8_t selected = 0;

	Ship playerShip;

	void drawBar();
	void input();
public:
	Game(System & ab);
	void step();
	void draw();
};

Game::Game(System & ab)
{
	this-> ab = &ab;
	playerShip.setType(ShipType::kestrel);
};

void Game::step()
{
	if(page==0)
	{
		if(ab->justPressed(UP_BUTTON))	{	selected++;	}
		if(ab->justPressed(DOWN_BUTTON)){	selected--;	}
	}
	if(selected==0)
	{
		if(ab->justPressed(LEFT_BUTTON)){	page--;	}
		if(ab->justPressed(RIGHT_BUTTON))	{	page++;	}
	}
	if(selected<0) selected=0;	
	if(selected>playerShip.roomNum) selected = playerShip.roomNum;

	if(page<0)	page = 0;
	if(page>3)	page = 3;
};

void Game::draw()
{
	ab->clear();
	drawBar();

	playerShip.draw(ab,selected-1);
};

void Game::drawBar()
{
	const uint8_t startx = 32;
	const uint8_t starty = 56;

	ab->fillRect(startx+(page*16),starty,16,8,1);
	for(uint8_t i=0; i<4; ++i)
	{
		ab->drawRect(startx+(i*16),starty,16,8,page != i);
	}
};