#pragma once
#include <Arduboy2.h>

class System : public Arduboy2
{
	private:
		
	public:
		void step();
};

void System::step()
{
	while(1)
	{
		if (!this->nextFrame())
			return;
		this->pollButtons();

		this->drawPixel(64,32,WHITE);
			
		this->display();
	}
}