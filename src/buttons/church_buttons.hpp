#pragma once

#include <raylib.h>
#include "button.hpp"

#include "../dwarf/dwarf.hpp"


class church_buttons : public button
{
public:

	church_buttons(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color, Color hover_button_color, Color hover_text_color,
		Color press_button_color, Color press_text_color, dwarf* player, float text_x = 0, float text_y = 0, const char* image_path = "") :

		button(pos_x, pos_y, width, height, text, font_size,
			button_color, text_color, hover_button_color, hover_text_color,
			press_button_color, press_text_color, text_x = 0, text_y = 0, image_path = "")
	{
		this->player = player;
	}

	void pray(){
	
		if (click_event) {
			if (player->_gold >= pray_pirce) {

				//TODO:: tu nalezy zaktualiuzowac zmienna odpowiadajaca za sprawdzanie czy pomodlil sie
				player->pay_and_pray = true;
				player->_gold -= pray_pirce;

			}
		}
	}

	



private:

	dwarf* player;
	unsigned int pray_pirce = 1;
	

};

