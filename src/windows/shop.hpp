#pragma once

#include <raylib.h>

#include "window.hpp"
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

	Image background_img = LoadImage("assets/Sklep.png");
	Image gold_img = LoadImage("assets/Zloto-przedmiot.png");
	Texture2D background_texture = LoadTextureFromImage(background_img);
	Texture2D gold_texture = LoadTextureFromImage(gold_img);

public:
	shop(dwarf& player);

	void update();

	void draw();
};
