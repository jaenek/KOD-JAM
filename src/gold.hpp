#pragma once

#include <cstdlib>

#include "grid_cell.hpp"

class gold : public grid_cell
{
private:
	static const int min_gold = 1;
	static const int max_gold = 5;
public:
	gold(grid_assets& assets, float x, float y, float width, float height);
	virtual void draw() override;
	int dig_gold();
};