#pragma once

#include "grid_cell.hpp"

class mine_entry : public grid_cell
{
public:
	mine_entry(float x, float y, float width, float height);
	virtual void draw() override;
};