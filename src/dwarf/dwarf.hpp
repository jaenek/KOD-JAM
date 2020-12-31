﻿#pragma once

enum class direction{UP, LEFT, DOWN, RIGHT};

#include <raylib.h>

#include "spotlight.hpp"
#include "../cells/gold.hpp"
#include "../cells/rock.hpp"
#include "../grid/grid.hpp"
#include "../windows/window.hpp"



class dwarf : public Rectangle
{

friend class shop;
friend class shop_buttons;
friend class equipment_bar;
friend class church_buttons;

private:
	Texture texture;
	grid& _grid; // referencja do klasy grid zawieraj¹cej tablice 2d wskaŸników do obiektów typu grid_cell
	Color _color;
	unsigned int _row = 0;
	unsigned int _col = 0;
	direction _dir = direction::RIGHT;
	unsigned int _gold=20;
	unsigned int _torches=10;
	unsigned int _pickaxe=20;
	unsigned int _food=10;
	unsigned int _hp=10;

	bool pay_and_pray = false; //TODO do zmiany, jak wam nie pasuje

	std::pair<int, int> block_in_front(const grid & cells) const;//returns pointer to the block in front of dwarf

public:
	// natura rzeczy martwych wymaga pewnych, .... tak
	// NIE RUSZAĆ
	spotlight torch_lights{ { -CELL_SIZE * 3, _grid.height/2 + CELL_SIZE*5} };
	//TU JUŻ MOŻNA

	dwarf(grid& main_grid, float width, float height);//sets attributes base values

	void set_start_pos(int row, int col);

	void move_up(Camera2D & camera);
	void move_left(Camera2D& camera);
	void move_down(Camera2D& camera);
	void move_right(Camera2D& camera);

	void use_pickaxe();
	void place_torch();
	void leave_mine(); //interaction with mine_entry
	void exit_mine(Camera2D& camera, bool& quit); //interaction with mine_exit


	void draw();
};