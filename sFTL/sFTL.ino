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

	ab.setCursor(0,0);
	//ab.print(game.warp);

  	//Serial.write(ab.getBuffer(), 128 * 64 / 8);
	ab.display();
}