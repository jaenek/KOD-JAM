#pragma once

#include <raylib.h>
#include <map>
#include <string>

#include "map_object.hpp"

struct grid_assets
{
	grid_assets();
	std::map<map_object, Texture> textures;
};