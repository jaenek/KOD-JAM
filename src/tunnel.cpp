#include "tunnel.hpp"

tunnel::tunnel(grid_assets& assets, float x, float y, float width, float height) : grid_cell(assets, x, y, width, height)
{
	this->color = WHITE;
	destructable = false;
	blocked = false;
	cell_type = map_object::TUNNEL;
}

void tunnel::draw()
{
	//DrawRectangleRec(*this, color);
	DrawTexture(assets.textures[cell_type], x, y, WHITE);
}