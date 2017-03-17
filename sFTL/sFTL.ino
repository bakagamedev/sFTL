/*
(slightly) Faster than Light
*/
#include <Arduboy2.h>
#include "system.h"

int main(void)
{
	init();
	#ifdef USBCON
    	USBDevice.attach();
	#endif
	System ab = System();

	ab.boot();

	while(1)
	{  
		if (ab.nextFrame())
		{
			ab.pollButtons();

			ab.display();
		}
	}
}