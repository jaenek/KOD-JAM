#include "grid.hpp"

grid::grid(int window_width)
{
	width = COLS * CELL_SIZE;
	height = ROWS * CELL_SIZE;
	x = (window_width - width) / 2;
	y = 0;
}

void grid::transform(map_generator&m)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
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
