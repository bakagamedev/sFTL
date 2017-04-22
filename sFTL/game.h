#pragma once	
#include "Ardutils\Maths.h"
#include "sprites.h"
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
	Ardutils::ClampedValue<uint8_t> selected = Ardutils::ClampedValue<uint8_t>(0,0,1);


	int16_t cameraX = 0;
	int8_t warp=0;

	char screentext1[8],screentext2[8],screentext3[8],screentext4[8];
	bool drawText1=true,drawText2=false,drawText3=false;

	Ship playerShip = Ship(*ab);
	Ship enemyShip = Ship(*ab);
	
	PeepControl peeps = PeepControl(*ab,playerShip);
	Background background = Background(*ab);

	void drawBar();
	void input();

	void stepInfo();
	void drawInfo();
public:

	Game(System & ab);
	void step();
	void draw();
};

Game::Game(System & ab)
{
	this->ab = &ab;

	playerShip.setType(ShipType::Kestrel);
	enemyShip.setType(ShipType::Engi);

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
		if(warp==127)	//stupid optimisation idea; replace with overflow flag check
			background.reset();	//rejig star positions when ship is  offscreen
	}
	else	//Allow inputs when not travelling
	{
		if(selected==0)
		{
			if(ab->justPressed(LEFT_BUTTON)){	--page;	}
			if(ab->justPressed(RIGHT_BUTTON)){	++page;	}

			uint8_t valueMax = 0;
			switch(page)
			{
				case 0:	{	valueMax = playerShip.roomNum;	}; break;
				case 1:	{	valueMax = peeps.peepNum;	}; break;
			}
			selected.SetMax(valueMax);
		}	

		if(ab->justPressed(UP_BUTTON))	{	if(page<2) ++selected;	}
		if(ab->justPressed(DOWN_BUTTON)){	if((page<2)&&(selected>0)) --selected;	}
	}


	if(page==3)	{	cameraX = min(cameraX+2,192);	}
	else	{	cameraX = max(cameraX-2,0);	}

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

	int8_t pos;
	if(cameraX<128)	//If looking at player ship
	{
		pos = -cameraX;
		playerShip.draw(sel,pos+warp);

		if(warp == 0)
		{
			sel = selected-1;
			if(page != 1) sel = -1;
			peeps.draw(sel,pos);
		}

		//if(enemyShip.hp > 0)
		ab->drawBitmap(120+cameraX,0,uiEnemyShip,8,64);
	}
	else	//If looking at enemy ship
	{
		pos = (-cameraX)-256;
		enemyShip.draw(-1,pos);
		//ab->fillRect(pos,16,64,32,0);
		//ab->drawRect(pos,16,64,32,1);
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
				//char* temp[8];
				playerShip.getRoomName(selected-1,screentext2);
				//strcpy(screentext2,temp);
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
		ab->setCursor(70,0);
		ab->print(screentext2);
	}
	if(drawText3)
	{
		ab->setCursor(70,8);
		ab->print(screentext3);
	}
};

void Game::drawBar()
{
	const uint8_t startx = 38;
	const uint8_t starty = 56;

	ab->fillRect(startx+(page*16),starty,16,8,1);
	for(uint8_t i=0; i<5; ++i)
	{
		ab->drawRect(startx+(i*16),starty,16,8,page != i);
	}
};

