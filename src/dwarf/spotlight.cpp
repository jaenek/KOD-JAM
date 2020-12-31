#include "spotlight.hpp"

spotlight::spotlight(Vector2 off)
{
	offset = off;

	shader = LoadShader(0, TextFormat("resources/spotlight.fs", GLSL_VERSION));

    for (int i = 0; i < MAX_SPOTS; i++)
    {
        spots[i].pos_location = GetShaderLocation(shader, TextFormat("spots[%i].pos\0", i));
    }
	
    current_location = GetShaderLocation(shader, "current\0");
    SetShaderValue(shader, current_location, &current, UNIFORM_INT);

	offset_location = GetShaderLocation(shader, "offset\0");
	SetShaderValue(shader, offset_location, &offset, UNIFORM_VEC2);
}

void spotlight::add(Vector2 v)
{
	if (current < MAX_SPOTS)
	{
		spots[current].pos = { v.x, v.y };
		SetShaderValue(shader, spots[current].pos_location, &spots[current].pos.x, UNIFORM_VEC2);
		current++;
		SetShaderValue(shader, current_location, &current, UNIFORM_INT);
	}
}

void spotlight::reset(Vector2 v)
{
	offset = v;
	SetShaderValue(shader, offset_location, &offset, UNIFORM_VEC2);
	current = 0;
	SetShaderValue(shader, current_location, &current, UNIFORM_INT);
}

void spotlight::update(Vector2 v)
{
	offset.x += v.x;
	offset.y += v.y;
	SetShaderValue(shader, offset_location, &offset, UNIFORM_VEC2);
}