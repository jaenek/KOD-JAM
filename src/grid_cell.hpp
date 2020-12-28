#pragma once

#include <raylib.h>

enum class map_object { tunnel = 0, rock = 1, border = 2, gold = 3, entry = 4, exit = 5 };

class grid_cell : Rectangle {
public:
	bool blocked;// true-dwarf shall not pass
	bool destructable;// true-can be destroyed with pickaxe

	grid_cell(float x, float y, float width, float height, Color color)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->color = color;
	}

	virtual void draw()
	{
		DrawRectangleRec(*this, color);
	}

	virtual void interact() = 0;

private:
	Color color;
	map_object grid_type;
	bool lighted;// true-in range of torch
};