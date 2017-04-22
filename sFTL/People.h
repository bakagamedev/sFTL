#pragma once
#include "ardutils\Collections.h"
#include "strings.h"
#include "types.h"
#include "system.h"
#include "ship.h"

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

	//Stats!
	//Stat statFixing = Stat(1,0,5);
	//Stat statPilot = Stat(1,0,5);
	//Stats!
public:
	char name[8];
	
	ByteClamped hp = ByteClamped(100,0,100);

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
	void draw(bool selected,int8_t offset);
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
	ShipRoom roomData;
	bool moved = false;

	/* test code */
	--count;
	if((count < 0) && (destination == position))		//If standing still, walk to a random room
	{
		roomID = random(0,6);	//Pick random room
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
	}
}

void Peep::reset()
{
	roomID = random(0,6);	//ship->roomIDFromType(RoomType::bridge);	//Spawn on the bridge
	ShipRoom roomData;
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

void Peep::draw(bool selected,int8_t offset)
{
	if(alive)
	{
		ab->drawCircle(position.X + offset,position.Y,3);
		if(selected)
			ab->drawCircle(position.X + offset,position.Y,5);
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

	void getName(uint8_t id,char *name);

	void add();
	void kill(uint8_t id);

	void setup(System &ab,Ship &ship);
	void step();
	void draw(int8_t selected,int16_t offset);
};
PeepControl::PeepControl(System &ab,Ship &ship)
{
	this->ab = &ab;
	this->ship = &ship;	
};

void PeepControl::getName(uint8_t id,char *name)
{
	if(id<peepNum)
	{
		//return peeps[id].name;
		strcpy(name,peeps[id].name);
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

void PeepControl::draw(int8_t selected,int16_t offset)
{
	for(uint8_t i=0; i<peeps.GetCount(); ++i)
	{
		peeps[i].draw(i==selected,offset);
	}
}