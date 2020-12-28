#include "dwarf.hpp"

dwarf::dwarf(grid& main_grid, float width, float height) : _grid(main_grid)
{
	this->width = width;
	this->height = height;
	this->_color = GREEN;
}

grid_cell & dwarf::block_in_front(const grid& cells) const
{
	switch(_dir)
	{
		case (direction::UP):
			return *_grid.cells[_row - 1][_col];
		case (direction::LEFT):
			return *_grid.cells[_row][_col - 1];
		case (direction::DOWN):
			return *_grid.cells[_row + 1][_col];
		case (direction::RIGHT):
			return *_grid.cells[_row][_col + 1];
	}
}

void dwarf::set_start_pos(int row, int col)
{
	_row = row;
	_col = col;
	x = col * CELL_SIZE + _grid.cells[0][0]->x;
	y = row * CELL_SIZE + _grid.cells[0][0]->y - CELL_SIZE/2;
}

void dwarf::move_up()
{
	if (_dir != direction::UP)
	{
		_dir = direction::UP;
		//obroc graficzke
	}
	else
	{
		if (_row != 0 && _grid.cells[_row - 1][_col]->blocked == false)
		{
			_row--;
			y -= CELL_SIZE;
		}
	}
}

void dwarf::move_left()
{
	if (_dir != direction::LEFT)
	{
		_dir = direction::LEFT;
		//obroc graficzke
	}
	else
	{
		if (_col != 0 && _grid.cells[_row][_col - 1]->blocked == false)
		{
			_col--;
			x -= CELL_SIZE;
		}
	}
}

void dwarf::move_down()
{
	if (_dir != direction::DOWN)
	{
		_dir = direction::DOWN;
		//obroc graficzke
	}
	else
	{
		if (_row != ROWS - 1 && _grid.cells[_row + 1][_col]->blocked == false)
		{
			_row++;
			y += CELL_SIZE;
		}
	}
}

void dwarf::move_right()
{
	if (_dir != direction::RIGHT)
	{
		_dir = direction::RIGHT;
		// obroc graficzke
	}
	else
	{
		if (_col != COLS - 1 && _grid.cells[_row][_col + 1]->blocked == false)
		{
			_col++;
			x += CELL_SIZE;
		}
	}
}

void dwarf::use_pickaxe()
{
	if (!_pickaxe)//kilof zepsuty
	{
		return;
	}

	if (block_in_front(_grid).destructable == true)
	{
		_pickaxe--;
		if (block_in_front(_grid).cell_type == map_object::GOLD_ORE)
		{
			_gold += dynamic_cast<gold *>(&block_in_front(_grid))->dig_gold();
		}
		else
		{
			dynamic_cast<rock *>(&block_in_front(_grid))->break_wall();
		}
	}
}

void dwarf::draw()
{
	DrawRectangleRec(*this, _color);
}