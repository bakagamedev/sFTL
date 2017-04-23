/*
(slightly)Faster than Light
*/
#include "system.h"
#include "game.h"
#include "sprites.h"
System ab;
Game game(ab);

void setup()
{
	ab.begin();	
  	Serial.begin(9600);

  	int8_t logoY=-64;
  	while(logoY++ < 64)
  	{
  		while(!ab.nextFrame())	{	};

  		ab.fillRect(0,-1,128,logoY,0);
  		ab.drawCompressed(0,min(logoY,0),uiLogo,1);
  		ab.display();
  	}
}

void loop()
{	
	if(!ab.nextFrame())
		return;
	ab.pollButtons();

	game.step();
	game.draw();

	ab.screenSend();

	ab.display();
}