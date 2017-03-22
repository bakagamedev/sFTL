#pragma once
#include "types.h"
#include "list.h"
#include "system.h"
#include "ship.h"

class Peep
{
private:
	Species species;
	Point position;
	uint8_t roomID = 0;
	ShipRoom roomData;
	bool moved = false;
	//Stats!
	uint8_t statFixing;
	//Stats!
public:
	System *ab;
	Ship *ship;

	int8_t hp = 100;
	bool alive = false;

	Peep(void) = default;
	Peep(System &ab,Ship &ship);

	Species getSpecies();
	void setPos(uint8_t x,uint8_t y);
	Point getPos();
	void update();
	void reset();
	void draw();
};
using PeepList = List<Peep, 10>;	

Peep::Peep(System &ab,Ship &ship)
{
	this->ab = &ab;
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

void Peep::draw()
{
	if(alive)
		ab->drawCircle(position.x,position.y,4);
}

class PeepControl
{
private:
	Ship *ship;
	System *ab;
	PeepList peeps;

public:
	PeepControl(System &ab,Ship &ship);

	void add();
	void kill(uint8_t id);

	void setup(System &ab,Ship &ship);
	void step();
	void draw();
};
PeepControl::PeepControl(System &ab,Ship &ship)
{
	this->ab = &ab;
	this->ship = &ship;	

	add();
};

void PeepControl::add()
{
	peeps.add(Peep(*ab,*ship));
};

void PeepControl::kill(uint8_t id)
{
	peeps.removeAt(id);
}

void PeepControl::step()
{
	for(uint8_t i=0; i<peeps.getCount(); ++i)
	{
		peeps[i].update();
	}
}

void PeepControl::draw()
{
	for(uint8_t i=0; i<peeps.getCount(); ++i)
	{
		peeps[i].draw();
	}
}