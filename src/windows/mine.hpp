#pragma once

#include <raylib.h>

#include "window.hpp"
#include "main_window.hpp"
#include "../buttons/navigate_buttons.hpp"
#include "../dwarf/dwarf.hpp"
#include "../grid/grid.hpp"

class mine : window
{
friend class shop;

private:
	leave_mine_btn leave_mine;
	grid mine_grid{window_width};
	map_generator map_gen{1000};
	dwarf player{mine_grid, 60, 90};
	Camera2D camera{};

public:
	mine() : leave_mine(425, 450, 150, 75, "Back to town", 20, GRAY, LIGHTGRAY, BROWN, GRAY, DARKBROWN, GRAY)
	{
		mine_grid.transform(map_gen);

		std::map<map_object, std::string> assets = {
			{ map_object::TUNNEL, "assets/Podloga.png" },
			{ map_object::ROCK, "assets/Sciana.png" },
			{ map_object::GOLD_ORE, "assets/Zloto.png" },
			{ map_object::TORCH, "assets/Pochodnia.png" },
		};

		for (auto const& [key, val] : assets)
			grid_cell::textures[key] = LoadTexture(val.c_str());

		player.set_start_pos(15, 15);

		camera.target = {player.x, player.y};
		camera.offset = {static_cast<float>(window_width)/2, static_cast<float>(window_height)/2};
		camera.rotation = 0.0f;
		camera.zoom = 0.8f;
	}

	
	dwarf& get_dwarf() {

		return player;
	}


	void update() {
		if (IsKeyPressed(KEY_W))
			player.move_up(camera);
		else if (IsKeyPressed(KEY_S))
			player.move_down(camera);
		else if (IsKeyPressed(KEY_A))
			player.move_left(camera);
		else if (IsKeyPressed(KEY_D))
			player.move_right(camera);

		if (IsKeyPressed(KEY_SPACE))
			player.use_pickaxe();
		if (IsKeyPressed(KEY_T))
			player.place_torch();
		if (IsKeyPressed(KEY_E))
			player.exit_mine(camera);
		if (IsKeyPressed(KEY_L))
			player.leave_mine();

		leave_mine.update();
	}

	void draw() {
		{
			BeginMode2D(camera);

			mine_grid.draw();
			player.draw();

			EndMode2D();
		}

		leave_mine.draw();


		const char* text = "MINE";
		DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
	}
};

