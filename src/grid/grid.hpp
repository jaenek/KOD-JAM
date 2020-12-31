#pragma once

#include <vector>
#include <memory>
#include <raylib.h>

#include "map_generator.hpp"
#include "../cells/rock.hpp"
#include "../cells/tunnel.hpp"
#include "../cells/gold.hpp"
#include "../cells/border.hpp"
#include "../cells/entry.hpp"
#include "../cells/exit.hpp"

typedef std::vector<std::vector<std::unique_ptr<grid_cell>>>MAP;

const float CELL_SIZE = 60;

class dwarf;

class grid : public Rectangle {
	friend class dwarf;
public:
	grid();

	void transform(map_generator &m);

	void draw();

private:
	MAP cells;
};