#include <array>
#include <memory>
#include <raylib.h>

#include "grid_cell.hpp"
#include "map_generator.hpp"

typedef std::array<std::array<std::unique_ptr<grid_cell>, COLS>, ROWS> MAP;

const float CELL_SIZE = 60;

class grid : Rectangle {
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
				cells[row][col] = std::make_unique<grid_cell>(
					CELL_SIZE * col + x,
					CELL_SIZE * row + y,
					CELL_SIZE,
					CELL_SIZE,
					(m.map[row][col]) ? BLACK : RAYWHITE
				);
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