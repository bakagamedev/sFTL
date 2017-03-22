#pragma once
#include "strings.h"
#include "types.h"
#include "list.h"
#include "system.h"
#include "ship.h"

class Peep
{
private:
	System *ab;
	Ship *ship;

	Species species;
	Point position;

	uint8_t roomID = 0;
	ShipRoom roomData;

	bool moved = false;
	//Stats!
	//Stat statFixing = Stat(1,0,5);
	//Stat statPilot = Stat(1,0,5);
	//Stats!
public:
	char name[8];

	int8_t hp = 100;
	bool alive = false;

	Peep(void) = default;
	Peep(System &ab,Ship &ship);

	Species getSpecies();
	void setPos(uint8_t x,uint8_t y);
	Point getPos();
	void update();
	void reset();
	void draw(bool selected);
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
	roomID = random(0,6);	//ship->roomIDFromType(RoomType::bridge);	//Spawn on the bridge
	roomData = ship->roomFromID(roomID);
	position.x = roomData.shape.x + (roomData.shape.width / 2);
	position.y = roomData.shape.y + (roomData.shape.height / 2);

	strcpy_P(name, (char*)pgm_read_word(&(nameCrew[random(5)])));
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

void Peep::draw(bool selected)
{
	if(alive)
	{
		ab->drawCircle(position.x,position.y,3);
		if(selected)
			ab->drawCircle(position.x,position.y,5);
	}
}

class PeepControl
{
private:
	Ship *ship;
	System *ab;
	PeepList peeps;

public:
	int8_t peepNum = 0;
	PeepControl(System &ab,Ship &ship);

	char* getName(uint8_t id);

	void add();
	void kill(uint8_t id);

	void setup(System &ab,Ship &ship);
	void step();
	void draw(int8_t selected);
};
PeepControl::PeepControl(System &ab,Ship &ship)
{
	this->ab = &ab;
	this->ship = &ship;	
};

char* PeepControl::getName(uint8_t id)
{
	if(id<peepNum)
	{
		return peeps[id].name;
	}
};

void PeepControl::add()
{
	peeps.add(Peep(*ab,*ship));
	peepNum = peeps.getCount();
};

void PeepControl::kill(uint8_t id)
{
	peeps.removeAt(id);
	peepNum = peeps.getCount();
}

void PeepControl::step()
{
	for(uint8_t i=0; i<peeps.getCount(); ++i)
	{
		peeps[i].update();

		if(peeps[i].alive == false)
			kill(i);
	}
}

void PeepControl::draw(int8_t selected)
{
	for(uint8_t i=0; i<peeps.getCount(); ++i)
	{
		peeps[i].draw(i==selected);
	}
}