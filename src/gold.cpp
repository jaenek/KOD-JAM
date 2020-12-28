#include "gold.hpp"

gold::gold(float x, float y, float width, float height) : grid_cell(x, y, width, height)
{
	color = YELLOW;
	destructable = true;
	blocked = true;
	cell_type = map_object::GOLD_ORE;
}

void gold::draw()
{
	DrawRectangleRec(*this, color);
}

int gold::dig_gold()
{
	color = WHITE;
	destructable = false;
	blocked = false;
	cell_type = map_object::TUNNEL;

	return rand() % max_gold + min_gold;
}