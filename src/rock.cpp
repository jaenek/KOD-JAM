#include "rock.hpp"

rock::rock(grid_assets& assets, float x, float y, float width, float height, bool destruct) : grid_cell(assets, x, y, width, height)
{
	this->color = BLACK;
	destructable = destruct;
	blocked = true;
	cell_type = map_object::ROCK;
}

void rock::draw()
{
	//DrawRectangleRec(*this, color);
	DrawTexture(assets.textures[cell_type], x, y, WHITE);
}

void rock::break_wall()
{
	color = WHITE;
	destructable = false;
	blocked = false;
}
