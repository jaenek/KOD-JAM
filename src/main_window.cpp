#include "main_window.hpp"

void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	bool quit = false;
	while (!WindowShouldClose() & !quit) {

		BeginDrawing();

		ClearBackground(RAYWHITE);

		const char* text = "tu ma byc gra";
		DrawText(text, (window_width-MeasureText(text,20))/2, window_height/2-10, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();
}
