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
		return false;//triggeruje jaki� d�wi�k typu z�a odpowied� w familiadzie

	//uszkod� kilofa
	//usu� z mapy

	return true;
}