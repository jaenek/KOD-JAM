#include "button.hpp"

#include <iostream>


void button::action()
{
}

bool button::is_mouse_on()
{
	return CheckCollisionPointRec(mouse_position, *this);
}

void button::update()
{

	if (is_mouse_on()) {

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			//mouse is pressed
			button_color = DARKBROWN;
		else
			//hover
			button_color = BROWN;

		//click event
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {			
			action();
		}

	}
	else {
		//outside button
		button_color = GRAY;
	}
}

void button::draw()
{
	DrawRectangleRec(*this, button_color);


	//justify text in button
	float text_pos_x = x + (width - MeasureText(text, font_size)) / 2;
	float text_pos_y = y + (height - font_size) / 2;
	DrawText(text, text_pos_x, text_pos_y, font_size, text_color);

}
