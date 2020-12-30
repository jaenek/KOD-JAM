#include "spotlight.hpp"

spotlight::spotlight(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	shader = LoadShader(0, TextFormat("resources/spotlight.fs", GLSL_VERSION));

    for (int i = 0; i < MAX_SPOTS; i++)
    {
        spots[i].pos_location = GetShaderLocation(shader, TextFormat("spots[%i].pos\0", i));
    }

    current_location = GetShaderLocation(shader, "current\0");
    SetShaderValue(shader, current_location, &current, UNIFORM_INT);
}

void spotlight::add(Vector2 v)
{
	if (current < MAX_SPOTS+1)
	{
		spots[current].pos = v;
		SetShaderValue(shader, spots[current].pos_location, &spots[current].pos.x, UNIFORM_VEC2);
		current++;
		SetShaderValue(shader, current_location, &current, UNIFORM_INT);
	}
}
