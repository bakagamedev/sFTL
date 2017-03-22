#pragma once	
#include "system.h"
#include "ship.h"
#include "people.h"
#include "types.h"

class Game
{
private:
	System *ab;
	int8_t page = 0;
	int8_t selected = 0;
	Point stars[15];

	Ship playerShip = Ship(*ab);
	PeepControl peeps = PeepControl(*ab,playerShip);

	void initStars();
	void drawStars();
	void drawBar();
	void input();
public:
	int8_t warp=0;

	Game(System & ab);
	void step();
	void draw();
};

Game::Game(System & ab)
{
	this->ab = &ab;

	playerShip.setType(ShipType::kestrel);

	peeps.add();

	initStars();
};

void Game::step()
{
	if(warp!=0)
	{	
		warp++;
		if(warp==127)	//rejig star positions when ship is  offscreen
			initStars();	
	}

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

	if((ab->justPressed(A_BUTTON)) && (page == 3))
	{
		warp = 1;
	}

	playerShip.step();
	peeps.step();
};

void Game::draw()
{
	ab->clear();
	drawStars();

	drawBar();

	playerShip.draw(selected-1,warp);

	if(warp == 0)
		peeps.draw();
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

void Game::initStars()
{
	for(uint8_t i=0; i<15; ++i)
	{
		stars[i].x = random(128);
		stars[i].y = random(56);
	}
};
void Game::drawStars()
{
	for(uint8_t i=0; i<15; ++i)
		ab->drawPixel(stars[i].x,stars[i].y,1);
};