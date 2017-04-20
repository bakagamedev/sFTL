#pragma once
#include "ardutils/list.h"
#include "types.h"
#include "system.h"

struct Rectangle : public Rect
{
public:
	set(const uint8_t x,const uint8_t y,const uint8_t width,const uint8_t height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	};
	Rectangle(void) = default;
	Rectangle(const uint8_t x,const uint8_t y,const uint8_t width,const uint8_t height)
	{
		set(x,y,width,height);
	};
};

class ShipRoom
{
public:
	RoomType type = RoomType::empty;
	int8_t hp = 100;

	bool functional;
	bool occupied = false;

	Rectangle shape;
	uint8_t crew;

	void update()
	{
		functional = (hp>=20);
	}
	ShipRoom(void) = default;
	ShipRoom(RoomType type,Rectangle rect)
	{
		this->type = type;
		this->shape.set(rect.x,rect.y,rect.width,rect.height);
	};
};
using RoomList = Ardutils::List<ShipRoom, 10>;

class Ship
{
private:
	System *ab;

	ShipType type;
	RoomList rooms;

	int16_t shieldMax = 100;
	int16_t shield = 100;
public:
	uint8_t roomNum = 0;

	char* getRoomName(uint8_t id);

	Ship(System &ab);
	void setType(ShipType type);

	void step();
	void draw(int8_t selected,int8_t offset);

	uint8_t roomIDFromPoint(Point pos);
	uint8_t roomIDFromType(RoomType type);
	ShipRoom roomFromID(uint8_t id);
};
Ship::Ship(System &ab)
{
	this->ab = &ab;
};

char* Ship::getRoomName(uint8_t id)
{
	if(id<rooms.GetCount())
	{
		uint8_t type = (uint8_t)(rooms[id].type);
		char name[8];
		strcpy_P(name, (char*)pgm_read_word(&(nameShipParts[type])));
		return name;
	}
};


void Ship::step()
{
	for(uint8_t r=0; r<rooms.GetCount(); ++r)
	{
		rooms[r].update();
	}
	if(shield < shieldMax)
	{
		shield += rooms[2].functional;
	}
}

void Ship::setType(ShipType type)
{
	this->type = type;

	rooms.Add(ShipRoom(RoomType::bridge,Rectangle(80,16,16,24)));	//Bridge
	rooms.Add(ShipRoom(RoomType::sickbay,Rectangle(64,16,16,24)));	//Medbay
	rooms.Add(ShipRoom(RoomType::shield,Rectangle(32,16,32,12)));	//Shield
	rooms.Add(ShipRoom(RoomType::weapons,Rectangle(32,28,32,12)));	//Weapons
	rooms.Add(ShipRoom(RoomType::engine,Rectangle(16,16,16,24)));	//Engine
	rooms.Add(ShipRoom(RoomType::empty,Rectangle(0,40,48,16)));		//Right Strut
	rooms.Add(ShipRoom(RoomType::empty,Rectangle(0,0,48,16)));		//Left Strut

	roomNum = rooms.GetCount();
};

uint8_t Ship::roomIDFromPoint(Point pos)
{
	for(uint8_t i=0; i<rooms.GetCount(); ++i)
	{
		Rectangle shape = rooms[i].shape;
		if(ab->collide(pos,shape))
			return i;
	}
	return 255;
}

uint8_t Ship::roomIDFromType(RoomType type)
{
	for(uint8_t i=0; i<rooms.GetCount(); ++i)
	{
		if(rooms[i].type == type)
			return i;
	}
	return 255;
}

ShipRoom Ship::roomFromID(uint8_t id)
{
	if(id<rooms.GetCount())
		return rooms[id];
	return rooms[0];
}

void Ship::draw(int8_t selected,int8_t offset)
{
	for(uint8_t i=0; i<rooms.GetCount(); ++i)
	{
		Rectangle shape = rooms[i].shape;
		ab->fillRect(offset+shape.x,shape.y,shape.width,shape.height,0);
		ab->drawRect(offset+shape.x,shape.y,shape.width,shape.height,1);

		if(selected==i)
		{
			ab->drawRect(offset+shape.x+2,shape.y+2,shape.width-4,shape.height-4,1);
		}
	}
}