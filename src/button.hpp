#pragma once
#include <raylib.h>

#include <functional>
#include "window.hpp"


extern Vector2 mouse_position;
extern window_type draw_window;

class button : Rectangle
{
private:
	const char* text;
	int font_size;
	Color button_color;
	Color text_color;

public:
	button(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color)
	{

		this->text = text;
		this->font_size = font_size;
		this->button_color = button_color;
		this->text_color = text_color;

		//rect shape
		this->x = pos_x;
		this->y = pos_y;
		this->width = width;
		this->height = height;

	}

	virtual void action();

	bool is_mouse_on();

	void update();

	void draw();
};
