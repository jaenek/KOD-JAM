#pragma once

#include <raylib.h>
#include <map>
#include <string>

#include "../grid/map_object.hpp"

class grid_cell : public Rectangle {
public:
	static std::map<map_object, Texture> textures;
	map_object cell_type;
	Color color = PINK;
	bool blocked = false;// true-dwarf shall not pass
	bool destructable = false;// true-can be destroyed with pickaxe

	grid_cell(float x, float y, float width, float height);

	virtual void draw() = 0;
};