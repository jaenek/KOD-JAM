#include "dwarf.hpp"

extern window_type draw_window;

dwarf::dwarf(grid& main_grid, float width, float height) : _grid(main_grid)
{
	this->texture = LoadTexture("assets/Ludzik.png");
	this->width = width;
	this->height = height;
	this->_color = GREEN;
}

std::pair<int, int> dwarf::block_in_front(const grid& cells) const
{
	switch(_dir)
	{
		case (direction::UP):
			return std::make_pair(_row - 1, _col);
		case (direction::LEFT):
			return std::make_pair(_row, _col - 1);
		case (direction::DOWN):
			return std::make_pair(_row + 1,_col);
		case (direction::RIGHT):
			return std::make_pair(_row, _col + 1);
		default:
			return std::make_pair(0,0);
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
		if (_grid.cells[_row - 1][_col]->blocked == false)
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
		if (_grid.cells[_row][_col - 1]->blocked == false)
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
		if (_grid.cells[_row + 1][_col]->blocked == false)
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
		if (_grid.cells[_row][_col + 1]->blocked == false)
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

	auto coords = block_in_front(_grid);
	auto block = _grid.cells[coords.first][coords.second].get();

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
		_grid.cells[coords.first][coords.second].reset(new tunnel(block->x, block->y, block->width, block->height));
	}
}

void dwarf::place_torch()
{
	if (auto block = dynamic_cast<tunnel*>(_grid.cells[_row][_col].get()); block)
	{
		if (!_torches && block->has_torch == false)
		{
			//dzwieka dzwieka
			return;
		}
		_torches--;
		block->has_torch = true;
		torch_lights.add({block->x+30, block->y+20});
	}
}

void dwarf::draw()
{
	//DrawRectangleRec(*this, _color);
	switch (_dir) {
	case direction::UP:    DrawTextureTiled(texture, { 0, 108, 21, 36 }, { x+5, y, 50, 90 }, {}, 0, 2.5, WHITE); break;
	case direction::DOWN:  DrawTextureTiled(texture, { 0, 72,  21, 36 }, { x+5, y, 50, 90 }, {}, 0, 2.5, WHITE); break;
	case direction::LEFT:  DrawTextureTiled(texture, { 0, 36,  21, 36 }, { x+5, y, 50, 90 }, {}, 0, 2.5, WHITE); break;
	case direction::RIGHT: DrawTextureTiled(texture, { 0, 0,   21, 36 }, { x+5, y, 50, 90 }, {}, 0, 2.5, WHITE); break;
	}
}

void dwarf::leave_mine()
{
	if (_grid.cells[_row][_col].get()->cell_type == map_object::ENTRY)
	{
		draw_window = window_type::TOWN;
		set_start_pos(map_generator::ROWS / 2, map_generator::COLS / 2);
	}
}

void dwarf::exit_mine(Camera2D& camera)
{
	if (_grid.cells[_row][_col].get()->cell_type == map_object::EXIT)
	{
		map_generator::ROWS += 30;
		map_generator::COLS += 30;

		map_generator new_map(1001);
		_grid.transform(new_map);

		set_start_pos(map_generator::ROWS / 2, map_generator::COLS / 2);
		camera.target = {x, y};
	}
}