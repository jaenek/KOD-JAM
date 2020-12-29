#include "rock.hpp"

rock::rock(float x, float y, float width, float height, bool destruct) : grid_cell(x, y, width, height)
{
	this->color = BLACK;
	destructable = destruct;
	blocked = true;
	cell_type = map_object::ROCK;
}

void rock::draw()
{
	//DrawRectangleRec(*this, color);
	DrawTextureEx(textures[cell_type], { x, y }, 0, 3, WHITE);
}

void rock::break_wall()
{
	color = WHITE;
	cell_type = map_object::TUNNEL;
	destructable = false;
	blocked = false;
}
