#pragma once

#include <raylib.h>

#include "window.hpp"
#include "dwarf.hpp"

#include "../buttons/navigate_buttons.hpp"


class equipment_bar: Rectangle, window
{
public:

	equipment_bar(dwarf* player) {

		this->player = player;

		//rectangle properties //maly na srodku
		/*this->width = 400;
		this->height = 100;
		this->x = (window_width- width)/2;
		this->y = window_height - height;*/


		//na cala szerokosc
		this->width = window_width;
		this->height = 150;
		this->x = 0;
		this->y = window_height - height;


	}

	void update(){}

	void draw() {

		DrawRectangleRec(*this, Color{255,255,255,50});

	}
	

private:

	dwarf* player;

	

		


};

