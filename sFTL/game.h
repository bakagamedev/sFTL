#pragma once	
#include "Ardutils/StaticWrappedValue.h"
#include "strings.h"
#include "system.h"
#include "ship.h"
#include "people.h"
#include "background.h"
#include "types.h"

class Game
{
private:
	System *ab;

	Ardutils::StaticWrappedValue<uint8_t,0,4> page;

	uint8_t selected = 0;

	char screentext1[8],screentext2[8],screentext3[8],screentext4[8];
	bool drawText1=true,drawText2=false,drawText3=false;

	Ship playerShip = Ship(*ab);
	PeepControl peeps = PeepControl(*ab,playerShip);
	Background background = Background(*ab);

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
};

void Game::step()
{

	if(warp!=0)
	{	
		warp++;
		if(warp==127)	//rejig star positions when ship is  offscreen
			background.reset();
	}

	if(selected==0)
	{
		if(ab->justPressed(LEFT_BUTTON)){	page--;	selected = 0; }
		if(ab->justPressed(RIGHT_BUTTON)){	page++;	selected = 0; }
	}	

	if(ab->justPressed(UP_BUTTON))	{	if(page<2) selected++;	}
	if(ab->justPressed(DOWN_BUTTON)){	if(page<2) selected--;	}


	if(page==0)
	{
		if(selected>playerShip.roomNum) selected = playerShip.roomNum;
	}
	if(page==1)
	{
		if(selected>peeps.peepNum)	selected = peeps.peepNum;
	}

	if(selected<0) selected=0;	


	if((ab->justPressed(A_BUTTON)) && (page == 4))
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
	background.draw();

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
	const uint8_t startx = 44;
	const uint8_t starty = 56;

	ab->fillRect(startx+(page*16),starty,16,8,1);
	for(uint8_t i=0; i<5; ++i)
	{
		ab->drawRect(startx+(i*16),starty,16,8,page != i);
	}
};

