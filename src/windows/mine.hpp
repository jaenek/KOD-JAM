#pragma once

#include <raylib.h>

#include "window.hpp"
#include "../buttons/navigate_buttons.hpp"
#include "../dwarf/dwarf.hpp"
#include "../dwarf/equipment_bar.hpp"
#include "../grid/grid.hpp"


class mine : window
{
friend class shop;

private:
	const std::map<map_object, std::string> assets = {
		{ map_object::TUNNEL, "assets/Podloga.png" },
		{ map_object::ROCK, "assets/Sciana.png" },
		{ map_object::BORDER, "assets/Sciana-Krawedz.png"},
		{ map_object::GOLD_ORE, "assets/Zloto.png" },
		{ map_object::ENTRY, "assets/Drabina-Gora.png" },
		{ map_object::EXIT, "assets/Drabina-Dol.png" },
		{ map_object::TORCH, "assets/Pochodnia.png" },
	};

	leave_mine_btn leave_mine;
	grid mine_grid;
	map_generator map_gen{ GetRandomValue(1, 10000) };
	dwarf player{mine_grid, 60, 90};
	equipment_bar equipment_bar{ &player };
	Camera2D camera{};

public:
	mine();

	~mine();

	inline dwarf& get_dwarf()
	{
		return player;
	}

	void update(bool & quit);

	void draw();
};

