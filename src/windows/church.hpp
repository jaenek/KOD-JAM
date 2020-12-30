#pragma once

#include <raylib.h>

#include "window.hpp"
#include "../buttons/navigate_buttons.hpp"

class church: window
{
private:

	leave_church_btn leave_church;

	/*Image image = LoadImage("assets/Kosciol.png");
	Texture2D texture = LoadTextureFromImage(image);*/

public:
	
	church();

	void update();

	void draw();

};

