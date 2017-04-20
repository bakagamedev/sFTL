#pragma once
#include "strings.h"
#include "types.h"
#include "ardutils/List.h"
#include "system.h"
#include "ship.h"

//bodge zone
Point Convert(BytePoint other) { Point point; point.x = other.X; point.y=other.Y; return point; }
//bodge zone

class Peep
{
private:
	System *ab;
	Ship *ship;

	Species species;
	BytePoint position;
	BytePoint destination;

	int8_t count = 10;

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
	BytePoint getPos();

	void setDestination(uint8_t x,uint8_t y);
	void setDestination(ShipRoom room);

	void update();
	void reset();
	void draw(bool selected);
};
using PeepList = Ardutils::List<Peep, 10>;	

Peep::Peep(System &ab,Ship &ship)
{
	this->ab = &ab;
	this->ship = &ship;	
	alive = true;
	reset();
}

void Peep::update()
{
	/* test code */
	--count;
	if((count < 0) && (destination == position))		//If standing still, walk to a random room
	{
		roomID = random(0,5);	//Pick random room
		//roomID = ship->roomIDFromType(RoomType::bridge);	//Spawn on the bridge
		roomData = ship->roomFromID(roomID);
		setDestination(roomData.shape.X+8,roomData.shape.Y+8);
		count = 120;
	}
	/* test code */

	//Manhattan distances, ho!
	if(destination.Y != position.Y)	//Solve Y first, then X.
	{
		if(position.Y > destination.Y)	
			position.Y--;
		else
			position.Y++;
		moved = true;
	}
	else if(destination.X != position.X)
	{
		if(position.X > destination.X)	
			position.X--;
		else
			position.X++;
		moved = true;
	}
	//As long as ship designs stay rectangley, they shouldn't walk out of bounds

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
	position.X = roomData.shape.X + (roomData.shape.Width / 2);
	position.Y = roomData.shape.Y + (roomData.shape.Height / 2);
	setDestination(position.X,position.Y);

	strcpy_P(name, (char*)pgm_read_word(&(nameCrew[random(5)])));
}

void Peep::setPos(uint8_t x,uint8_t y)
{
	this->position.X = x;
	this->position.Y = y;
	moved = true;
}

BytePoint Peep::getPos()
{
	return position;
}

void Peep::setDestination(uint8_t x,uint8_t y)
{
	this->destination = BytePoint(x,y);
}
void Peep::setDestination(ShipRoom room)
{
	this->destination = BytePoint(room.shape.X,room.shape.Y);
}

Species Peep::getSpecies()
{
	return species;
}

void Peep::draw(bool selected)
{
	if(alive)
	{
		ab->drawCircle(position.X,position.Y,3);
		if(selected)
			ab->drawCircle(position.X,position.Y,5);
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
	peeps.Add(Peep(*ab,*ship));
	peepNum = peeps.GetCount();
};

void PeepControl::kill(uint8_t id)
{
	peeps.RemoveAt(id);
	peepNum = peeps.GetCount();
}

void PeepControl::step()
{
	for(uint8_t i=0; i<peeps.GetCount(); ++i)
	{
		peeps[i].update();

		if(peeps[i].alive == false)
			kill(i);
	}
}

void PeepControl::draw(int8_t selected)
{
	for(uint8_t i=0; i<peeps.GetCount(); ++i)
	{
		peeps[i].draw(i==selected);
	}
}