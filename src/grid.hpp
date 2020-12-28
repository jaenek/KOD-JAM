#pragma once

#include <array>
#include <memory>
#include <raylib.h>

#include "map_generator.hpp"
#include "grid_assets.hpp"
#include "rock.hpp"
#include "tunnel.hpp"
#include "gold.hpp"

typedef std::array<std::array<std::unique_ptr<grid_cell>, COLS>, ROWS> MAP;

const float CELL_SIZE = 60;

class dwarf;

class grid : Rectangle {
	friend class dwarf;
public:

	grid(int window_width, float margin_y) {
		width = COLS * CELL_SIZE;
		height = ROWS * CELL_SIZE;
		x = (window_width - width) / 2;
		y = margin_y;
	}

	void transform(map_generator &m, grid_assets& assets)
	{
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				if (m.map[row][col] == map_object::BORDER)
				{
					cells[row][col] = std::make_unique<rock>(
						assets,
						CELL_SIZE * col + x,
						CELL_SIZE * row + y,
						CELL_SIZE,
						CELL_SIZE,
						false
						);
				}
				else if (m.map[row][col] == map_object::TUNNEL)
				{
					cells[row][col] = std::make_unique<tunnel>(
						assets,
						CELL_SIZE * col + x,
						CELL_SIZE * row + y,
						CELL_SIZE,
						CELL_SIZE
						);
				}
				else if (m.map[row][col] == map_object::ROCK)
				{
					cells[row][col] = std::make_unique<rock>(
						assets,
						CELL_SIZE * col + x,
						CELL_SIZE * row + y,
						CELL_SIZE,
						CELL_SIZE,
						true
						);
				}
				else if (m.map[row][col] == map_object::GOLD_ORE)
				{
					cells[row][col] = std::make_unique<gold>(
						assets,
						CELL_SIZE * col + x,
						CELL_SIZE * row + y,
						CELL_SIZE,
						CELL_SIZE
						);
				}
			}
		}
	}

	void draw()
	{
		for (auto& row : cells) {
			for (auto& cell : row) {
				cell->draw();
			}
		}
	}

private:
	MAP cells;
};