#include "church.hpp"

church::church(dwarf& player):
	leave_church(430, 585, 200, 75, "Back to town", 20, GRAY, WHITE, BROWN, WHITE, DARKBROWN, WHITE, 0, 0),
	pay_and_pray(775, 685, 200, 75, "Pay and pray", 20, GRAY, WHITE, BROWN, WHITE, DARKBROWN, WHITE, &player, 0, 0),
	player(player)
	{}

void church::update()
{

	leave_church.update();
	pay_and_pray.update();

	pay_and_pray.pray();
	
}

void church::draw()
{
	//background
	DrawTextureEx(texture, { 0, 0 }, 0, 6, WHITE);

	//buttons
	leave_church.draw();
	pay_and_pray.draw();
	

	//text
	const char* text = "CHURCH";
	DrawText(text, (window_width - MeasureText(text, 40)) / 2, 50, 30, DARKBROWN);


}
