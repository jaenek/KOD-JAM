#pragma once
#include <iostream>
#include <raylib.h>
#include "button.hpp"


class go_shop_btn : public button
{
public:

	go_shop_btn(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color) :
		button(pos_x, pos_y, width, height, text, font_size, button_color, text_color)
	{}


	virtual void action() {

		draw_window = window_type::SHOP;
	}
};

class leave_shop_btn : public button
{
public:

	leave_shop_btn(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color) :
		button(pos_x, pos_y, width, height, text, font_size, button_color, text_color)
	{}


	virtual void action() {
		draw_window = window_type::TOWN;
	}
};

class go_mine_btn : public button
{
public:

	go_mine_btn(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color) :
		button(pos_x, pos_y, width, height, text, font_size, button_color, text_color)
	{}


	virtual void action() {

		draw_window = window_type::MINE;
	}
};

class leave_mine_btn : public button
{
public:

	leave_mine_btn(float pos_x, float pos_y, float width, float height, const char* text, int font_size,
		Color button_color, Color text_color) :
		button(pos_x, pos_y, width, height, text, font_size, button_color, text_color)
	{}


	virtual void action() {
		draw_window = window_type::TOWN;
	}
};