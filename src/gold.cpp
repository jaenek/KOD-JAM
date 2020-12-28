#include "gold.hpp"

gold::gold(grid_assets& assets, float x, float y, float width, float height) : grid_cell(assets, x, y, width, height)
{
	color = YELLOW;
	destructable = true;
	blocked = true;
	cell_type = map_object::GOLD_ORE;
}

void gold::draw()
{
	//DrawRectangleRec(*this, color);
	DrawTextureEx(assets.textures[cell_type], { x, y }, 0, 3, WHITE);
}

int gold::dig_gold()
{
	color = WHITE;
	cell_type = map_object::TUNNEL;
	destructable = false;
	blocked = false;
	
	return rand() % max_gold + min_gold;
}