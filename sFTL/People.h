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

	Peep(System &ab,Ship &ship);
	Species getSpecies();
	void setPos(uint8_t x,uint8_t y);
	Point getPos();
	void update();
	void reset();
	void draw(System *ab);
};
using PeepList = List<Peep, 10>;

Peep::Peep(System &ab,Ship &ship);
{
	this->ab = &ab;
	this->ship = &ship;	
	alive = true;
	reset();
};

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
	Ship *ship;
	System *ab;
	PeepControl();
	PeepList peeps;

	uint8_t add();
	void kill(uint8_t id);

	void setup(System &ab,Ship &ship);
	void step();
	void draw();
};
PeepControl::PeepControl()	{};

void PeepControl::setup(System &ab,Ship &ship)
{
	/* 
	FAQ excerpt;
	Q) Shouldn't this be in a constructor?
	A) Great question! Yes it should!
	*/
	peepmax = 10;
	this->ab = &ab;
	this->ship = &ship;
	for(uint8_t p=0; p<10; ++p)
	{
		peeps[p].ab = &ab;
		peeps[p].ship = &ship;
	}
}

uint8_t PeepControl::add()
{
	peeps.add(Peep(ab,ship));
	return 255;
};

void PeepControl::kill(uint8_t id)
{
	if(id<peepmax)
		peeps[id].alive = false;
}

void PeepControl::step()
{
	for(uint8_t i=0; i<peepmax; ++i)
		peeps[i].update();
}

void PeepControl::draw()
{
	for(uint8_t i=0; i<peepmax; ++i)
		peeps[i].draw(ab);
}