#include "shop.hpp"

shop::shop(dwarf& player) :
	leave_shop(25, window_height - 25 - 75, 150, 75, "Back to town", 20, DARKBROWN, LIGHTGRAY, BROWN, WHITE, DARKBROWN, GRAY),
	buy_food(1146, 588, 227, 120, "Buy food", 25, Color{ 130,22,22,255 }, WHITE, Color{ 170,22,22,255 }, WHITE, Color{ 130,22,22,255 }, WHITE, & player),
	buy_torch(1146, 330, 227, 120, "Buy torch", 20, Color{ 130,22,22,255 }, WHITE, Color{ 170,22,22,255 }, WHITE, Color{ 130,22,22,255 }, WHITE, & player),
	upgrade_pickaxe(1146, 66, 227, 120, "Upgrade pickaxe", 20, Color{ 130,22,22,255 }, WHITE, Color{ 170,22,22,255 }, WHITE, Color{ 130,22,22,255 }, WHITE, & player),
	player(player) {}

void shop::update()
{
	//check if hover
	leave_shop.update();
	buy_food.update();
	buy_torch.update();
	upgrade_pickaxe.update();

	//check if clicked and do action
	buy_food.add_food();
	buy_torch.add_torch();
	upgrade_pickaxe.upgrade_pickaxe();


	//update equipment lables
	gold_amt = TextFormat("Gold: %d", player._gold);
	pickaxe_amt = TextFormat("%d", player._pickaxe);
	torches_amt = TextFormat("%d", player._torches);
	food_amt = TextFormat("%d", player._food);
}

void shop::draw()
{
	//background texture	
	DrawTextureEx(background_texture, { 0, 0 }, 0, 6, WHITE);

	//buttons
	leave_shop.draw();
	buy_food.draw();
	buy_torch.draw();
	upgrade_pickaxe.draw();

	//equipment lables
	DrawText(gold_amt, 25, 25, 30, WHITE);
	DrawText(pickaxe_amt, 1000, 175, 40, WHITE);
	DrawText(torches_amt, 1000, 475, 40, WHITE);
	DrawText(food_amt, 1000, 700, 40, WHITE);

	//gold texture
	DrawTextureEx(gold_texture, { 25 + (float)MeasureText(gold_amt, 30) + 10, 19 }, 0, 4, WHITE);
	
	const char* text = "SHOP";
	DrawText(text, (window_width - MeasureText(text, 30)) / 2, 50, 30, DARKGRAY);
}
