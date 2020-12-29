#pragma once

#include <raylib.h>

#include "window.hpp"
#include "main_window.hpp"

#include "all_buttons.hpp"

class town : window
{
private:
	go_shop_btn go_shop;
	go_mine_btn go_mine;

public:
	town(): go_shop(50, 450, 150, 75, "Shop", 20, GRAY, LIGHTGRAY),
		go_mine(window_width-200, 450, 150, 75, "Mine", 20, GRAY, LIGHTGRAY) {}


	void update()
	{
		go_shop.update();
		go_mine.update();
	}

	void draw()
	{
		go_shop.draw();
		go_mine.draw();

		const char* text = "TOWN";
		DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
	}
};

