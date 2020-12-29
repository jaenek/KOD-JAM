#include "main_window.hpp"

void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	town town;
	shop shop;
	mine mine;

	bool quit = false;
	while (!WindowShouldClose() & !quit) {
		mouse_position = GetMousePosition();

		if (draw_window == window_type::TOWN) {
			town.update();
			BeginDrawing();
			ClearBackground(RAYWHITE);
			town.draw();
			EndDrawing();
		}
		else if (draw_window == window_type::SHOP) {
			shop.update();
			BeginDrawing();
			ClearBackground(RAYWHITE);
			shop.draw();
			EndDrawing();

		}
		else if (draw_window == window_type::MINE) {
			mine.update();
			BeginDrawing();
			ClearBackground(RAYWHITE);
			mine.draw();
			EndDrawing();
		}

	}

	CloseWindow();
}
