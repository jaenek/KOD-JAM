#pragma once

enum class direction{UP=0, LEFT=1, DOWN=2, RIGHT=3};

#include <raylib.h>

#include "grid.hpp"

class dwarf : public Rectangle
{

private:
	grid& _grid;
	Color _color;
	unsigned int _row = 0;
	unsigned int _col = 0;
	direction _dir = direction::RIGHT;
	unsigned int _gold=0;
	unsigned int _torches=20;
	unsigned int _pickaxe=20;
	unsigned int _food=10;
	unsigned int _hp=10;
	
	grid_cell & block_in_front() const;//returns pointer to the block in front of dwarf

public:
	dwarf(grid& main_grid, float width, float height);//sets attributes base values

	void set_start_pos(int row, int col);

	void move_up();
	void move_left();
	void move_down();
	void move_right();

	bool use_pickaxe();

	void draw();
};