#include "button.hpp"

void button::action()
{
}

void button::justify_text()
{
	//0 - center this direction
	if (text_pos_x == 0 && text_pos_y == 0) {
		//center text in button
		text_pos_x = x + (width - MeasureText(text, font_size)) / 2;
		text_pos_y = y + (height - font_size) / 2;
	}
	else if (text_pos_x == 0) {
		//center text vertical
		text_pos_x = x + (width - MeasureText(text, font_size)) / 2;
		text_pos_y = y + text_pos_y;
	}
	else if (text_pos_y == 0) {
		//center text horizontal
		text_pos_x = x + text_pos_x;
		text_pos_y = y + (height - font_size) / 2;
	}
	
}

void button::load_texture()
{
	if (image_path != "") {

		image = LoadImage(image_path);   // Loaded in CPU memory (RAM)
		texture = LoadTextureFromImage(image);
	}
}

bool button::is_mouse_on()
{
	return CheckCollisionPointRec(mouse_position, *this);
}

void button::update()
{

	if (is_mouse_on()) {

		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			//mouse is pressed
			draw_text_color = press_text_color;
			draw_button_color = press_button_color;
		}
		else {
			//hover
			draw_text_color = hover_text_color;
			draw_button_color = hover_button_color;
		}			

		//click event
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
			action();
		}

	}
	else {
		//outside button
		draw_text_color = text_color;
		draw_button_color = button_color;
	}
}

void button::draw()
{
	DrawRectangleRec(*this, draw_button_color);

	DrawTextureEx(texture, { x, y }, 0, 1, WHITE);

	DrawText(text, text_pos_x, text_pos_y, font_size, draw_text_color);
}
