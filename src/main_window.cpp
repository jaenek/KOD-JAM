#include "main_window.hpp"


void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	grid mine_grid(window_width, 0);

	map_generator map_gen(1000);
	grid_assets assets;
	mine_grid.transform(map_gen, assets);

	dwarf player(mine_grid, 60, 90);
	player.set_start_pos(11, 55);

	bool quit = false;
	while (!WindowShouldClose() & !quit) {
		if (IsKeyPressed(KEY_W))
			player.move_up();
		else if (IsKeyPressed(KEY_S))
			player.move_down();
		else if (IsKeyPressed(KEY_A))
			player.move_left();
		else if (IsKeyPressed(KEY_D))
			player.move_right();

		if (IsKeyPressed(KEY_SPACE))
			player.use_pickaxe();

		BeginDrawing();

		ClearBackground(BLACK);

		mine_grid.draw();
		player.draw();

		EndDrawing();
	}

	CloseWindow();
}
