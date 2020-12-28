#pragma once

#include <array>
#include <memory>
#include <raylib.h>

#include "map_generator.hpp"
#include "rock.hpp"
#include "tunnel.hpp"

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

	void transform(map_generator &m)
	{
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				if (m.map[row][col] == 0)
				{
					cells[row][col] = std::make_unique<tunnel>(
						CELL_SIZE * col + x,
						CELL_SIZE * row + y,
						CELL_SIZE,
						CELL_SIZE
						);
				}
				else
				{
					cells[row][col] = std::make_unique<rock>(
						CELL_SIZE * col + x,
						CELL_SIZE * row + y,
						CELL_SIZE,
						CELL_SIZE,
						true
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