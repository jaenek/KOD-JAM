#pragma once

#include <raylib.h>

#include "../windows/window.hpp"
#include "../buttons/navigate_buttons.hpp"
#include "dwarf.hpp"


class equipment_bar: Rectangle, window
{
public:

	equipment_bar(dwarf* player) {

		this->player = player;

		//rectangle properties 
		this->width = 600;
		this->height = 125;
		this->x = (window_width- width)/2;
		this->y = window_height - height;

	}

	void update(){
		
		
		gold_amt = TextFormat("%d", player->_gold);
		pickaxe_amt = TextFormat("%d", player->_pickaxe);
		torches_amt = TextFormat("%d", player->_torches);
		food_amt = TextFormat("%d", player->_food);	
	}

	void draw() {

		//main frame 
		DrawRectangleRec(*this, Color{0,0,0,100});

		//picture
		DrawRectangle(x + small_margin, y + small_margin, picture_size, picture_size, GREEN);

	

		//goold, pickaxe, torches, food: items_frames
		DrawRectangle(x + padding + picture_size + big_margin + 0 * item_size + 0 * item_margin, y + padding, item_size, item_size, GOLD);
		DrawRectangle(x + padding + picture_size + big_margin + 1 * item_size + 1 * item_margin, y + padding, item_size, item_size, GRAY);
		DrawRectangleLines(x + padding + picture_size + big_margin + 2 * item_size + 2 * item_margin, y + padding, item_size, item_size, ORANGE);
		DrawRectangle(x + padding + picture_size + big_margin + 3 * item_size + 3 * item_margin, y + padding, item_size, item_size, BLUE);


		//goold, pickaxe, torches, food: items_textures
		DrawTextureEx(torach_texture, { x + padding + picture_size + big_margin + 2 * item_size + 2 * item_margin, y + padding }, 0, 2, WHITE);


		//goold, pickaxe, torches, food: items_text
		DrawText(gold_amt, x + padding + picture_size + big_margin + 0 * item_size + 0 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
		DrawText(pickaxe_amt, x + padding + picture_size + big_margin + 1 * item_size + 1 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
		DrawText(torches_amt, x + padding + picture_size + big_margin + 2 * item_size + 2 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
		DrawText(food_amt, x + padding + picture_size + big_margin + 3 * item_size + 3 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);

		
	}
	

private:

	dwarf* player;

	//equipment_bar set up variables

	float padding = 12.5;
	float small_margin = 12.5;
	float item_margin = 25;
	float big_margin = 25;
	float picture_size = 100;
	float item_size = 40;
	float text_item_offset = item_size - 10;


	//text variables
	const char* gold_amt;
	const char* pickaxe_amt;
	const char* torches_amt;
	const char* food_amt;
	int font_size = 18;
	Color font_color = WHITE;


	//textures
	Image torach_img = LoadImage("assets/Pochodnia.png");
	Texture2D torach_texture = LoadTextureFromImage(torach_img);

	

		


};

