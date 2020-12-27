#include "main_window.hpp"

void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	grid g(window_width, 0);
	map_generator m(1000);
	g.transform(m);

	bool quit = false;
	while (!WindowShouldClose() & !quit) {
		BeginDrawing();

		ClearBackground(BLACK);

		g.draw();
		DrawRectangleRec({ static_cast<float>(window_width / 2) + 330 , static_cast<float>(window_height / 2) + 90, 30.f, 90.f }, GREEN);

		EndDrawing();
	}

	CloseWindow();
}
