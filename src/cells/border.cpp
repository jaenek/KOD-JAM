#include "border.hpp"

border::border(float x, float y, float width, float height) : grid_cell(x, y, width, height)
{
	this->color = PINK;
	destructable = false;
	blocked = true;
	cell_type = map_object::BORDER;
}

void border::draw()
{
	//DrawTextureEx(textures[cell_type], { x, y }, 0, 3, WHITE);
	DrawRectangleRec(*this, color);

}