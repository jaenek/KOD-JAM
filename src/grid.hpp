#include <array>
#include <memory>
#include <raylib.h>

#include "grid_cell.hpp"

class grid : Rectangle {
public:

	grid(int window_width, float margin_y) {
		width = columns * cell_size;
		height = rows * cell_size;
		x = (window_width - width) / 2;
		y = margin_y;

		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				cells[row][col] = std::make_unique<grid_cell>(
					cell_size * col + x,
					cell_size * row + y,
					cell_size,
					cell_size,
					RAYWHITE
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
	static const int columns = 50;
	static const int rows = 30;
	std::array<std::array<std::unique_ptr<grid_cell>, columns>, rows> cells;
	const float cell_size = 10;
};

