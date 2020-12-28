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

	Camera2D camera = {0};
	camera.target = {player.x, player.y};
	camera.offset = {static_cast<float>(window_width/2), static_cast<float>(window_height/2)};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	bool quit = false;
	while (!WindowShouldClose() & !quit) {
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

		BeginDrawing();
		BeginMode2D(camera);

		ClearBackground(BLACK);

		mine_grid.draw();
		player.draw();
		EndMode2D();
		EndDrawing();
	}

	CloseWindow();
}
