#pragma once
#include "system.h"

#define starNum 15

class Background 
{
private:
	System *ab;
	Point stars[starNum];
public:
	Background(System &ab);

	void reset();
	void draw();
};

Background::Background(System &ab)
{
	this->ab = &ab;

	reset();	//first attempt always ends up with weird clumps. 
	reset();
};

void Background::reset()
{
	for(uint8_t i=0; i<starNum; ++i)
	{
		stars[i].x = random(128);
		stars[i].y = random(56);
	}
}

void Background::draw()
{
	for(uint8_t i=0; i<starNum; ++i)
		ab->drawPixel(stars[i].x,stars[i].y,1);
};