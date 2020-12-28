#pragma once

#include <cstdlib>

#include "grid_cell.hpp"
#include "dwarf.hpp"

class dwarf;

class gold : public grid_cell
{
	friend class dwarf;
private:
	static int min_gold = 1;
	static int max_gold = 5;
public:
	gold(float x, float y, float width, float height, Color color) : grid_cell(float x, float y, float width, float height, Color color);
	virtual void interact() const;
};