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
	ShipRoom room;
	bool moved;

	//Stats!
	uint8_t statFixing;
	//Stats!
public:
	Peep(Ship &ship);
	Species getSpecies();
	void setPos(uint8_t x,uint8_t y);
	Point getPos();
	void update();
	void draw();
}

Peep::Peep(Ship &ship)
{
	this->ship = &ship;
}

void update()
{
	if(moved)
	{
		room = ship->roomFromPoint(position);
	}
}

void Peep::setPos(uint8_t x,uint8_t y)
{
	this->x = x;
	this->y = y;
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
	ab->drawCircle(position.x,position.y,4);
}