#pragma once

#include <raylib.h>

#include "window.hpp"
#include "main_window.hpp"

#include "../buttons/all_buttons.hpp"

class shop : window
{
private:
	leave_shop_btn leave_shop;

public:
	shop() : leave_shop(425, 450, 150, 75, "Back to town", 20, GRAY, LIGHTGRAY){}

	void update()
	{
		leave_shop.update();
	}

	void draw()
	{
		leave_shop.draw();

		const char* text = "SHOP";
		DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
	}
};

