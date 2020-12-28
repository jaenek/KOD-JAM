#include "gold.hpp"

gold(float x, float y, float width, float height, Color color) : grid_cell(float x, float y, float width, float height, Color color)
{
	destructable = true;
	blocked = true;
	lighted = true;
}

virtual void gold::interact() const
{
	//uszkodŸ kilofa
	//usuñ obiekt z mapy
	
	int gold_mined = rand() % gold_max + gold_min;
	//dodaj golda do ekwipunku
}