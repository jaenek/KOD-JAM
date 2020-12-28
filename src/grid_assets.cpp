#pragma once
#include "grid_assets.hpp"

grid_assets::grid_assets() {
	std::map<map_object, std::string> assets = {
		{ map_object::TUNNEL, "assets/Podloga.png" },
		{ map_object::ROCK, "assets/Sciana.png" },
		{ map_object::GOLD_ORE, "assets/Zloto.png" },
	};
	
	for (auto const& [key, val] : assets)
		textures[key] = LoadTexture(val.c_str());
}