#pragma once

#include <raylib.h>
#include "button.hpp"



class go_shop_btn : public button
{
public:
	using button::button;

	virtual void action()
	{
		draw_window = window_type::SHOP;
	}
};

class leave_shop_btn : public button
{
public:
	using button::button;

	virtual void action()
	{
		draw_window = window_type::TOWN;
	}
};

class go_mine_btn : public button
{
public:
	using button::button;

	virtual void action()
	{
		draw_window = window_type::MINE;
	}
};

class leave_mine_btn : public button
{
public:
	using button::button;

	virtual void action()
	{
		draw_window = window_type::TOWN;
	}
};

class go_church_btn : public button
{
public:
	using button::button;

	virtual void action()
	{
		draw_window = window_type::CHURCH;
	}
};

class leave_church_btn : public button
{
public:
	using button::button;

	bool first_visit = true;

	virtual void action()
	{
		first_visit = false;
		draw_window = window_type::TOWN;
	}
};