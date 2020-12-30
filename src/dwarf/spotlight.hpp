#pragma once

#include <raylib.h>
#include <array>

const int MAX_SPOTS = 9;

struct spot {
	Vector2 pos;

	unsigned int pos_location;
};

class spotlight : public Rectangle
{
	unsigned int current = 0;
	unsigned int current_location;

	std::array<spot, MAX_SPOTS> spots;

public:
    Shader shader{};

	spotlight(float x, float y, float width, float height);

	void add(Vector2 v);
};
