/*
(slightly)Faster than Light
*/
#include "system.h"
#include "game.h"
System ab;
Game game(ab);

void setup()
{
	ab.begin();	
  	Serial.begin(9600);
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