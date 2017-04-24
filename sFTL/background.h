#pragma once
#include "system.h"
#include "types.h"

#define starNum 15

class Background 
{
private:
	System *ab;
	Point stars[starNum];
	BackgroundType type;
public:
	Background(System &ab);

	void reset();
	void reset(BackgroundType type);
	void draw();
};

Background::Background(System &ab)
{
	this->ab = &ab;

	reset();	//first attempt always ends up with weird clumps. 
	reset();
};

void Background::reset(BackgroundType type)
{
	this->type = type;	
	for(uint8_t i=0; i<starNum; ++i)
	{
		stars[i].x = random(128);
		stars[i].y = random(56);
	}
}

void Background::reset()
{
	reset(BackgroundType::Stars);	//Default for maximum lazy
}

void Background::draw()
{
	for(uint8_t i=0; i<starNum; ++i)
		ab->drawPixel(stars[i].x,stars[i].y,1);

	switch(type)
	{
		case BackgroundType::Planet:
		{
			ab->drawCircle(128,64,32,1);
		}; break;
	}
};