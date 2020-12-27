#pragma once

#include <raylib.h>

#include "grid.hpp"

class main_window
{
public:
	void loop();

private:
	const int window_width = 1200, window_height = 600;
};
