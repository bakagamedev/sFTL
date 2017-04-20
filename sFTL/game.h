#pragma once	
#include "strings.h"
#include "system.h"
#include "ship.h"
#include "people.h"
#include "types.h"

class Game
{
private:
	System *ab;
	uint8_t page=0;
	int8_t selected = 0;
	Point stars[15];

	char screentext1[8],screentext2[8],screentext3[8],screentext4[8];
	bool drawText1=true,drawText2=false,drawText3=false;

	Ship playerShip = Ship(*ab);
	PeepControl peeps = PeepControl(*ab,playerShip);

	void initStars();
	void drawStars();
	void drawBar();
	void input();

	void stepInfo();
	void drawInfo();
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
	peeps.add();
	peeps.add();
	peeps.add();
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

	if(selected==0)
	{
		if(ab->justPressed(LEFT_BUTTON)){	page--;	}
		if(ab->justPressed(RIGHT_BUTTON)){	page++;	}
	}
	if(page<0)	page = 0;
	if(page>3)	page = 3;

	if(ab->justPressed(UP_BUTTON))	{	selected++;	}
	if(ab->justPressed(DOWN_BUTTON)){	selected--;	}
	if(page<0)	page = 0;
	if(page>3)	page = 3;
	if(page==0)
	{
		if(selected>playerShip.roomNum) selected = playerShip.roomNum;
	}
	if(page==1)
	{
		if(selected>peeps.peepNum)	selected = peeps.peepNum;
	}

	if(selected<0) selected=0;	


	if((ab->justPressed(A_BUTTON)) && (page == 3))
	{
		warp = 1;
	}

	playerShip.step();
	peeps.step();
	stepInfo();
};

void Game::draw()
{
	ab->clear();
	drawStars();

	int8_t sel = selected-1;
	if(page != 0 ) sel = -1;
	playerShip.draw(sel,warp);

	if(warp == 0)
	{
		sel = selected-1;
		if(page != 1) sel = -1;
		peeps.draw(sel);
	}

	drawBar();
	drawInfo();
};

void Game::stepInfo()
{
	drawText1 = true;
	strcpy_P(screentext1, (char*)pgm_read_word(&(pageNames[page]))); //I pretend to know how this works!
	drawText2 = false;
	drawText3 = false;
	if (selected>0)
	{
		switch(page)
		{
			case 0:
			{
				char* temp = playerShip.getRoomName(selected-1);
				strcpy(screentext2,temp);
			}; break;
			case 1:
			{
				char* temp = peeps.getName(selected-1);
				strcpy(screentext2,temp);
			}; break;
		}
		drawText2 = true;		
	}
};

void Game::drawInfo()
{
	//this can probably be minimised a bit
	if(drawText1)
	{
		ab->setCursor(0,56);
		ab->print(screentext1);
	}
	if(drawText2)
	{
		ab->setCursor(80,0);
		ab->print(screentext2);
	}
	if(drawText3)
	{
		ab->setCursor(80,8);
		ab->print(screentext3);
	}
};

void Game::drawBar()
{
	const uint8_t startx = 40;
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