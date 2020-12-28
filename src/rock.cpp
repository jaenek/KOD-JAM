#include "rock.hpp"

rock::rock(float x, float y, float width, float height, bool destruct) : grid_cell(x, y, width, height)
{
	this->color = BLACK;
	destructable = destruct;
	blocked = true;
	grid_type = map_object::ROCK;
}

void rock::draw()
{
	DrawRectangleRec(*this, color);
}
