#include "main_window.hpp"


void main_window::loop()
{
	InitWindow(window_width, window_height, "kod-jam");
	SetTargetFPS(60);

	grid g(window_width, 0);
	map_generator m(1000);
	g.transform(m);

	dwarf player(g, 60, 90);
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

		BeginDrawing();

		ClearBackground(YELLOW);

		g.draw();
		player.draw();

		EndDrawing();
	}

	CloseWindow();
}
