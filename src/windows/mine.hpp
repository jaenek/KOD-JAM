#pragma once

#include <raylib.h>

#include "window.hpp"
#include "../buttons/navigate_buttons.hpp"
#include "../dwarf/dwarf.hpp"
#include "../grid/grid.hpp"

class mine : window
{
friend class shop;

private:
	leave_mine_btn leave_mine;
	grid mine_grid;
	map_generator map_gen{1000};
	dwarf player{mine_grid, 60, 90};
	Camera2D camera{};

public:
	mine();

	inline dwarf& get_dwarf()
	{
		return player;
	}

	void update();

	void draw();
};

