#include "gold.hpp"

gold::gold(float x, float y, float width, float height, Color color) : grid_cell(x, y, width, height)
{
	destructable = true;
	blocked = true;
	grid_type = map_object::GOLD_ORE;
}