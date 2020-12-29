#include "dwarf.hpp"

dwarf::dwarf(grid& main_grid, float width, float height) : _grid(main_grid)
{
	this->texture = LoadTexture("assets/Ludzik.png");
	this->width = width;
	this->height = height;
	this->_color = GREEN;
}

grid_cell* dwarf::block_in_front(const grid& cells) const
{
	switch(_dir)
	{
		case (direction::UP):
			return _grid.cells[_row - 1][_col].get();
		case (direction::LEFT):
			return _grid.cells[_row][_col - 1].get();
		case (direction::DOWN):
			return _grid.cells[_row + 1][_col].get();
		case (direction::RIGHT):
			return _grid.cells[_row][_col + 1].get();
		default:
			return nullptr;
	}
}

void dwarf::set_start_pos(int row, int col)
{
	_row = row;
	_col = col;
	x = col * CELL_SIZE + _grid.cells[0][0]->x;
	y = row * CELL_SIZE + _grid.cells[0][0]->y - CELL_SIZE/2;
}

void dwarf::move_up(Camera2D & camera)
{
	if (_dir != direction::UP)
	{
		_dir = direction::UP;
	}
	else
	{
		if (_row != 0 && _grid.cells[_row - 1][_col]->blocked == false)
		{
			_row--;
			y -= CELL_SIZE;
			camera.target = { x, y };
		}
	}
}

void dwarf::move_left(Camera2D& camera)
{
	if (_dir != direction::LEFT)
	{
		_dir = direction::LEFT;
	}
	else
	{
		if (_col != 0 && _grid.cells[_row][_col - 1]->blocked == false)
		{
			_col--;
			x -= CELL_SIZE;
			camera.target = { x, y };
		}
	}
}

void dwarf::move_down(Camera2D& camera)
{
	if (_dir != direction::DOWN)
	{
		_dir = direction::DOWN;
	}
	else
	{
		if (_row != ROWS - 1 && _grid.cells[_row + 1][_col]->blocked == false)
		{
			_row++;
			y += CELL_SIZE;
			camera.target = { x, y };
		}
	}
}

void dwarf::move_right(Camera2D& camera)
{
	if (_dir != direction::RIGHT)
	{
		_dir = direction::RIGHT;
	}
	else
	{
		if (_col != COLS - 1 && _grid.cells[_row][_col + 1]->blocked == false)
		{
			_col++;
			x += CELL_SIZE;
			camera.target = { x, y };
		}
	}
}

void dwarf::use_pickaxe()
{
	if (!_pickaxe)//kilof zepsuty
	{
		return;
	}

	grid_cell* block = block_in_front(_grid);

	if (block->destructable == true)
	{
		_pickaxe--;
		if (block->cell_type == map_object::GOLD_ORE)
		{
			_gold += dynamic_cast<gold *>(block)->dig_gold();
		}
		else
		{
			dynamic_cast<rock *>(block)->break_wall();
		}
	}
}

void dwarf::draw()
{
	//DrawRectangleRec(*this, _color);
	switch (_dir) {
	case direction::UP: DrawTextureTiled(texture, { 67, 0, 24, 45 }, { x, y, 60, 113 }, {}, 0, 2.5, WHITE); break;
	case direction::DOWN: DrawTextureTiled(texture, { 37, 0, 24, 45 }, { x, y, 60, 113 }, {}, 0, 2.5, WHITE); break;
	case direction::LEFT: DrawTextureTiled(texture, { 0,0,24,45 }, { x, y, 60, 113 }, {}, 0, 2.5, WHITE); break;
	case direction::RIGHT: DrawTextureTiled(texture, { 0,0,24,45 }, { x, y, 60, 113 }, {}, 0, 2.5, WHITE); break;
	}
}