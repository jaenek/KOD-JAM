#pragma once

#include <raylib.h>

#include "grid.hpp"

class main_window
{
public:
	void loop();

private:
	const int window_width = 1440, window_height = 1080;
};
