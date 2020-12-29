#pragma once
#include <iostream>
#include <raylib.h>
#include "button.hpp"

class go_shop_btn : public button
{
public:
	using button::button;

	virtual void action() {

		draw_window = window_type::SHOP;
	}
};

class leave_shop_btn : public button
{
public:
	using button::button;

	virtual void action() {
		draw_window = window_type::TOWN;
	}
};

class go_mine_btn : public button
{
public:
	using button::button;

	virtual void action() {

		draw_window = window_type::MINE;
	}
};

class leave_mine_btn : public button
{
public:
	using button::button;

	virtual void action() {
		draw_window = window_type::TOWN;
	}
};