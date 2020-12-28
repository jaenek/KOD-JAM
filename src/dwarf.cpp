#include "dwarf.hpp"

dwarf::dwarf(float width, float height)
{
	this->width = width;
	this->height = height;
}

void dwarf::set_start_pos(int x, int y)
{
	row = x;
	col = y;
}

void dwarf::move_up(MAP & map)
{
	if (dir != UP)
	{
		dir = UP;
		//obróæ graficzke
	}
	else
	{
		if (row != 0 && map[row - 1][col].blocked == false)
		{
			row--;
			y -= CELL_SIZE;
		}
	}
}

void dwarf::move_left(MAP& map)
{
	if (dir != LEFT)
	{
		dir = LEFT;
		//obróæ graficzke
	}
	else
	{
		if (col != 0 && map[row][col - 1].blocked == false)
		{
			col--;
			x -= CELL_SIZE;
		}
	}
}

void dwarf::move_down(MAP& map)
{
	if (dir != DOWN)
	{
		dir = DOWN;
		//obróæ graficzkê
	}
	else
	{
		if (row != ROWS - 1 && map[row + 1][col].blocked == false)
		{
			row++;
			y += CELL_SIZE;
		}
	}
}

void dwarf::move_right(MAP& map)
{
	if (dir != RIGHT)
	{
		dir = RIGHT;
		// obróæ graficzke
	}
	else
	{
		if (col != COLS - 1 && map[row][col + 1].blocked == false)
		{
			col++;
			x += CELL_SIZE;
		}
	}
}