#pragma once

#include "grid_cell.hpp"

class mine_exit : public grid_cell
{
public:
	mine_exit(float x, float y, float width, float height);
	virtual void draw() override;
};