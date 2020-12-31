#pragma once

#include <raylib.h>
#include <array>

#include "../windows/window.hpp"

const int MAX_SPOTS = 9;

struct spot {
	Vector2 pos;

	unsigned int pos_location;
};

class spotlight : window
{
	unsigned int current = 0;
	unsigned int current_location;

	Vector2 offset{};
	unsigned int offset_location;

	std::array<spot, MAX_SPOTS> spots;

public:
    Shader shader{};

	spotlight(Vector2 off);

	void add(Vector2 v);

	void reset(Vector2 v);

	void update(Vector2 v);
};
