#pragma once
#include <raylib.h>

#include <functional>
#include <string>
#include "../windows/window.hpp"


extern Vector2 mouse_position;
extern window_type draw_window;

class button : Rectangle
{
private:
	const char* text;
	int font_size;
	float text_pos_x;
	float text_pos_y;

	const char* image_path;
	Image image;
	Texture2D texture;

	Color button_color;
	Color text_color;
	Color hover_button_color;
	Color hover_text_color;
	Color press_button_color;
	Color press_text_color;
	Color draw_button_color;
	Color draw_text_color;


public:
	bool click_event = false;

public:
	button(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color, Color hover_button_color, Color hover_text_color,
		Color press_button_color, Color press_text_color, float text_x = 0, float text_y = 0, const char* image_path = "")
	{
		//text
		this->text = text;
		this->font_size = font_size;
		this->text_pos_x = text_x;
		this->text_pos_y = text_y;

		//image_path
		this->image_path = image_path;

		//colors
		this->button_color = button_color;
		this->text_color = text_color;
		this->hover_button_color = hover_button_color;
		this->hover_text_color = hover_text_color;
		this->press_button_color = press_button_color;
		this->press_text_color = press_text_color;
		this->draw_button_color = button_color;
		this->draw_text_color = text_color;

		//button shape
		this->x = pos_x;
		this->y = pos_y;
		this->width = width;
		this->height = height;

		justify_text();

		load_texture();
		
	}

	virtual void action();

	void justify_text();

	void load_texture();

	bool is_mouse_on();	

	void update();

	void draw();
};
