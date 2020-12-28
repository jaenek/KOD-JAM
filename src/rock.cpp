#include "grid_cells.hpp"

rock::rock(float x, float y, float width, float height, Color color, bool destruct) : grid_cell(x, y, width, height, color)
{
	destructable = destruct;
	lighted = false;
	blocked = true;
}

bool rock::interact() const
{
	if (!destructable)
		return false;//triggeruje jakiœ dŸwiêk typu z³a odpowiedŸ w familiadzie

	//uszkodŸ kilofa
	//usuñ z mapy

	return true;
}