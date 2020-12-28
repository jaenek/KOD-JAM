#pragma once

#include <raylib.h>
#include "map_object.hpp"
#include "grid_assets.hpp"


class grid_cell : public Rectangle {
public:
	map_object cell_type;
	grid_assets& assets;
	Color color = PINK;
	bool blocked = false;// true-dwarf shall not pass
	bool destructable = false;// true-can be destroyed with pickaxe

	grid_cell(grid_assets& assets, float x, float y, float width, float height) : assets(assets)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	virtual void draw() = 0;
};