#pragma once

#include <raylib.h>

#include "window.hpp"
#include "main_window.hpp"

#include "button.hpp"

class mine : window
{
private:
	leave_mine_btn leave_mine;

public:
	mine() :
		leave_mine(425, 450, 150, 75, "Back to town", 20, GRAY, LIGHTGRAY) {}

	void draw() {
		leave_mine.update();

		leave_mine.draw();

		const char* text = "MINE";
		DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
	}
};

