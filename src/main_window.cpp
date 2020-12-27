#include "main_window.hpp"

void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	grid g(window_width, 60);

	bool quit = false;
	while (!WindowShouldClose() & !quit) {

		BeginDrawing();

		ClearBackground(BLACK);

		g.draw();

		EndDrawing();
	}

	CloseWindow();
}
