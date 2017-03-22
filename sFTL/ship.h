#pragma once
#include "list.h"
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
	uint8_t functional = 1;
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
using RoomList = List<ShipRoom, 10>;

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

	Ship(System &ab);
	void setType(ShipType type);

	void step();
	void draw(int8_t selected,int8_t offset);

	uint8_t roomIDFromPoint(Point pos);
	ShipRoom roomFromID(uint8_t id);
};
Ship::Ship(System &ab)
{
	this->ab = &ab;
};

void Ship::step()
{
	for(uint8_t r=0; r<rooms.getCount(); ++r)
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

	rooms.add(ShipRoom(RoomType::bridge,Rectangle(80,16,16,24)));	//Bridge
	rooms.add(ShipRoom(RoomType::sickbay,Rectangle(64,16,16,24)));	//Medbay
	rooms.add(ShipRoom(RoomType::shield,Rectangle(32,16,32,12)));	//Shield
	rooms.add(ShipRoom(RoomType::weapons,Rectangle(32,28,32,12)));	//Weapons
	rooms.add(ShipRoom(RoomType::engine,Rectangle(16,16,16,24)));	//Engine
	rooms.add(ShipRoom(RoomType::empty,Rectangle(0,40,48,16)));		//Right Strut
	rooms.add(ShipRoom(RoomType::empty,Rectangle(0,0,48,16)));		//Left Strut

	roomNum = rooms.getCount();
};

uint8_t Ship::roomIDFromPoint(Point pos)
{
	for(uint8_t i=0; i<rooms.getCount(); ++i)
	{
		Rectangle shape = rooms[i].shape;
		if(ab->collide(pos,shape))
			return i;
	}
	return 255;
}

ShipRoom Ship::roomFromID(uint8_t id)
{
	if(id<rooms.getCount())
		return rooms[id];
	return rooms[0];
}

void Ship::draw(int8_t selected,int8_t offset)
{
	for(uint8_t i=0; i<rooms.getCount(); ++i)
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