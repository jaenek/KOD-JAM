#pragma once

#include "grid_cell.hpp"
#include "dwarf.hpp"

class dwarf;

class rock : public grid_cell
{
	friend class dwarf;
public:
	rock(float x, float y, float width, float height, Color color, bool destruct) : grid_cell(x, y, width, height, color);
	virtual bool interact() const;
};