#pragma once

#include "grid_cell.hpp"

class border : public grid_cell
{
public:
	border(float x, float y, float width, float height);
	virtual void draw() override;
};