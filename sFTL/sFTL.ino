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

  	/*
  	int8_t logoY=-64;
  	while(int8_t < 0)
  	{
  		while(!ab.nextFrame())	{	};
  		ab.drawBitmap(0,logoY,uiLogo,128,64);
  		ab.display();
  	}
  	*/
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