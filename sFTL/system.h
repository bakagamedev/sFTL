#pragma once
#include <Arduboy2.h>

class System : public Arduboy2
{
	//stick stuff here
private:
	bool screenOutput = false;

public:
	void screenSend()
	{
		if(screenOutput)
			Serial.write(getBuffer(), 128 * 64 / 8);
	};

	void drawNoise()
	{
		int8_t i = rand();
	    while(--i > 0)
	    {
	      auto buf = getBuffer();
	      buf += rand() % (WIDTH * HEIGHT / 8);
	      *buf = rand();
	    }
	}
};