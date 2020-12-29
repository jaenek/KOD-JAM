#include "grid_cell.hpp"

grid_cell::grid_cell(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

std::map<map_object, Texture> grid_cell::textures{};
