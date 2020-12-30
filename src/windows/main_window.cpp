#include "main_window.hpp"

void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	town town;
	mine mine;
	shop shop(mine.get_dwarf());
	
	

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
			ClearBackground(BLACK);
			mine.draw();
			EndDrawing();
		}

	}

	CloseWindow();
}
