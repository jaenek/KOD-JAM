#pragma once

#include <raylib.h>

#include "window.hpp"
#include "../buttons/navigate_buttons.hpp"
#include "../buttons/church_buttons.hpp"
#include "../dwarf/dwarf.hpp"

class church: window
{
private:

	leave_church_btn leave_church;
	church_buttons pay_and_pray;
	dwarf& player;

	Texture2D texture = LoadTexture("assets/kosciol_taca.png");

	unsigned int frame_counter = 0;

public:
	
	church(dwarf& player);

	void update();

	void draw();

};

