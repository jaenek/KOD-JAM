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
		this->width = 220;
		this->height = 80;
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

		//goold, pickaxe, torches, food: items_textures
		DrawTextureEx(gold_texture,    { x + padding + 0 * item_size + 0 * item_margin, y + padding }, 0, 4, WHITE);
		DrawTextureEx(pickaxe_texture, { x + padding + 1 * item_size + 1 * item_margin, y + padding }, 0, 4, WHITE);
		DrawTextureEx(torch_texture,   { x + padding + 2 * item_size + 2 * item_margin, y + padding }, 0, 4, WHITE);
		DrawTextureEx(food_texture,    { x + padding + 3 * item_size + 3 * item_margin, y + padding }, 0, 4, WHITE);

		//goold, pickaxe, torches, food: items_text
		DrawText(gold_amt,    x + padding + 0 * item_size + 0 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
		DrawText(pickaxe_amt, x + padding + 1 * item_size + 1 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
		DrawText(torches_amt, x + padding + 2 * item_size + 2 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
		DrawText(food_amt,    x + padding + 3 * item_size + 3 * item_margin + text_item_offset, y + padding + text_item_offset, font_size, font_color);
	}


private:

	dwarf* player;

	//equipment_bar set up variables
	float padding = 10;
	float small_margin = 12.5;
	float item_margin = 25;
	float item_size = 40;
	float text_item_offset = item_size - 10;


	//text variables
	const char* gold_amt;
	const char* pickaxe_amt;
	const char* torches_amt;
	const char* food_amt;
	int font_size = 20;
	Color font_color = WHITE;


	//textures
	Texture2D gold_texture = LoadTexture("assets/Zloto-przedmiot.png");
	Texture2D torch_texture = LoadTexture("assets/Pochodnia-przedmiot.png");
	Texture2D pickaxe_texture = LoadTexture("assets/Kilof-przedmiot.png");
	Texture2D food_texture = LoadTexture("assets/Jedzenie-przedmiot.png");

};
