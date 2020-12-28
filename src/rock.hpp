#pragma once

#include "grid_cell.hpp"

class rock : public grid_cell
{
public:
	rock(grid_assets& assets, float x, float y, float width, float height, bool destruct);
	virtual void draw() override;
	void break_wall();
};