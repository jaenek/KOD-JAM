#include "main_window.hpp"
#include "town.hpp"
#include "shop.hpp"
#include "mine.hpp"

void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	grid mine_grid(window_width);

	map_generator map_gen(1000);
	mine_grid.transform(map_gen);

	std::map<map_object, std::string> assets = {
		{ map_object::TUNNEL, "assets/Podloga.png" },
		{ map_object::ROCK, "assets/Sciana.png" },
		{ map_object::GOLD_ORE, "assets/Zloto.png" },
	};

	for (auto const& [key, val] : assets)
		grid_cell::textures[key] = LoadTexture(val.c_str());

	dwarf player(mine_grid, 60, 90);
	player.set_start_pos(11, 55);

	Camera2D camera = {0};
	camera.target = {player.x, player.y};
	camera.offset = {static_cast<float>(window_width/2), static_cast<float>(window_height/2)};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	town town;
	shop shop;
	mine mine;

	bool quit = false;
	while (!WindowShouldClose() & !quit) {
		mouse_position = GetMousePosition();

		if (draw_window == window_type::TOWN) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			town.draw();
			EndDrawing();
		}
		else if (draw_window == window_type::SHOP) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			shop.draw();
			EndDrawing();

		}
		else if (draw_window == window_type::MINE) {
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

			BeginMode2D(camera);

			ClearBackground(BLACK);

			mine_grid.draw();
			player.draw();
			EndMode2D();

			mine.draw();
			EndDrawing();
		}

	}

	CloseWindow();
}
