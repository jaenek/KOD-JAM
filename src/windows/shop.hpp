#pragma once

#include <raylib.h>

#include "window.hpp"
#include "main_window.hpp"
#include "../buttons/navigate_buttons.hpp"
#include "../buttons/shop_buttons.hpp"
#include "../dwarf/dwarf.hpp"

class shop : window
{
private:
	leave_shop_btn leave_shop;
	shop_buttons buy_food;
	shop_buttons buy_torch;
	shop_buttons upgrade_pickaxe;

	dwarf& player; //referencja do ekwipunku gracza

	const char* gold_amt;
	const char* torches_amt;
	const char* pickaxe_amt;
	const char* food_amt;

	Texture2D background_texture = LoadTexture("assets/Sklep.png");
	Texture2D gold_texture = LoadTexture("assets/Zloto-przedmiot.png");

public:
	shop(dwarf& player);

	void update();

	void draw();
};
