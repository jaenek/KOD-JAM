#include "tunnel.hpp"

tunnel::tunnel(float x, float y, float width, float height) : grid_cell(x, y, width, height)
{
	this->color = WHITE;
	destructable = false;
	blocked = false;
	cell_type = map_object::TUNNEL;
}

void tunnel::draw()
{
	//DrawRectangleRec(*this, color);
	DrawTextureEx(textures[cell_type], { x, y }, 0, 3, WHITE);
}