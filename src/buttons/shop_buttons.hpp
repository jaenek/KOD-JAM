#pragma once

#include <raylib.h>
#include "button.hpp"

#include "../dwarf/dwarf.hpp"


class shop_buttons: public button
{
public:
	
	shop_buttons(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color, Color hover_button_color, Color hover_text_color,
		Color press_button_color, Color press_text_color, dwarf* player, float text_x = 0, float text_y = 0, const char* image_path = "") :

		button(pos_x, pos_y, width, height, text, font_size,
			button_color, text_color, hover_button_color, hover_text_color,
			press_button_color, press_text_color, text_x = 0, text_y = 0, image_path = "")
	{
		this->player = player;
	}
	
	void add_food();

	void add_torch();

	void upgrade_pickaxe();
	
	

private:

	dwarf* player;

	unsigned int food_pirce = 1;
	unsigned int toarch_price = 3;
	unsigned int pickaxe_upgrade_price = 2;

};

