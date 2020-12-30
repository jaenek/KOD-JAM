#include "entry.hpp"

mine_entry::mine_entry(float x, float y, float width, float height) : grid_cell(x, y, width, height)
{
	this->color = PINK;
	destructable = false;
	blocked = false;
	cell_type = map_object::ENTRY;
}

void mine_entry::draw()
{
	//DrawRectangleRec(*this, color);
	DrawTextureEx(textures[map_object::ROCK], { x, y }, 0, 3, WHITE);
	DrawTextureEx(textures[cell_type], { x, y }, 0, 3, WHITE);
}