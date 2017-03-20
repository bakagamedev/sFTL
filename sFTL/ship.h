#pragma once
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
	}
};

struct ShipRoom
{
	int8_t hp = 100;
	int8_t oxygen = 100;
	Rectangle shape;
};

class Ship
{
private:
	ShipType type;
	ShipRoom rooms[10];
public:
	uint8_t roomNum = 0;
	Ship();
	void setType(ShipType type);
	//void setType();
	void draw(System *ab,int8_t selected);
};

Ship::Ship()
{
	
};

void Ship::setType(ShipType type)
{
	this->type = type;
	roomNum = 7;

	rooms[0].shape.set(80,16,16,24);	//Bridge
	rooms[1].shape.set(64,16,16,24);	//Medbay
	rooms[2].shape.set(32,16,32,12);	//Shield
	rooms[3].shape.set(32,28,32,12);	//Weapons
	rooms[4].shape.set(16,16,16,24);	//Engine
	rooms[5].shape.set(0,0,48,16);		//Left Strut
	rooms[6].shape.set(0,40,48,16);		//Right Strut
};

void Ship::draw(System *ab,int8_t selected)
{
	for(uint8_t i=0; i<roomNum; ++i)
	{
		Rectangle shape = rooms[i].shape;
		ab->drawRect(shape.x,shape.y,shape.width,shape.height,1);

		if(selected==i)
		{
			ab->drawRect(shape.x+2,shape.y+2,shape.width-4,shape.height-4,1);
		}
	}
};