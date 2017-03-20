/*
(slightly) Faster than Light
*/
#include "system.h"
#include "game.h"
System ab;
Game game(ab);

void setup()
{
	ab.begin();	
}

void loop()
{	
	if(!ab.nextFrame())
		return;
	ab.pollButtons();

	game.step();
	game.draw();

	ab.display();
}