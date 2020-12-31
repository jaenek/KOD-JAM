#include "town.hpp"

town::town(): 
	go_shop(1125, 300, 300, 525, "Shop", 25, BLANK, WHITE, Color{255, 255, 255, 0}, YELLOW, Color{ 255, 255, 255, 0}, ORANGE, 0, 80),
	go_mine((window_width-200) / 2+15, 350, 200, 200, "Mine", 25, BLANK, WHITE, Color{255, 255, 255, 0}, YELLOW, Color{ 255, 255, 255, 0}, ORANGE, 0, 0),
	go_church(10, 425, 350, 450, "Church", 25, BLANK, WHITE, Color{ 255, 255, 255, 0 }, YELLOW, Color{ 255, 255, 255, 0 }, ORANGE, 95, 50)
	{	}

void town::update()
{
	go_shop.update();
	go_mine.update();
	go_church.update();
}

void town::draw()
{
	//background
	DrawTextureEx(texture, { 0, 0 }, 0, 6, WHITE);

	//buttons
	go_shop.draw();
	go_mine.draw();
	go_church.draw();

	//text
	const char* text = "TOWN";
	DrawText(text, (window_width - MeasureText(text, 40)) / 2, 50, 30, YELLOW);


}
