#pragma once

#include <array>
#include <memory>
#include <raylib.h>

#include "map_generator.hpp"
#include "rock.hpp"
#include "tunnel.hpp"
#include "gold.hpp"

typedef std::array<std::array<std::unique_ptr<grid_cell>, COLS>, ROWS> MAP;

const float CELL_SIZE = 60;

class dwarf;

class grid : Rectangle {
	friend class dwarf;
public:
	grid(int window_width);

	void transform(map_generator &m);

	void draw();

private:
	MAP cells;
};