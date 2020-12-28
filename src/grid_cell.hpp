#pragma once

#include <raylib.h>

enum class map_object { TUNNEL, ROCK, BORDER, GOLD_ORE, ENTRY, EXIT };

class grid_cell : public Rectangle {
public:
	map_object grid_type;
	Color color = PINK;
	bool blocked = false;// true-dwarf shall not pass
	bool destructable = false;// true-can be destroyed with pickaxe

	grid_cell(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	virtual void draw() = 0;
};