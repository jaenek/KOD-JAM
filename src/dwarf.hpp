#pragma once

enum class direction{UP=0, LEFT=1, DOWN=2, RIGHT=3};

#include <raylib.h>

#include "grid.hpp"

class dwarf : Rectangle
{
private:
	int row;
	int col;
	direction _dir=RIGHT;
	unsigned int _gold=0;
	unsigned int _torches=20;
	unsigned int _pickaxe=20;
	unsigned int _food=10;
	unsigned int _hp=10;
	//unsigned int _sanity; optional
public:
	dwarf(float width, float height);//sets attributes base values

	void set_start_pos(int x, int y);

	void move_up(MAP& map);
	void move_left(MAP& map);
	void move_down(MAP& map);
	void move_right(MAP& map);

};