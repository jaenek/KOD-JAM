#include "shop.hpp"

shop::shop(dwarf& player) :
	leave_shop(425, 250, 150, 75, "Back to town", 20, GRAY, LIGHTGRAY, BROWN, GRAY, DARKBROWN, GRAY),
	buy_food(50, 450, 150, 75, "Buy food", 20, GRAY, LIGHTGRAY, BROWN, GRAY, DARKBROWN, GRAY, &player),
	buy_torch(425, 450, 150, 75, "Buy torch", 20, GRAY, LIGHTGRAY, BROWN, GRAY, DARKBROWN, GRAY, &player),
	upgrade_pickaxe(850, 450, 200, 75, "Upgrade pickaxe", 20, GRAY, LIGHTGRAY, BROWN, GRAY, DARKBROWN, GRAY, &player),
	player(player) {}

void shop::update()
{
	leave_shop.update();
	buy_food.update();
	buy_torch.update();
	upgrade_pickaxe.update();

	buy_food.add_food();
	buy_torch.add_torch();
	upgrade_pickaxe.upgrade_pickaxe();
}

void shop::draw()
{
	leave_shop.draw();
	buy_food.draw();
	buy_torch.draw();
	upgrade_pickaxe.draw();

	const char* text = "SHOP";
	DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
}
