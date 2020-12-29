#include "exit.hpp"

mine_exit::mine_exit(float x, float y, float width, float height) : grid_cell(x, y, width, height)
{
	this->color = GREEN;
	destructable = false;
	blocked = false;
	cell_type = map_object::ENTRY;
}

void mine_exit::draw()
{
	DrawRectangleRec(*this, color);
	//DrawTextureEx(textures[cell_type], { x, y }, 0, 3, WHITE);
}