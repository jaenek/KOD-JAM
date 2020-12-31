#include "mine.hpp"

mine::mine() : leave_mine(425, 450, 150, 75, "Back to town", 20, GRAY, LIGHTGRAY, BROWN, GRAY, DARKBROWN, GRAY)
{
	mine_grid.transform(map_gen);

	for (auto const& [key, val] : assets)
		grid_cell::textures[key] = LoadTexture(val.c_str());

	player.set_start_pos(15, 15);

	camera.target = {player.x, player.y};
	camera.offset = {static_cast<float>(window_width)/2, static_cast<float>(window_height)/2};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
}

mine::~mine()
{
	for (auto const& [key, val] : assets)
		UnloadTexture(grid_cell::textures[key]);
}

void mine::update(bool & quit)
{
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
		player.exit_mine(camera, quit); 
	if (IsKeyPressed(KEY_L))
		player.leave_mine();

	leave_mine.update();
	equipment_bar.update();
}

void mine::draw()
{
	BeginMode2D(camera);

		mine_grid.draw();
		player.draw();

	EndMode2D();

	BeginShaderMode(player.torch_lights.shader);

		DrawRectangleRec(mine_grid, WHITE);

	EndShaderMode();


	leave_mine.draw();
	equipment_bar.draw();


	const char* text = "MINE";
	DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
}
