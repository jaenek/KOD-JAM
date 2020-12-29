#pragma once

enum class direction{UP, LEFT, DOWN, RIGHT};

#include <raylib.h>

#include "../cells/gold.hpp"
#include "../cells/rock.hpp"
#include "../grid/grid.hpp"

class dwarf : public Rectangle
{

private:
	Texture texture;
	grid& _grid; // referencja do klasy grid zawierającej tablice 2d wskaźników do obiektów typu grid_cell
	Color _color;
	unsigned int _row = 0;
	unsigned int _col = 0;
	direction _dir = direction::RIGHT;
	unsigned int _gold=0;
	unsigned int _torches=10;
	unsigned int _pickaxe=20;
	unsigned int _food=10;
	unsigned int _hp=10;

	grid_cell* block_in_front(const grid & cells) const;//returns pointer to the block in front of dwarf

public:
	dwarf(grid& main_grid, float width, float height);//sets attributes base values

	void set_start_pos(int row, int col);

	void move_up(Camera2D & camera);
	void move_left(Camera2D& camera);
	void move_down(Camera2D& camera);
	void move_right(Camera2D& camera);

	void use_pickaxe();
	void place_torch();

	void draw();
};