#pragma once
#include "types.h"
#include "system.h"
#include "ship.h"

class Peep
{
private:
	Ship *ship;

	Species species;
	Point position;
	uint8_t roomID = 0;
	ShipRoom roomData;
	bool moved = false;

	//Stats!
	uint8_t statFixing;
	//Stats!
public:
	int8_t hp = 100;
	bool alive = false;

	Peep(Ship &ship);
	Species getSpecies();
	void setPos(uint8_t x,uint8_t y);
	Point getPos();
	void update();
	void reset();
	void draw(System *ab);
};

Peep::Peep(Ship &ship)
{
	this->ship = &ship;
	alive = true;
	reset();
}

void Peep::update()
{
	if(moved)
	{
		roomID = ship->roomIDFromPoint(position);
		roomData = ship->roomFromID(roomID);
		moved = false;
	}
}

void Peep::reset()
{
	roomID = 1;	//medbay
	roomData = ship->roomFromID(roomID);
	position.x = roomData.shape.x;
	position.y = roomData.shape.y;
}

void Peep::setPos(uint8_t x,uint8_t y)
{
	this->position.x = x;
	this->position.y = y;
	moved = true;
}

Point Peep::getPos()
{
	return position;
}

Species Peep::getSpecies()
{
	return species;
}

void Peep::draw(System *ab)
{
	if(alive)
		ab->drawCircle(position.x,position.y,4);
}

class PeepControl
{
public:
	//uint8_t peepmax = 10;
	uint8_t peepmax;
	Peep peeps[10];

	uint8_t add();
	void kill(uint8_t id);

	void update();
	void draw();
};

uint8_t PeepControl::add()
{
	peepmax = 10;
	for(uint8_t p=0; p<peepmax; ++p)
	{
		if(peeps[p].alive == false)
		{
			peeps[p].alive = true;
			peeps[p].reset();
			return p;
		}
	}
	return 255;
};

void PeepControl::kill(uint8_t id)
{
	if(id<peepmax)
		peeps[id].alive = false;
}