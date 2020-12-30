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

	Image image = LoadImage("assets/Sklep.png");   // Loaded in CPU memory (RAM)
	Texture2D texture = LoadTextureFromImage(image);

public:
	shop(dwarf& player):
		leave_shop(25, window_height-25-75, 150, 75, "Back to town", 20, DARKBROWN, LIGHTGRAY, BROWN, WHITE, DARKBROWN, GRAY),
		buy_food(1146, 588, 227, 120, "Buy food", 20, Color{ 130,22,22,255 }, WHITE, Color{ 170,22,22,255 }, WHITE, Color{ 130,22,22,255 }, WHITE, &player),
		buy_torch(1146, 330, 227, 120, "Buy torch", 20, Color{ 130,22,22,255 }, WHITE, Color{ 170,22,22,255 }, WHITE, Color{ 130,22,22,255 }, WHITE, &player),
		upgrade_pickaxe(1146, 66, 227, 120, "Upgrade pickaxe", 20, Color{ 130,22,22,255 }, WHITE, Color{ 170,22,22,255 }, WHITE, Color{ 130,22,22,255 }, WHITE, &player),
		
		player(player){}

	void update()
	{
		leave_shop.update();
		buy_food.update();
		buy_torch.update();
		upgrade_pickaxe.update();

		buy_food.add_food();
		buy_torch.add_torch();
		upgrade_pickaxe.upgrade_pickaxe();
	}

	void draw()
	{	

		//background		
		DrawTextureEx(texture, { 0, 0 }, 0, 6, WHITE);

		//buttons
		leave_shop.draw();
		buy_food.draw();
		buy_torch.draw();
		upgrade_pickaxe.draw();

		const char* text = "SHOP";
		DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
	}
};

