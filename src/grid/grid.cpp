#include "grid.hpp"

grid::grid()
{
	x = 0;
	y = 0;
	width = map_generator::COLS * CELL_SIZE;
	height = map_generator::ROWS * CELL_SIZE;
}

void grid::transform(map_generator&m)
{
	width = map_generator::COLS * CELL_SIZE;
	height = map_generator::ROWS * CELL_SIZE;

	cells.resize(map_generator::ROWS);
	for (int i = 0; i < map_generator::ROWS; i++)
	{
		cells[i].resize(map_generator::COLS);
	}
	for (int row = 0; row < map_generator::ROWS; row++)
	{
		for (int col = 0; col < map_generator::COLS; col++)
		{
			if (m.map[row][col] == map_object::BORDER)
			{
				cells[row][col] = std::make_unique<border>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE
					);
			}
			else if (m.map[row][col] == map_object::TUNNEL)
			{
				cells[row][col] = std::make_unique<tunnel>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE
					);
			}
			else if (m.map[row][col] == map_object::ROCK)
			{
				cells[row][col] = std::make_unique<rock>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE
					);
			}
			else if (m.map[row][col] == map_object::GOLD_ORE)
			{
				cells[row][col] = std::make_unique<gold>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE
					);
			}
			else if (m.map[row][col] == map_object::ENTRY)
			{
				cells[row][col] = std::make_unique<mine_entry>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE
					);
			}
			else if (m.map[row][col] == map_object::EXIT)
			{
				cells[row][col] = std::make_unique<mine_exit>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE
					);
			}
		}
	}
}

void grid::draw()
{
	for (auto& row : cells) {
		for (auto& cell : row) {
			cell->draw();
		}
	}
}
